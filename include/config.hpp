# pragma once
#define IP "127.0.0.1"
#define PORT 10001
#define MESSAGE_LEN 1024
#define REGISTER_PREFIX "REGISTERINFO:"
#define PRIVATE_PREFIX "TALKTO:"
#define EXITCHAT "EXIT:"
#define CONNECTREQUEST "CONNECTION"
#define JOINREQUEST_PREFIX "JOIN: "
#define VERIFICATION_CODE_FILE "code.txt"
#define VERIFY_PREFIX "VERIFY:"
#define LOGIN_PREFIX "LOGIN:"
#define PUBLIC_MSG_PREFIX "#"
#define PRIVATE_MSG_PREFIX "*"


/* msg format between client and server:
 *
 * registration:
 *      REGISTER INFO: <id> <password> <name>
 *
 * joining request:
 *      JOIN INFO: <id>
 *
 * Welcome info:
 *      SERVER: welcome to <room_name>
 *
 *
 *
 *
 *
 *
 *
 *
 */