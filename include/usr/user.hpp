//
// Created by Vigo Wong on 11/8/20.
//

#ifndef WECHAT_ROOM_MANAGER_HPP
#define WECHAT_ROOM_MANAGER_HPP

#endif //WECHAT_ROOM_MANAGER_HPP

#include <iostream>
#include <string>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <utility>
#include <sys/socket.h>
#include <string>
#include <cstring>
#include <range/v3/all.hpp>

#include <chrono>
#include <iostream>
#include <thread>
#include <fmt/format.h>
#include <sstream>

#include "config.hpp"
#include "util.hpp"

namespace chatroom {
class User {
public:
    // constructor
    explicit User(std::string &name, int id, std::string &password);

    User() = default;

    // connect to the chat room
    auto join_chatroom() -> void;

    // return the name of the user
    [[nodiscard]] auto get_usr_name() const -> std::string;

    // return the id of the user
    [[nodiscard]] auto get_usr_id() const -> int;

    auto listener() -> void;

    auto connect_to_server() -> void;

    auto registration() -> void;

    auto sendMessage(const std::string &msg) -> void;

    auto login() -> void;

    auto set_connection(const std::string &name) -> void;

    auto exit_chatroom() -> void;

    auto verify_admin(const std::string &code) -> void;

    auto server_msg_processor(const std::string &msg) -> void;

    auto is_connected() -> bool;


private:
    [[nodiscard]] auto is_admin() const -> bool;

    auto set_admin() -> void;

    std::string room_{};
    std::string name_{}; // user name
    int id_{};  // user id with 6 digits
    bool is_admin_ = false; // usr is common member by default
    std::string password_ = "1234567"; // user password

    // socket info
    int fd_ = 0;
    sockaddr_in serv_addr_{};
    int reuse_ = 0;
    socklen_t saddr_len_ = 0;

    // is connected
    bool connection_ = false;
};

}