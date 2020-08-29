//
// Created by Vigo Wong on 11/8/20.
//

#include "usr/user.hpp"


//#include "src/user/admin.h"
//#include "src/user/normal_user.h"

#include "glog/logging.h"

namespace chatroom {

User::User(std::string &name, int id, std::string &password) : name_(name), id_(id),
                                                               password_(password) {
    this->connect_to_server();
}

auto User::connect_to_server() -> void {
    LOG(ERROR) << "Welcome to the chatroom client";

    this->fd_ = socket(AF_INET, SOCK_STREAM, 0);
    this->reuse_ = 0;
    setsockopt(this->fd_, SOL_SOCKET, SO_REUSEADDR, &this->reuse_, sizeof(this->reuse_));

    this->serv_addr_ = sockaddr_in();
    memset(&this->serv_addr_, 0, sizeof(this->serv_addr_));
    this->serv_addr_.sin_family = AF_INET;
    this->serv_addr_.sin_port = htons(PORT);
    this->serv_addr_.sin_addr.s_addr = inet_addr(IP);

    // connect
    this->saddr_len_ = sizeof(this->serv_addr_);
    if (connect(this->fd_, (struct sockaddr *) &this->serv_addr_, this->saddr_len_) < 0) {
        perror("Connected error.");
        exit(1);
    }
    LOG(ERROR) << "Connection Initialization succeed.";
}

auto User::verify_admin(const std::string &code) -> void {
    this->sendMessage(fmt::format("{} {}", VERIFY_PREFIX, code));
    // TODO: wait until the status of id changed or not
}

auto User::registration() -> void {
    int type;
    std::string verification_code;
    LOG(ERROR) << "Client: Registration";
    std::cout << "Please input your type(1 for admin, 2 for normal members):" << std::endl;
    std::cin >> type;
    if (type == 1) {
        std::cout << "Please input the verification code:" << std::endl;
        std::cin >> verification_code;
        this->sendMessage(fmt::format("{} {}", VERIFY_PREFIX, verification_code));

    } else if (type != 2) {
        LOG(FATAL) << "Incorrect code. Exiting...";
        // TODO: let the user try again, if wrong again, then exit
        exit(1);
    }
    int id;
    std::string name;
    std::string password;
    std::string password2;
    try {
        std::cout << "Please input your id:" << std::endl;
        std::cin >> id;
        std::cout << "Please input your name:" << std::endl;
        std::cin >> name;
        std::cout << "Please input your password:" << std::endl;
        std::cin >> password;
        std::cout << "Please repeat your password:" << std::endl;
        std::cin >> password2;

        // TODO: let the usr try again
        if (password == password2) {
            this->name_ = name;
            this->id_ = id;
            this->password_ = password;
            auto fmt_msg = fmt::format("{} {} {} {}", REGISTER_PREFIX, id, name, password);
            sendMessage(fmt_msg);
        } else {
            LOG(FATAL) << "Incorrect password";
        }
    } catch (...) {
        LOG(FATAL) << "Incorrect input. Exiting...";
        exit(1);
    }
}

auto User::sendMessage(const std::string &msg) -> void {
    char buf[MESSAGE_LEN];
    memset(buf, 0, MESSAGE_LEN);
    ranges::copy(msg, buf);
    send(this->fd_, buf, MESSAGE_LEN, 0);
}

auto User::join_chatroom() -> void {
    char buf[MESSAGE_LEN];
    auto msg = std::string(CONNECTREQUEST);
    std::copy(msg.begin(), msg.end(), buf);
    buf[msg.size()] = '\0';
    send(this->fd_, buf, strlen(buf), 0);

    // listen to ack
    fd_set rfds;
    int maxfd = 0;
    timeval tv{5, 0};
    int retry_time = 3;

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    maxfd = 0;
    FD_SET(this->fd_, &rfds);
    if (maxfd < this->fd_) {
        maxfd = this->fd_;
    }

    int rtn = select(maxfd + 1, &rfds, nullptr, nullptr, nullptr);

    if (rtn < 0) {
        LOG(ERROR) << "select error, error code=" << rtn;
    } else if (rtn == 0) {
        LOG(ERROR) << "client wait overtime.";
    } else {
        if (FD_ISSET(this->fd_, &rfds)) {
            char recv_buf[MESSAGE_LEN];
            while (retry_time) {
                memset(recv_buf, 0, MESSAGE_LEN);
                int len = recv(this->fd_, recv_buf, MESSAGE_LEN, 0);
                if (len == 0) {
                    std::cout << "Server not exist" << retry_time-- << "try again later。" << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                    continue;
                }
                auto welcome = std::string(recv_buf);
                // TODO: extract the name of chat room here
                if (welcome.starts_with(std::string_view("Server: Welcome to"))) {
                    auto room_name = chatroom::split_string_by_space(welcome)[3];
                    std::cout << "Welcome to " << room_name << std::endl;
                } else {
                    LOG(ERROR) << "Fail to join the chat room, exiting...";
                    exit(0);
                }
                LOG(ERROR) << "Already in the chat room";
                break;
            }
        }
    }

    std::thread listening(&User::listener, this);
    listening.detach();
}

auto User::exit_chatroom() -> void {
    this->sendMessage(fmt::format("{} {}", EXITCHAT, this->id_));
}


auto User::set_connection(const std::string &name) -> void {
    this->name_ = name;
    this->connection_ = true;
    LOG(ERROR) << "You can now speak";
}

auto User::get_usr_name() const -> std::string {
    return this->name_;
}

auto User::set_admin() -> void {
    this->is_admin_ = true;
}

auto User::is_admin() const -> bool {
    return this->is_admin_;
}

auto User::get_usr_id() const -> int {
    return this->id_;
}

auto User::login() -> void {
    auto id = 0;
    std::string password;
    try {
        std::cout << "Please input your id:" << std::endl;
        std::cin >> id;
        std::cout << "Please input your password:" << std::endl;
        std::cin >> password;
        this->sendMessage(fmt::format("{} {} {}", LOGIN_PREFIX, id, password));
    } catch (...) {
        LOG(FATAL) << "Incorrect input";
    }
}

auto User::server_msg_processor(const std::string &msg) -> void {
    if (msg.starts_with("Server: Welcome to")) {
        auto words = split_string_by_space(msg);
        auto name = words[4];
        this->set_connection(name);
    } else if (msg == "Server: The registration id has already existed") {
        // TODO: let the usr retry
        LOG(ERROR) << "Your registration id has already existed, exiting";
        this->exit_chatroom();
    } else if (msg == "Server: Incorrect id or password") {
        // TODO: let the usr retry
        LOG(ERROR) << "Incorrect id or password";
        this->exit_chatroom();
    } else if (msg.starts_with("Server: Welcome, admin")) {
        // TODO: enable admin
        LOG(ERROR) << "You are now an admin of the chat room";
        this->set_admin();
    }
}

auto User::listener() -> void {
    fd_set rfds;
    int maxfd = 0;
    timeval tv{5, 0};
    int retry_time = 3;

    while (true) {
        FD_ZERO(&rfds);
        FD_SET(0, &rfds);
        maxfd = 0;
        FD_SET(this->fd_, &rfds);
        if (maxfd < this->fd_) {
            maxfd = this->fd_;
        }
        int rtn = select(maxfd + 1, &rfds, nullptr, nullptr, nullptr);

        if (rtn < 0) {
            LOG(ERROR) << "select error, error code=" << rtn;
            break;
        } else if (rtn == 0) {
            // 等待超时
            // LOG(ERROR) << "client wait overtime.";
            continue;
        } else {
            // recv, 获取socket标记
            if (FD_ISSET(this->fd_, &rfds)) {
                char buf[MESSAGE_LEN];
                memset(buf, 0, MESSAGE_LEN);
                int len = recv(this->fd_, buf, MESSAGE_LEN, 0);
                if (len == 0) {
                    std::cout << "server端不在线，请检查，5秒后重试，再重试" << retry_time-- << "次后退出。" << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                    if (retry_time == 0) {
                        // close(fd);
                        std::cout << "exiting...\n";
                        exit(1);
                        break;
                    }
                }
                auto msg = std::string(buf);
                if (msg.starts_with("Server: ")) {
                    // Server official command
                    std::thread msg_processor(&User::server_msg_processor, this, msg);
                    msg_processor.detach();
                } else {
                    std::cout << buf << std::flush;
                    memset(buf, 0, MESSAGE_LEN);
                }
            }
        }
    }
}

auto User::is_connected() -> bool {
    return this->connection_;
}

}
