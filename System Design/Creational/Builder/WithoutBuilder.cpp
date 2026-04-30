#include<bits/stdc++.h>
using namespace std;

class HTTPRequest{
    private:
    string url;
    string method;
    map<string,string>header;
    map<string,string>queryparams;
    string body;
    int timeout;

    public:
    HTTPRequest(const string& url){
        this->url=url;
        this->method="GET";
        this->timeout=30;
    }
    HTTPRequest(const string& url, string method){
        this->url=url;
        this->method=method;
        this->timeout=30;
    }
    HTTPRequest(const string& url, string method, int timeout){
        this->url=url;
        this->method=method;
        this->timeout=timeout;
    }
    HTTPRequest(const string& url,string method,int timeout, map<string,string>header){
        this->url=url;
        this->method=method;
        this->timeout=timeout;
        this->header=header;
    }
    HTTPRequest(const string& url,string method,int timeout, map<string,string>header, map<string,string>queryparams){
        this->url=url;
        this->method=method;
        this->timeout=timeout;
        this->header=header;
        this->queryparams=queryparams;
    }
    HTTPRequest(const string& url,string method,int timeout, map<string,string>header,map<string,string>queryparams, string body){
        this->url=url;
        this->method=method;
        this->timeout=timeout;
        this->header=header;
        this->queryparams=queryparams;
        this->body=body;
    }

    void setUrl(const string& url){
        this->url=url;
    }
    void setMethod(string method){
        this->method=method;
    }
    void addHeader(const string& key, const string& value){
        header[key]=value;
    }
    void addQueryParam(const string& key, const string& value){
        queryparams[key]=value;
    }
    void setBody(string body){
        this->body=body;
    }
    void setTimeout(int timeout){
        this->timeout=timeout;
    }

    void execute(){
        cout<<"Executing method "<<method<<" for url "<<url<<endl;
        if(!queryparams.empty()){
            cout<<"Query-Param: ";
            for(const auto& q:queryparams){
                cout<<" "<<q.first<<" = "<<q.second<<endl;
            }
        }
        if(!header.empty()){
            cout<<"Header: ";
            for(const auto& h:header){
                cout<<" "<<h.first<<" : "<<h.second<<endl;
            }
        }
        if(!body.empty()){
            cout<<"Body: "<<body<<endl;
        }
        cout<<"Timeout: "<<timeout<<endl;
    }
};
int main(){
    HTTPRequest* h1= new HTTPRequest("api.com");
    HTTPRequest* h2= new HTTPRequest("api.com", "PUT");
    HTTPRequest* h3= new HTTPRequest("api.com", "POST", 40);
    HTTPRequest* h4= new HTTPRequest("api.com");
    h4->addHeader("Content-Type","Application/json");
    h4->setMethod("POST");
    h4->setTimeout(55);
    h4->addQueryParam("key","12345");
    h4->execute();
    return 0;
}