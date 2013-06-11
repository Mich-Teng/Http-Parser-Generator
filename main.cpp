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
	q.setMethod(GET);
	q.setResource("/");
	q.setVersion("Http/1.1");
	q.setHost("www.baidu.com");
	q.setContent("ss");
	p.geneHttpRequest(q,str);
	HttpRequest w;
	p.parseHttpRequest(str,w);
	cout << w.getContent() << endl;
	cout << method[w.getMethod()] << endl;
	cout << w.getResource() << endl;
	cout << w.getVersion() << endl;
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