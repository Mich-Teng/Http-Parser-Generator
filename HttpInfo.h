#ifndef HTTPINFO_H
#define HTTPINFO_H

#include <string>


class HttpHeader
{
public:
	std::string host;
	std::string user_agent;
//	std::string accept;
//	std::string authorization;
//	std::string referer;
};

class HttpInfo
{
public:
	HttpInfo();

	void setHost(const std::string& host);
	const std::string& getHost() const;
	void setUserAgent(const std::string& user_agent);
	const std::string& getUserAgent() const;
	void setContent(const std::string& content);
	const std::string& getContent() const;
	void getHeader(HttpHeader& header) const;
protected:
	HttpHeader header;		  // http header
	std::string content; 		  // http content
 


};

#endif
