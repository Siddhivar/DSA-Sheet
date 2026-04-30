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
    friend class HTTPReqStepBuilder;

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

// Step Interfaces
class MethodStep;
class OptionalStep;

class UrlStep{
    public:
    virtual MethodStep& withUrl(const string &url)=0;
};
class MethodStep{
    public:
    virtual OptionalStep& withMethod(const string& method)=0;
};
class OptionalStep{
    public:
    virtual OptionalStep& withHeaders(const string& key, const string& value)=0;
    virtual OptionalStep& withQueryParams(const string& key, const string& value)=0;
    virtual OptionalStep& withBody(const string& body)=0;
    virtual OptionalStep& withTimeout(int timeout)=0;
    virtual HTTPRequest build()=0;
};
class HTTPReqStepBuilder: public UrlStep, public MethodStep, public OptionalStep{
    private:
    HTTPRequest req;
    public:
    MethodStep &withUrl(const string& url) override{
        req.url=url;
        return *this;
    }
    OptionalStep &withMethod(const string& method)override{
        req.method=method;
        return *this;
    }
    OptionalStep &withQueryParams(const string& key, const string& value)override{
        req.queryparams[key]=value;
        return *this;
    }
    OptionalStep &withHeaders(const string& key, const string& value)override{
        req.headers[key]=value;
        return *this;
    }
    OptionalStep &withBody(const string& body)override{
        req.body=body;
        return *this;
    }
    OptionalStep &withTimeout(int timeout)override{
        req.timeout=timeout;
        return *this;
    }
    HTTPRequest build()override{
        if(req.url.empty()){
            throw runtime_error("URL is not given");
        }
        return req;
    }
    //Static means: You can call it WITHOUT object
    static UrlStep& getBuilder(){
        return *(new HTTPReqStepBuilder());
    } 
};

int main(){
    HTTPRequest req=HTTPReqStepBuilder::getBuilder()
    .withUrl("api.com")
    .withMethod("POST")
    .withBody("data")
    .withTimeout(30)
    .build();

    req.execute();

    return 0;
}