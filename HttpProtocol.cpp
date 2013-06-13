#include "HttpProtocol.h"
#include "constant.h"
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;
Status status_op[] = {{200,"OK"},{400,"Bad Request"},{401,"Unauthorized"},{403,"Forbidden"},{404,"Not Found"},{500,"Internet Server Error"},{503,"Server Available"}};

void HttpProtocol::geneHttpResponse(const HttpResponse& http,string& response)
{
	HttpHeader header;
	http.getHeader(header);
	char t[10];
	sprintf(t, "%d", http.getStatusCode());
	string code = t;
	response = "" + http.getVersion() + " " + code + " " +  http.getReason() + "\n";
	geneHeader(response,header);
	response += http.getContent();
}



void HttpProtocol::geneHttpRequest(const HttpRequest& http,string& request)
{
	HttpHeader header;
	http.getHeader(header);
	// generate the request line
	request = "" + method[http.getMethod()] + " " + http.getResource() + " " + http.getVersion()+"\n";  
	// generate header
	geneHeader(request,header);
	request += http.getContent();
	return ;
}

void HttpProtocol::geneHeader(std::string& str,const HttpHeader& http)
{
	map<string,string> m;
	http.get(m);
	map<string,string>::iterator it = m.begin();
	for(;it != m.end(); it++)
		str = str+(*it).first + ":" + (*it).second + "\n";
	str+="\n";
}

// split the string
 void HttpProtocol::split(string str,string pattern, vector<string>& result)
 {
     std::string::size_type pos;
     str+=pattern;
     int size=str.size();
 
     for(int i=0; i<size; i++)
     {
         pos=str.find(pattern,i);
         if(pos<size)
         {
             std::string s=str.substr(i,pos-i);
             result.push_back(s);
             i=pos+pattern.size()-1;
         }
     }
     return;
 }

void HttpProtocol::parseHttpResponse(const std::string& res,HttpResponse& http)
{
	string response(res);
	int pos;
	if( (pos = res.find("\n\r"))!= -1)
		response = response.replace(pos,2,"\n\n");
	HttpHeader header;
	http.getHeader(header);
	string str(response);
	string delim = "\n";
	vector<string> vec;
	split(str,delim,vec);
	parseResponseLine(vec[0],http);
	int i = 1;
	while(vec[i] != "")
	{
		parseHeader(vec[i],header);
		i++;
	}
	i++;
	for(;i<vec.size();i++)
	{
		string tmp(http.getContent());
		tmp = tmp+vec[i];
		if(i != vec.size()-1)
			tmp+="\n";
		http.setContent(tmp);
	}	
}
void HttpProtocol::parseHttpRequest(const string& req,HttpRequest& http)
{
	string request(req);           // some browser will use /r to separate the header and content
	int pos;
	if( (pos = req.find("\n\r"))!= -1)
		request = request.replace(pos,2,"\n\n");
	HttpHeader header;
	http.getHeader(header);
	string str(request);
	string tmp = "";
	string delim = "\n";
	vector<string> vec;
	split(str,delim,vec);
	parseRequestLine(vec[0],http);
	int i = 1;
	while(vec[i] != "")
	{
		parseHeader(vec[i],header);
		i++;
	}
	i++;
	for(;i<vec.size();i++)
	{
		tmp = tmp+vec[i];
		if(i != vec.size()-1)
			tmp+="\n";
		http.setContent(tmp);
	}	
	http.setHeader(header);
}

void HttpProtocol::parseHeader(string& str,HttpHeader& http)
{
	int i=0;
	vector<string> p;
	split(str,":",p);
	http.set(p[0],p[1]);		
}

void HttpProtocol::parseResponseLine(string& str,HttpResponse& http)
{	
	vector<string> p;
	split(str," ",p);
	int number = atoi(p[1].c_str());
	if(p.size() != 3)
	{
		cout << "invalid format" << endl;
		exit(1);
	}
	http.setVersion(p[0]);
	for(int i =0 ; i<7; i++)
		if( number == status_op[i].code )
		{
			http.setStatusCode(i);
			break;
		}
	http.setReason(p[2]);             // set the version of http
	return ;
}
void HttpProtocol::parseRequestLine(string& str,HttpRequest& http)
{
	vector<string> p;
	split(str," ",p);
	if(p.size() != 3)
	{
		cout << "invalid format" << endl;
		exit(1);
	}
	for(int i =0 ; i<8; i++)
		if( p[0] == method[i] )
		{
			http.setMethod(i);
			break;
		}
	http.setResource(p[1]);            // set the resource
	http.setVersion(p[2]);             // set the version of http
	return ;
}
//	int geneHttpResponse(const HttpResponse& res);
//	const HttpResponse& parseHttpResponse();
