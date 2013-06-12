#ifndef HTTPINFO_H
#define HTTPINFO_H

#include <string>


class HttpHeader	// Http Header info
{
public:
	HttpHeader& operator =(const HttpHeader& );
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

	void setHost(const std::string& host);		// set host info
	const std::string& getHost() const;			// get host info
	void setUserAgent(const std::string& user_agent);		// set user_agent info
	const std::string& getUserAgent() const;		// get user_agent info
	void setContent(const std::string& content);		// set http content
	const std::string& getContent() const;		// get http content
	// easy to copy header from http request to the corresponding http response by calling getHeader and setHeader 
	void getHeader(HttpHeader& header) const;		// get the header of http package
	void setHeader(const HttpHeader& header);		// set the header of http package	
protected:
	HttpHeader header;		  // http header
	std::string content; 		  // http content
 


};

#endif
