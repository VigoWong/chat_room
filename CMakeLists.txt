cmake_minimum_required(VERSION 3.15)
project("wechat_room" CXX)

set(CMAKE_CXX_STANDARD 20)


# testing framework
find_package(Catch2)
# logging package
find_package(glog)
# string formatting
find_package(fmt)
# c++ 20 range library
find_package(range-v3)

set(GLOG_INCLUDE_DIR ${GLOG_ROOT_DIR}/include)
# glog::glog is imported target
set(GLOG_LIBRARY glog::glog)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/built)

include_directories(${LINK_DIR})

include_directories(include)
add_subdirectory(src)

