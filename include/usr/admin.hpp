//
// Created by Vigo Wong on 11/8/20.
//

#ifndef WECHAT_ROOM_MANAGER_HPP
#define WECHAT_ROOM_MANAGER_HPP

#endif //WECHAT_ROOM_MANAGER_HPP

#include <iostream>
#include <string>

namespace chatroom {

    class User {
        using id_type = int;
    public:
//        // constructor
//        explicit User(std::string &name, id_type id, std::string &password) : name_(name), id_(id),
//                                                                              password_(password) {}


    private:
        std::string name_; // user name
        id_type id_{};  // user id with 6 digits
        bool is_admin_ = false; // usr is common member by default
        const std::string password_ = "1234567"; // user password
    };
}