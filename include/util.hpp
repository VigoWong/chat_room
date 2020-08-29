//
// Created by Vigo Wong on 11/8/20.
//

#ifndef WECHAT_ROOM_UTIL_HPP
#define WECHAT_ROOM_UTIL_HPP

#endif //WECHAT_ROOM_UTIL_HPP

#include <glog/logging.h>
#include <string>

namespace chatroom {
    class GlogUtil {
    public:
        static void init_glog(const std::string& chatroom);
    };

    auto split_string_by_space(const std::string &text) -> std::vector<std::string>;
}

