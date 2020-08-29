//
// Created by Vigo Wong on 11/8/20.
//

#include "util.hpp"

namespace chatroom {
void GlogUtil::init_glog(const std::string &workspace_name) {
    google::InitGoogleLogging(workspace_name.c_str());
    google::SetLogDestination(google::INFO, "./logs/INFO_"); //设置 google::INFO 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::WARNING, "./logs/WARNING_");   //设置 google::WARNING 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::ERROR, "./logs/ERROR_");   //设置 google::ERROR 级别的日志存储路径和文件名前缀
    google::SetLogFilenameExtension(workspace_name.c_str());     // file name extension

    FLAGS_colorlogtostderr = true;    // color style
    FLAGS_logbufsecs = 0;        // immediate output
    FLAGS_max_log_size = 100;    // maximum size of the log
    FLAGS_stop_logging_if_full_disk = true;    // stop logging when the disk is full
}

auto split_string_by_space(const std::string &text) -> std::vector<std::string> {
    std::istringstream iss(text);
    return std::vector<std::string>(std::istream_iterator<std::string>(iss),
                                    std::istream_iterator<std::string>());

}

}