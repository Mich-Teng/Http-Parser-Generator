#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include "HttpInfo.h"
class HttpRequestLine
{
public:
	int method;
	std::string resource;
	std::string version;
};


class HttpRequest:public HttpInfo
{
public:
	void setMethod(int method);        
	int getMethod() const;
	void setResource(const std::string& res);
	const std::string& getResource() const; 
	void setVersion(const std::string& res);
	const std::string& getVersion() const;

private:
	HttpRequestLine request_line;     // http request line
};

#endif