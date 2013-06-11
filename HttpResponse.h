#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include "HttpInfo.h"


class HttpResponseLine
{
public:
	int status_code;
	std::string reason;
	std::string version;
};


class HttpResponse:public HttpInfo
{
public:
	void setStatusCode(int method);        
	int getStatusCode() const;
	void setReason(const std::string& res);
	void setReason(int);
	const std::string& getReason() const; 
	void setVersion(const std::string& res);
	const std::string& getVersion() const;

private:
	HttpResponseLine response_line;     // http request line
};

#endif