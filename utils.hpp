#include <iostream>
#include <string>
#include <vector>
#include <unorder_map>

std::unorder_map<std::string, std::string> g_errmsg = {
    {"200",     "OK"},                              //正常处理
    {"206",     "Partial Content"},                 //分块传输
    {"302",     "Found"},                           //临时重定向
    {"304",     "Not Modified"},                    //资源未修改无需重传，搭配Last_Modified/Etag
    {"400",     "Bad Request"},                     //请求语法错误
    {"403",     "Forbidden"},
    {"404",     "Page Not Found"},                  //无资源
    {"405",     "Method Not Allowed"},              //请求方法被禁止
    {"412",     "Precondition Failed"},             //请求信息先决条件错误
    {"414",     "Request-URI Too Large"},           //uri（网址）过大
    {"416",     "Requested range not satisfiable"}, //分块传输，请求范围不合法
    {"500",     "Internal Server Error"},           //服务器内部错误
};
std::unorder_map<std::string, std::string> g_mime = {
    {"txt",     "text/plain"},
    {"html",    "text/html"},
    {"htm",     "text/html"},
    {"jpg",     "image/jpeg"},
    {"zip",     "application/zip"},
    {"mp3",     "audio/mpeg"},
    {"mpeg",    "video/mpeg"},
    {"unknow",  "application/octet-stream"},
};

class Utils
{
    public:
	static std::string & GetDesc(std::string &err){
	    if (g_errmsg.find(err) == g_errmsg.end()) {
		return g_errmsg["400"];
	    }
	    return g_errmsg[err];
	}
	static std::string & GetMime(std::string &fname){
	    size_t pos = fname.find_last_of('.');
	    if (pos == std::string::npos) {
		return g_mime["unknow"];
	    }
	    std::string type = fname.substr(pos + 1);
	    if (g_mime.find(type) == g_mime.end()) {
		return g_mime["unknow"];
	    }
	    return g_mime[type];
	}
};
