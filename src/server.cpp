//
// Created by Vigo Wong on 11/8/20.
//

#include "server.hpp"

#include <cstring>
#include <utility>
#include <sstream>
#include <unordered_map>
#include <range/v3/all.hpp>
#include <fstream>
#include <fmt/format.h>

auto Server::accept_socket() -> void {
    while (true) {
        int client_fd = accept(this->fd_, (sockaddr *) &this->serv_addr_, &this->saddr_len_);
        std::cout << client_fd << " is linked." << std::endl;
        this->socket_list_.push_back(client_fd);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

auto Server::send_message_to_clinet(const std::string &msg, int client_fd) -> void {
    char buf[MESSAGE_LEN];
    memset(buf, 0, MESSAGE_LEN);
    ranges::copy(msg, buf);
    send(client_fd, buf, MESSAGE_LEN, 0);
}

auto Server::send_chatroom_msg(const std::string &msg) {
    char buf[MESSAGE_LEN];
    memset(buf, 0, MESSAGE_LEN);
    ranges::copy(msg, buf);
    for (auto i:this->socket_list_) {
        send(i, buf, MESSAGE_LEN, 0);
    }
}

auto Server::request_processor(std::string recv_msg, int fd) -> void {
    const auto join_prefix = std::string(JOINREQUEST_PREFIX);
    const auto register_prefix = std::string(REGISTER_PREFIX);
    const auto transmit_prefix = std::string(PRIVATE_PREFIX);
    const auto connect_request = std::string(CONNECTREQUEST);
    const auto login_prefix = std::string(LOGIN_PREFIX);
    const auto exit_prefix = std::string(EXITCHAT);
    const auto verify_prefix = std::string(VERIFY_PREFIX);
    auto words = chatroom::split_string_by_space(recv_msg);

    if (recv_msg == connect_request) {
        auto msg = fmt::format("Server: Welcome to {}", this->room_name_);
        send_message_to_clinet(msg, fd);
    } else if (recv_msg.starts_with(register_prefix)) {
        // registration info(sock name)
        try {
            auto id = std::stoi(words[1]);
            auto password = words[2];
            auto name = words[3];
            if (this->id_pass_.find(id) == this->id_pass_.end()) {
                auto a = Server::member_info{fd, name, true};
                this->usr_database_[id] = a;
                this->id_pass_[id] = password;
                send_message_to_clinet(fmt::format("Server: Welcome to {}, {}", this->room_name_, a.name), fd);
                LOG(ERROR) << fmt::format("Server receive registration request from user: {}", a.name);
            } else {
                send_message_to_clinet("Server: The registration id has already existed", fd);
            }
        } catch (...) {
            LOG(FATAL) << "Incorrectly formatted message!";
        }
    } else if (recv_msg.starts_with(login_prefix)) {
        try {
            auto id = std::stoi(words[1]);
            auto password = words[2];
            if (this->id_pass_.find(id) == this->id_pass_.end() or this->id_pass_[id] != password) {
                send_message_to_clinet("Server: Incorrect id or password", fd);
            } else {
                this->usr_database_[id].fd = fd;
                send_message_to_clinet(
                        fmt::format("Server: Welcome to {}, {}", this->room_name_, this->usr_database_[id].name), fd);
            }
        } catch (...) {
            LOG(FATAL) << "Incorrectly formatted message!";
        }
    } else if (recv_msg.starts_with(verify_prefix)){
        try{
            auto code = words[1];
            if(this->verification_codes_.find(code)!=this->verification_codes_.end()){
                send_message_to_clinet("Server: Welcome, admin",fd);
            }else{
                send_message_to_clinet("Server: Your verification code is incorrect, try again later",fd);
            }
        } catch (...){
            LOG(ERROR) << "Incorrect formatted message";
        }
    } else if (recv_msg.starts_with(exit_prefix)) {
        auto id = stoi(words[1]);
        this->usr_database_[id].connection = false;
    } else if (recv_msg.starts_with(PUBLIC_MSG_PREFIX)) {
        this->send_chatroom_msg(recv_msg);
    } else {
        LOG(ERROR) << "do nothing";
    }
}

auto Server::request_listener() -> void {
    LOG(ERROR) << "Server: Processing request.";
    auto timeout = timeval();
    while (true) {
        if (std::empty(this->socket_list_)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        } else {
            for (auto sock:this->socket_list_) {
                auto rfds = fd_set();
                // clear the set to all 0
                FD_ZERO(&rfds);
                int maxfd = 0;
                // flip the 4th position of the set to 1
                FD_SET(sock, &rfds);
                if (maxfd < sock) {
                    maxfd = sock;
                }
                // select调用完后，timeout的值可能被修改，是一个不确定的值，所以cpu可能飙升到100%
                // 所以需要在while循环内部每次都赋值一遍
                timeout.tv_sec = 2;
                timeout.tv_usec = 0;
                int rtn = select(maxfd + 1, &rfds, NULL, NULL, &timeout);
                if (rtn < 0) {
                    LOG(ERROR) << "Select error.";
                    std::cout << "Select error." << std::endl;
                } else if (rtn == 0) {
                    // 连接超时
                    // LOG(ERROR) << "select overtime, continue";
                    // cout << "select OK." << endl;
                } else {
                    char recv_msg[MESSAGE_LEN];
                    memset(recv_msg, 0, MESSAGE_LEN);

                    // recv take four parameters, including the recv buffer and return the length of msg being copied into buffer
                    // here the server recv msg from client and convert it to std::string for further processed
                    int len = recv(sock, recv_msg, MESSAGE_LEN, 0);

                    if (len < 0) {
                        continue;
                    }
                    if (len == 0) {
                        LOG(ERROR) << fmt::format("User {} is offline", sock);
                        close(sock);
                        auto iter = ranges::find(this->socket_list_, sock);
                        if (iter != this->socket_list_.end()) {
                            this->socket_list_.erase(iter);
                        }

                    } else if (len > 0) {
                        // successfully recv msg from client
                        LOG(INFO) << "recv message len=" << strlen(recv_msg)
                                  << ", clientid=" << sock << ", message=" << recv_msg << std::endl;

                        // trigger a thread to process request
                        std::thread processor(&Server::request_processor, this, std::string(recv_msg), sock);
                        processor.detach();
                    } else {
                        LOG(ERROR) << "Conection Error from " << sock;
                        continue;
                    }
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

auto Server::bind_to_addr() -> void {
    // bind
    this->saddr_len_ = sizeof(this->serv_addr_);
    if (bind(this->fd_, (struct sockaddr *) &this->serv_addr_, this->saddr_len_) == -1) {
        perror("Bind error.");
        exit(1);
    }
    LOG(ERROR) << "Server: Bind success.";
}

auto Server::listen_to_addr() -> void {
    // listen
    auto listen_queue_size = 20;
    if (listen(this->fd_, listen_queue_size) == -1) {
        perror("listen error.");
        exit(1);
    }
    LOG(ERROR) << "Server: Ready to listen.";
}

auto Server::load_admin_ids(const std::string &filename) {
    auto file = std::ifstream(filename);
    auto line = std::string();
    while (std::getline(file, line)) {
        this->verification_codes_.insert(line);
    }
}

Server::Server(const std::string &room_name) : room_name_(room_name), serv_addr_(sockaddr_in()) {
    chatroom::GlogUtil::init_glog(this->room_name_);
    LOG(ERROR) << "Server: " << this->room_name_ << " is initializing." << std::endl;

    // socket(fd is an abbreviation of file descriptor, which can be regarded as file,
    // being used for receiving and sending msg )
    this->fd_ = socket(AF_INET, SOCK_STREAM, 0);
    auto reuse = 0;
    setsockopt(this->fd_, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    memset(&this->serv_addr_, 0, sizeof(this->serv_addr_));
    this->serv_addr_.sin_family = AF_INET;
    this->serv_addr_.sin_port = htons(PORT);
    this->serv_addr_.sin_addr.s_addr = inet_addr(IP);
    this->socket_list_ = std::list<int>();
    this->id_pass_ = std::unordered_map<int, std::string>();

    // bind
    this->bind_to_addr();

    // listening
    this->listen_to_addr();

    // accept
    // trigger a daemon thread to listen to the request
    std::thread listening_thread(&Server::accept_socket, this);
    listening_thread.detach();
    LOG(ERROR) << "Server: Listening to request.";

    // loading the database of admin
    this->load_admin_ids(VERIFICATION_CODE_FILE);

    // trigger a daemon thread to process request
    std::thread response_thread(&Server::request_listener, this);
    response_thread.detach();
    LOG(ERROR) << "Server: Initialization done. ";
}

int main(int argc, char const *argv[]) {
    if (argc != 2) { exit(1); }
    auto roomname = std::string(argv[1]);
    auto server = Server(roomname);

    // hang on the main thread until manual terminated,
    // TODO: main thread continuously monitor background input and reponse
    while (true) {
        LOG(ERROR) << "Server: Chatroom server is active.";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 * 100));
    }

    return 0;
}