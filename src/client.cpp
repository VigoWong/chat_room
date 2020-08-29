//
// Created by Vigo Wong on 11/8/20.
//
//#include "admin.hpp"
//#include "member.hpp"
#include "usr/user.hpp"

int main(int argc, char const *argv[]) {
    std::string chat_room = "chatroom";
    chatroom::GlogUtil::init_glog(chat_room);

    auto user = chatroom::User();
    user.connect_to_server();
    user.join_chatroom();

    std::cout << "Please select options below: " << std::endl;
    std::cout << "\t1. register " << std::endl;
    std::cout << "\t2. log in " << std::endl;
    int op;
    std::cin >> op;

    // obtain the login method
    if (op == 1) {
        user.registration();
    } else if (op == 2) {
        user.login();
    } else {
        LOG(FATAL) << "Unexpected operation";
        exit(1);
    }

    auto msg = std::string();

    std::cout << "#1. add a prefix '#' to talk in chat room" << std::endl;
    std::cout << "#2. add a prefix '* <id>' to launch a private chat" << std::endl;
    std::cout << "#3. input '%exit' to exit the chat room" << std::endl << std::endl;
    // TODO: adding more feature
    while (true) {
        std::getline(std::cin, msg);
        if (msg.starts_with("#")) {
            if(user.is_connected()){
                msg = msg.substr(1, msg.size() - 1);
                msg = fmt::format("#{} says: {}", user.get_usr_name(), msg);
                user.sendMessage(msg);
            }else{
                LOG(ERROR) << "You hasn't registered or logined";
            }
        } else if (msg.starts_with("*")) {
            //TODO
            if(user.is_connected()){
            }else{
                LOG(ERROR) << "You hasn't registered or logined";
            }
        } else if (msg == "%exit") {
            user.exit_chatroom();
            break;
        }
    }
    return 0;
}