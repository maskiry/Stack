#include "MyStack.h"

MyStack::MyStack():len(0), max_len(10){}

MyStack::MyStack(std::string s): len(s.size()), max_len(s.size()), stack_l(){
    int i=0;
    while (i<len){
        stack_l.push_back(s[i]);
        if ((s[i]=='&') || (s[i]=='|')){
            i++;
        }
        i++;
    }
}

MyStack::MyStack(int size):len(0), max_len(size){}

MyStack::~MyStack(){}

void MyStack::push(char c){
    stack_l.push_back(c);
    len++;
}

char MyStack::pop(){
    if (len==0){
        std::cout << "error";
        throw "Stack is empty";
    }
    char c=stack_l.back();
    stack_l.pop_back();
    len--;
    return c;
}

char MyStack::back(){
    if (len==0){
        std::cout << "error";
        throw "Stack is empty";
    }
    return stack_l.back();
}

int MyStack::size(){
    return len;
}