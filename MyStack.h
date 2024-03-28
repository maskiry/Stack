#include <iostream>
#include <string.h>
#include "vector"
#include "MyList.h"
#include "list"

#ifndef MyStack_h
#define MyStack_h 1

class MyStack
{
private:
    int len;
    int max_len;
    std::vector<char> stack_v;
    MyList stack_my_l;
    std::list<char> stack_l;
public:
    MyStack();
    MyStack(std::string s);
    MyStack(int size);
    void push(char c);
    char pop();
    char back();
    int size();
    ~MyStack();
};


#endif