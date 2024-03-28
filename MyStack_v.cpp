#include "MyStack.h"

MyStack::MyStack():len(0){}

MyStack::MyStack(std::string s): len(s.size()), stack_v(){
    stack_v.reserve(len);
    int i=0;
    while (i<len){
        stack_v.push_back(s[i]);
        if ((s[i]=='&') || (s[i]=='|')){
            i++;
        }
        i++;
    }
}

MyStack::MyStack(int size):len(0), max_len(size){
    stack_v.reserve(max_len);
}

void MyStack::push(char c){
    if (len==max_len){
        std::cout << "overflow";
        throw "Stack overflow";
    }
    stack_v.push_back(c);
    len++;
}

char MyStack::pop(){
    if (len==0){
        std::cout << "error";
        throw "Stack is empty";
    }
    char c=stack_v[len-1];
    stack_v.pop_back();
    len--;
    return c;
}

char MyStack::back(){
    if (len==0){
        std::cout << "error";
        throw "Stack is empty";
    }
    return stack_v[len-1];
}

int MyStack::size(){
    return len;
}
