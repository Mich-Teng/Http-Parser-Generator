#include "HttpResponse.h"
#include <string>
#include "constant.h"

using namespace std;

extern Status status_op[];

void HttpResponse::setReason(int index)
{
	response_line.reason = status_op[index].description;
}

void HttpResponse::setStatusCode(int code)
{
	response_line.status_code = code;
}	

int HttpResponse::getStatusCode() const
{
	return status_op[response_line.status_code].code;
}

void  HttpResponse::setReason(const string& res)
{
	response_line.reason = res;
}

const string&  HttpResponse::getReason() const
{
	return response_line.reason;
}

void  HttpResponse::setVersion(const string& res)
{
	response_line.version = res;
}

const string&  HttpResponse::getVersion() const
{
	return response_line.version;
}