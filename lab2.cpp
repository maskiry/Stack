#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )

#include "iostream"
#include <string>
#include <stdio.h>
#include <fstream>
#include "MyStack.h"

int calc_expr(std::string s){
    if (s.size()==0){
        std::cout << "error; empty string; return ";
        return -1;
    }
    MyStack operands;
    MyStack operations;
    unsigned int n_op=0, i=0;
    while (i<s.size()){
        if ((s[i]=='!') || (s[i]=='&') || (s[i]=='|')){
            operations.push(s[i]);
            if (s[i]!='!') n_op=0;
        }
        else if ((s[i]=='1') || (s[i]=='0')) {
            operands.push(s[i]);
            n_op++;
            while (operations.size()>0 && operations.back()=='!'){
                char n = operands.pop();
                operations.pop();
                operands.push((n -'0'+1)%2+'0');
            }
            if (n_op==2 && operations.size()>0){
                char n1=operands.pop();
                char n2=operands.pop();
                char op=operations.pop();
                if (op=='&'){
                    operands.push((n1-'0')*(n2-'0')+'0');
                }
                else if (op=='|'){
                    operands.push(((n1-'0'+n2-'0')!=0)+'0');
                }
                else {
                    std::cout << "unexpected symbol\n";
                    return -1;
                }
                n_op=1;
            }
            else if (n_op>2){
                std::cout << "error; ";
                return -1;
            }
        }
        else {
            std::cout << "unexpected symbol\n";
            return -1;
        }
        i++;
    }

    return operands.pop()=='1';
}

int main(){
    std::string s;
    std::ifstream in("input2.txt");
    while (!in.eof()){
        std::getline(in, s);
        std::cout << "input string: " << "\"" << s << "\"" << "\n";
        std::cout << "output string: " << "\"" << calc_expr(s) << "\"" << "\n\n";
    }
    
    in.close();


    _CrtDumpMemoryLeaks();
    return 0;
}