
add_executable(client
	util.cpp
	usr/user.cpp
	client.cpp
)

add_executable(server
	util.cpp
	server.cpp
)

target_link_libraries(server glog::glog range-v3 fmt::fmt)
target_link_libraries(client glog::glog range-v3 fmt::fmt)


include_directories(usr)