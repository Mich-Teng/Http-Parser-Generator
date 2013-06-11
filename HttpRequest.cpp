#include "HttpRequest.h"
#include <string>

using namespace std;

void HttpRequest::setMethod(int method)
{
	request_line.method = method;
}	

int HttpRequest::getMethod() const
{
	return request_line.method;
}

void  HttpRequest::setResource(const string& res)
{
	request_line.resource = res;
}

const string&  HttpRequest::getResource() const
{
	return request_line.resource;
}

void  HttpRequest::setVersion(const string& res)
{
	request_line.version = res;
}

const string&  HttpRequest::getVersion() const
{
	return request_line.version;
}