#include <iostream>
#include <string>
#include <unorder_map>
#include <sys/stat.h>
#include "tcpsocket.hpp"
#include "threadpool.hpp"

#define WWW_ROOT    "www"

enum req_type_t{
    REQ_UNKNOW = 0,
    REQ_FILE,
    REQ_CGI,
};
class Request
{
    public:
	Request(){
	}
	~Request(){
	}
	bool RecvHttpHeader(TcpSocket &sock){
	    return true;
	}
	std::string & GetErrno(){
	    return _errno;
	}
	std::string & GetPath(){
	    return _path;
	}
	std::string & GetMethod(){
	    return _method;
	}
	std::string & GetVersion(){
	    return _version;
	}
	req_type_t GetReqType(){
	    return REQ_UNKNOW;
	}
	std::unorder_map<std::string, std::string> & GetHeaders(){
	    return _headers;
	}

	void SetMethod(std::string &method){
	    _method = method;
	}
	void SetPath(std::string &path){
	    _path = path;
	}
	void SetVersion(std::string &version) {
	    _version = version;
	}
	void SetHeaders(std::string &key, std::string &val){
	    _headers[key] = val;
	}
	void MakeHttpHeader(std::string &hdr){
	    return;
	}
    private:
	std::string _hdr;
	std::string _errno;
	std::string _path;
	std::string _method;
	std::string _version;
	std::unorder_map<std::string, std::string> _headers;
};
class Response
{
    public:
	Response(){
	}
	~Response(){
	}
	void ErrorHandler(std::string &err){
	    return;
	}
	bool FileHandler(TcpSocket &sock, Request &req) {
	    return true;
	}
	bool CGIHandler(TcpSocket &sock, Request &req) {
	    return true;
	}
    private:
    private:
	std::string _errno;
};
 
class Http
{
    public:
	Http(){
	}
	~Http(){
	}
	bool HttpServere(){}
	bool HttpClient(){}
    private:
	static bool HttpHandler(TcpSocket sock) {
	    return true;
	}
    private:
	TcpSocket _socket;
	ThreadPool *_tp;
};
