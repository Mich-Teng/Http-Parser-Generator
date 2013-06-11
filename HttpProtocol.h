#ifndef HTTPPROTOCOL_H
#define HTTPPROTOCOL_H

#include "HttpRequest.h"
#include "HttpResponse.h"
#include "HttpInfo.h"
#include <string>
#include <vector>
class HttpProtocol
{
public:
	void geneHttpRequest(const HttpRequest& http,std::string&);
	void parseHttpRequest(const std::string&,HttpRequest& http);
	void geneHttpResponse(const HttpResponse& ,std::string& );
	void parseHttpResponse(const std::string&,HttpResponse&);
private:
	void geneHeader(std::string& str,const HttpHeader& http);
	void parseRequestLine(std::string& str,HttpRequest& http);
	void parseHeader(std::string& str,HttpHeader& http);
	void split(std::string str,std::string pattern,std::vector<std::string>& );
	void parseResponseLine(std::string& str,HttpResponse& http);
};

#endif
