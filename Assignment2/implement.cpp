#include<iostream>
#include "stack.h"
#include "stack.cpp"
using namespace std;
class expression{
    public:
    string intopost(string s);
    string intopre(string s);
    int prec(char c);
    string reverse(string s);
    int evalpostfix(string s);
    int evalprefix(string s);
};
string expression:: reverse(string s){
    string rev;
    int a=s.length();
    for(int i=a-1; i>=0; i--){
        if(s[i]=='('){
            rev=rev+')';
        }
        else if(s[i]==')'){
            rev=rev+'(';
        }
        else{
            rev=rev+s[i];
        }
       
    }
    return rev;
}
int expression::prec(char c){
    if(c=='^'){
        return 3;
    }
    if(c=='*'|| c=='/'){
        return 2;
    }
    if(c=='+'|| c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
string expression::intopost(string s){
    Stack<char> st;
    string res;
    for(int i=0; i<s.length(); i++){
        if(s[i]>='a'&& s[i]<='z'){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push('(');
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty()&& prec(s[i])<=prec(st.top())){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
       
    }
    return res;
}
string expression:: intopre(string s){
       string rev=reverse(s);
       string mid=intopost(rev);
       string ans=reverse(mid);
       return ans;
}      
int expression:: evalpostfix(string s){
      Stack<int> st;
      for(int i=0; i<s.length(); i++){
          if(s[i]>='0' && s[i]<='9'){
                 st.push(s[i]-'0');
           }
           else{
               int op2=st.top();
               st.pop();
               int op1=st.top();
               st.pop();
               switch(s[i]){
                   case '+' :
                       st.push(op1 + op2);
                       break;
                       
                   case '-' :
                       st.push(op1-op2);
                       break;
                       
                   case '*' :
                       st.push(op1 * op2);
                       break;
                       
                   case '/' :
                       st.push(op1 / op2);
                       break;
                }
           }
       }    
       return st.top();
}
int expression:: evalprefix(string s){
      Stack<int> st;
      for(int i=s.length()-1; i>=0; i--){
          if(s[i]>='0' && s[i]<='9'){
                 st.push(s[i]-'0');
           }
           else{
               int op1=st.top();
               st.pop();
               int op2=st.top();
               st.pop();
               switch(s[i]){
                   case '+' :
                       st.push(op1 + op2);
                       break;
                       
                   case '-' :
                       st.push(op1-op2);
                       break;
                       
                   case '*' :
                       st.push(op1 * op2);
                       break;
                       
                   case '/' :
                       st.push(op1 / op2);
                       break;
                }
           }
       }    
       return st.top();
}                                
                             
int main(){
    expression e;
    string s;
    int ch;
    while(ch!=5){
    cout<<endl;
    cout<<"--Menu--"<<endl;
    cout<<"Enter 1 for infix to postfix"<<endl;
    cout<<"Enter 2 for infix to prefix"<<endl;
    cout<<"Enter 3 for postfix evaluation"<<endl;
    cout<<"Enter 4 for prefix evaluation"<<endl;
    cout<<"Enter 5 for exit "<<endl;
    cout<<"Enter your choice : ";
    cin>>ch;
    switch(ch){
        case 1:
          cout<<"Enter string: ";
          cin>>s;
          cout<<endl;
          cout<<"Result : "<<e.intopost(s)<<endl;
          break;
         
       case 2:
          cout<<"Enter string: ";
          cin>>s;
          cout<<endl;
          cout<<"Result : "<<e.intopre(s)<<endl;
          break;
         
       case 3:
          cout<<"Enter string: ";
          cin>>s;
          cout<<endl;
          cout<<"Result : "<<e.evalpostfix(s)<<endl;
          break;
         
       case 4:
          cout<<"Enter string: ";
          cin>>s;
          cout<<endl;
          cout<<"Result : "<<e.evalprefix(s)<<endl;
          break;  
     }
     }          
}



