cmake_minimum_required(VERSION 3.15)
project(wechat_room)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
include_directories(include/usr)
include_directories(src)
include_directories(logs)
include_directories(src/usr)
include_directories(util)
include_directories(config)

# GLOG_ROOT_DIR 是glog 的安装路径
find_package(glog REQUIRED CONFIG HINTS ${GLOG_ROOT_DIR})
set(GLOG_INCLUDE_DIR ${GLOG_ROOT_DIR}/include)
# glog::glog is imported target
set(GLOG_LIBRARY glog::glog)

include_directories(${LINK_DIR})
add_executable(wechat_room
#        include/usr/admin.hpp
#        include/usr/user.hpp
#        include/usr/member.hpp
#        src/client.cpp
        src/server.cpp
#        src/usr/admin.cpp
#        src/usr/user.cpp
#        src/usr/member.cpp
        util/util.cpp
        util/util.hpp
        config/config.hpp
        )

target_link_libraries(wechat_room glog::glog)