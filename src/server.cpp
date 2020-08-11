//
// Created by Vigo Wong on 11/8/20.
//

#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>

#include <chrono>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <string>
#include <thread>

#include "config.hpp"
#include "util.hpp"

int main(int argc, char const *argv[]) {
    if (argc != 2) { exit(1); }
    auto roomname = std::string(argv[1]);
    chatroom::GlogUtil::init_glog(roomname);
    LOG(ERROR) << roomname << " is running!" << std::endl;

    // socket
    auto fd = socket(AF_INET, SOCK_STREAM, 0);
    auto reuse = 0;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    struct sockaddr_in serv_addr{};
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(IP);

    // bind
    int saddr_len = sizeof(serv_addr);
    if (bind(fd, (struct sockaddr *) &serv_addr, saddr_len) == -1) {
        perror("bind error.");
        exit(1);
    }

    LOG(ERROR) << "bind success.";

    // listen
    auto listen_queue_size = 20;
    if (listen(fd, listen_queue_size) == -1) {
        perror("listen error.");
        exit(1);
    }
    LOG(ERROR) << "listen success.";

    // accept
    auto socket_list = std::list<int>();
    auto usr_database = std::map<int, std::string>();
    auto data = std::string();
//    std::thread accept_socket(AcceptSocket, fd, std::ref(serv_addr), saddr_len, std::ref(socket_list));

    return 0;
}