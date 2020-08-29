//
// Created by Vigo Wong on 13/8/20.
//

#ifndef WECHAT_ROOM_SERVER_HPP
#define WECHAT_ROOM_SERVER_HPP

#endif //WECHAT_ROOM_SERVER_HPP

#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unordered_map>
#include <chrono>
#include <cstring>
#include <iostream>
#include <list>
#include <set>
#include <map>
#include <mutex>
#include <string>
#include <thread>
#include <range/v3/all.hpp>
#include <utility>
#include <fmt/format.h>

#include "config.hpp"
#include "util.hpp"

/*
 * TODO:
 * 1. server recv request from client and process request
 * 2. server transmit private msg between client
 * 3. server broadcast public msg to all client in the chatroom
 * 4. server manage usr information, including admin and common member
 * 5. server is in charge to registeration
 * 6. server maintain a log file to record the status
 * 7. server notify all members in chatroom before moderate terminated
 * 8. init a redis database to store info of client, before that, simply maintain a txt file for that
 */

class Server {
public:
    struct member_info {
        int fd;
        std::string name;
        bool connection = false;
    };


    struct cmp {
        auto operator()(const member_info &a, const member_info &b) const -> bool {
            return a.name < b.name;
        }
    };

    explicit Server(const std::string &room_name);

    auto bind_to_addr() -> void;

    auto listen_to_addr() -> void;

    auto request_listener() -> void;

    auto accept_socket() -> void;

    auto request_processor(std::string, int fd) -> void;

    auto send_message_to_clinet(const std::string &msg, int client_fd) -> void;

    auto load_admin_ids(const std::string &filename);

    auto send_chatroom_msg(const std::string &msg);

private:
    std::string room_name_;
    sockaddr_in serv_addr_;
    socklen_t saddr_len_;
    std::list<int> socket_list_;
    std::unordered_map<int, member_info> usr_database_;
    std::set<std::string> verification_codes_;
    std::unordered_map<int, std::string> id_pass_;
    int fd_;
};