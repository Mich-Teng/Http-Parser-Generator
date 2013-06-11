#include "HttpInfo.h"

using namespace std;

HttpInfo::HttpInfo()
{
}

void HttpInfo::getHeader(HttpHeader& h) const
{
	h = header;
}

void  HttpInfo::setHost(const string& host)
{
	header.host = host;
}

const string&  HttpInfo::getHost() const 
{
	return header.host;
}
	
void  HttpInfo::setUserAgent(const string& user_agent)
{
	header.user_agent = user_agent;
}
	
const string&  HttpInfo::getUserAgent() const
{
	return header.user_agent;
}

void  HttpInfo::setContent(const string& t)
{
	content = t;
}

const string& HttpInfo::getContent() const
{
	return content;
}	
