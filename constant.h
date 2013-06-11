#ifndef CONSTANT_H
#define CONSTANT_H
#include <string>
//global constant
#define MAX_LENGTH_OF_HTTP 4096

// request method
#define GET 0
#define POST 1
#define HEAD 2
#define PUT 3
#define DELETE 4
#define TRACE 5
#define CONNECTION 6
#define OPTIONS 7

const std::string method[] = {"GET","POST","HEAD","PUT","DELETE","TRACE","CONNECTION","OPTIONS"};

// header info

#define HEADER_ITEM_NUM 2
#define HOST 0
#define USER_AGENT 1
const std::string header_item[] = {"HOST","USER_AGENT"};

// status code
struct Status
{
	int code;
	std::string description;
};


#define OK 0
#define BADREQUEST 1
#define UNAUTHORIZED 2
#define FORBIDDEN 3
#define NOTFOUND 4
#define INTERNET_SERVER_ERROR 5
#define SERVER_AVAILABLE 6

#endif
