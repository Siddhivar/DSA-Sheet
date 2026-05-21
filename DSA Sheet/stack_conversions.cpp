#include<bits/stdc++.h>
using namespace std;

// INFIX to POSTFIX
int precedence(char ch){
    if(ch=='^') return 3;
    else if(ch=='/' || ch=='*') return 2;
    else if(ch=='+' || ch=='-') return 1;
    else return -1;
}
string infixToPostfix(string s){
    stack<int>st;
    string result="";
    for(char ch: s){
        if(isalnum(ch)){
            result+=ch;
        }else if(ch=='('){
            st.push(ch);
        }else if(ch==')'){
            while(!st.empty() && st.top()!='('){
                result+=st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() && precedence(ch)<=precedence(st.top())){
                result+=st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    return result;
}

string reverse(string s){
    int i=0;
    int j=s.size()-1;
    while(i<j){
        swap(s[i],s[j]);
        i++;
        j--;
    }
    return s;
}
//INFIX TO PREFIX
string infixToPrefix(string s){
    stack<char>st;
    string result="";
    for(int i=s.size()-1;i>=0;i--){
        if(isalnum(s[i])){
            result+=s[i];
        }else if(s[i]==')'){
            st.push(s[i]);
        }else if(s[i]=='('){
            while(!st.empty() && st.top()!=')'){
                result+=st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() && precedence(s[i])<=precedence(st.top())){
                result+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    return reverse(result);
}
string prefixToInfix(string s){
    stack<string>st;
    for(int i=s.size()-1;i>=0;i--){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }else{
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            string exp="("+op1+s[i]+op2+")";
            st.push(exp);
        }
    }
    return st.top();

}
string postfixToInfix(string s){
    stack<string>st;
    for(int i=0;i<s.size();i++){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }else{
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            string exp="("+op2+s[i]+op1+")";
            st.push(exp);
        }
    }
    return st.top();
}
string PrefixToPostfix(string s){
    stack<char>st;
    result="";
    for(char ch:s){
        if(isalnum(ch)){
            result+=ch;
        }else{
            if(!st.empty() && )
        }
    }
}
int main(){
    // string s="a+b*(c^d-e)^(f+g*h)-i";
    // cout<<"Infix: "<<s<<endl;
    // cout<<"Postfix: "<<infixToPostfix(s)<<endl;
    // cout<<"Prefix: "<<infixToPrefix(s)<<endl;
    
    // string prefix="*+PQ-MN";
    // cout<<"Prefix: "<<prefix<<endl;
    // cout<<"Infix: "<<prefixToInfix(prefix)<<endl;

    string postfix="ab+c*";
    cout<<"Postfix: "<<postfix<<endl;
    cout<<"Infix: "<<postfixToInfix(postfix)<<endl;
    return 0;
}