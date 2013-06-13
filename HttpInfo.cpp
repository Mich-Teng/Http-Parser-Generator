#include "HttpInfo.h"

using namespace std;

//********************************************************
//HttpHeader
//********************************************************
HttpHeader& HttpHeader::operator =(const HttpHeader& tmp)
{
	map<string,string> m;
	tmp.get(m);
	map<string,string>::iterator it = m.begin();
	for(;it != m.end(); it++)
		this->set((*it).first,(*it).second);
	return (*this);
}

bool HttpHeader::get(map<string,string>& map) const
{
	map = pairs;
	return true;
}

HttpHeader::HttpHeader()
{
	size = 0;
}

void HttpHeader::set(const string& key,const string& value)
{
	pairs.insert(map<string,string>::value_type(key,value));
}

bool HttpHeader::get(const string& key,string& value) const
{
	map<string,string>::const_iterator it = pairs.find(key);
	if( it == pairs.end())      // can not find the key
		return false; 
	value = (*it).second;
	return true;
} 



//********************************************************

//********************************************************
// HttpInfo
//********************************************************
HttpInfo::HttpInfo()
{
}

void HttpInfo::setHeader(const HttpHeader& h)
{
	header = h;
}

void HttpInfo::getHeader(HttpHeader& h) const
{
	h = header;
}




void  HttpInfo::setContent(const string& t)
{
	content = t;
}

const string& HttpInfo::getContent() const
{
	return content;
}	
