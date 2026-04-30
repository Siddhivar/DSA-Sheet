#include<bits/stdc++.h>
using namespace std;

class HTTPRequest{
    private:
    string url;
    string method;
    map<string,string>headers;
    map<string,string>queryparams;
    string body;
    int timeout;

    //private constructor - can only be accessed by the builder
    HTTPRequest(){};

    public:
    friend class HTTPReqBuilder;

    void execute(){
        cout<<"Executing method "<<method<<" for url "<<url<<endl;
        if(!queryparams.empty()){
            cout<<"Query-Param: ";
            for(const auto& q:queryparams){
                cout<<" "<<q.first<<" = "<<q.second<<endl;
            }
        }
        if(!headers.empty()){
            cout<<"Headers: ";
            for(const auto& h:headers){
                cout<<" "<<h.first<<" : "<<h.second<<endl;
            }
        }
        if(!body.empty()){
            cout<<"Body: "<<body<<endl;
        }
        cout<<"Timeout: "<<timeout<<endl;
    }
};

class HTTPReqBuilder{
    HTTPRequest req;
    public:
    HTTPReqBuilder(){
        req.method="GET";
        req.timeout=30;
    }
    HTTPReqBuilder &withUrl(const string& url){
        req.url=url;
        return *this; //return the same builder object
    }
    HTTPReqBuilder &withMethod(const string& method){
        req.method=method;
        return *this;
    }
    HTTPReqBuilder &withQueryParams(const string& key, const string& value){
        req.queryparams[key]=value;
        return *this;
    }
    HTTPReqBuilder &withHeaders(const string& key, const string& value){
        req.headers[key]=value;
        return *this;
    }
    HTTPReqBuilder &withBody(string body){
        req.body=body;
        return *this;
    }
    HTTPReqBuilder &withTimeout(int timeout){
        req.timeout=timeout;
        return *this;
    }
    HTTPRequest build(){
        if(req.url.empty()){
            throw runtime_error("URL cannot be empty");
        }
        return req;
    }
};
int main(){
    HTTPRequest req=HTTPReqBuilder()
    .withUrl("api.com")
    .withMethod("GET")
    .withHeaders("Content-Type","Application/json")
    .withQueryParams("key","12345")
    .withTimeout(30)
    .build();

    req.execute();

    HTTPReqBuilder builder;
    HTTPRequest request = builder.withUrl("www.api.com").build();

    return 0;
}