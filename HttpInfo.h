#ifndef HTTPINFO_H
#define HTTPINFO_H

#include <string>
#include <map>

class HttpHeader	// Http Header info
{
public:
	HttpHeader& operator =(const HttpHeader& );
	bool get(const std::string&, std::string& res) const;		// get the value of specific key
	void set(const std::string&, const std::string& );	// set the key-value pair
	bool get(std::map<std::string,std::string>& map) const;   // get all the value of header
	HttpHeader();
private:
	std::map<std::string,std::string> pairs;
	int size;
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
	HttpHeader header;		  // http header
protected:
	
	std::string content; 		  // http content
 


};

#endif
