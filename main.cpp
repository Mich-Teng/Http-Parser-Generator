#include "HttpProtocol.h"
#include "HttpRequest.h"
#include <string>
#include "constant.h"
#include <iostream>
using namespace std;

extern Status status_op[];

int main()
{
	HttpProtocol p;
	HttpRequest q;
	HttpResponse r;
	HttpResponse ra;
	string str;
	q.setMethod(POST);
	q.setResource("/");
	q.setVersion("Http/1.1");
	q.header.set("HOST","www.baidu.com");
	q.setContent("ss");
	p.geneHttpRequest(q,str);
	cout << str << endl;
	string tst = "POST / HTTP/1.1\nHost: 127.0.0.1:1234\nUser-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:21.0) Gecko/20100101 Firefox/21.0\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\nContent-Length: 31\n\rip=127.0.0.1&port=1234&path=%2F";
	
	HttpRequest w;
	p.parseHttpRequest(tst,w);
	
	cout << method[w.getMethod()] << endl;
	cout << w.getResource() << endl;
	cout << w.getVersion() << endl;
	map<string,string> m;
	w.header.get(m);
	map<string,string>::iterator it = m.begin();
	for(;it != m.end(); it++)
		cout << (*it).first << ":" << (*it).second << endl;
	cout << w.getContent() << endl;
	string ss;
	w.header.get("HOST",ss);
	cout << ss << endl;
	//cout << str << endl;
	string s;
	r.setVersion("Http/1.1");
	r.setStatusCode(OK);
	r.setReason(OK);
	r.setContent("hello");
	p.geneHttpResponse(r,s);
	cout << s << endl;
	p.parseHttpResponse(s,ra);
	cout << ra.getContent() << endl;
	cout << ra.getVersion() << endl;
	cout << ra.getReason() << endl;
	cout << ra.getStatusCode() << endl;

	return 0;
}