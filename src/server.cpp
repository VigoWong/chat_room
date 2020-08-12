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
#include <range/v3/all.hpp>

#include "config.hpp"
#include "util.hpp"

auto accept_socket(int fd, struct sockaddr_in sock_addr, socklen_t saddr_len, std::list<int> &sock_list) -> void {
    while (true) {
        int client_fd = accept(fd, (sockaddr *) &sock_addr, &saddr_len);
        std::cout << fd << " is linked." << std::endl;
        sock_list.push_back(client_fd);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

auto request_processor(std::list<int> &socket_list) -> void {
    LOG(ERROR) << "Requests are being processed.";
    auto timeout = timeval();
    while (true) {
        if (std::empty(socket_list)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        } else {
            for (auto sock:socket_list) {
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
                    LOG(ERROR) << "select error.";
                    std::cout << "select error." << std::endl;
                }else if (rtn == 0) {
                // 连接超时
                // LOG(ERROR) << "select overtime, continue";
                // cout << "select OK." << endl;
                }else{
                    
                }

            }
        }
    }
}


int main(int argc, char const *argv[]) {
    if (argc != 2) { exit(1); }
    auto roomname = std::string(argv[1]);
    chatroom::GlogUtil::init_glog(roomname);
    LOG(ERROR) << roomname << " is running!" << std::endl;

    // socket(fd is an abbreviation of file descriptor, which can be regarded as file,
    // being used for receiving and sending msg )
    auto fd = socket(AF_INET, SOCK_STREAM, 0);
    auto reuse = 0;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    auto serv_addr = sockaddr_in();
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
    // the list of client fd
    auto socket_list = std::list<int>();
    auto usr_database = std::map<int, std::string>();
    auto data = std::string();

    //  trigger a daemon thread to listen to the request
    std::thread listening_thread(accept_socket, fd, std::ref(serv_addr), saddr_len, std::ref(socket_list));
    listening_thread.detach();
    LOG(ERROR) << "listening to request.";

    // trigger a daemon thread to process request
    std::thread response_thread(request_processor, std::ref(socket_list));
    response_thread.detach();
    LOG(ERROR) << "Server is on.";

    // hang on the main thread until manual terminated
    while (true) {
        LOG(ERROR) << "chatroom server is active.";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 * 100));
    }

    return 0;
}