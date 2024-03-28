#include <string.h>
#include "iostream"

#ifndef MyList_h
#define MyList_h 1

class MyList;

struct Node{
    friend MyList;
    private:
        Node* const head;
        Node* next;
        Node* prev;
        void* operator new(std::size_t size) {return ::operator new(size);}
        void operator delete(void* ptr) {::operator delete(ptr);}
        void* operator new[](std::size_t size) {return ::operator new[](size);}
        void operator delete[](void* ptr) {::operator delete[](ptr);}
    public:
        char symbol;
        Node(char c, Node* const n): symbol(c), next(nullptr), prev(nullptr), head(n){};
        Node* get_next() const{
            if (next->next==nullptr) return nullptr;
            return next;
        };
        Node* get_prev() const{
            if (prev->prev==nullptr) return nullptr;
            return prev;
        };
};

class MyList
{
private:
    Node* head;
    Node* tail;
    unsigned int len;
public:
    MyList();
    MyList(const MyList& other);
    MyList(MyList&& other);
    MyList(std::string input_s);
    MyList& operator = (std::string input_s){
        clear();
        int i=0;
        while (len<input_s.size())
        {
            push_back(input_s[i]);
            i++;
        }
        return *this;
    };
    MyList& operator = (const MyList& other){
        if (this!=&other){
            clear();
            Node* iter=other.begin();
            int i=0;
            while (i<other.size()){
                push_back(iter->symbol);
                iter=iter->get_next();
                i++;
            }
        }
        return *this;
    }
    MyList& operator = (MyList&& other){
        if (this!=&other){
            head=other.head;
            other.head=nullptr;
            tail=other.tail;
            other.tail=nullptr;
            other.len=0;
            len=other.len;
        }
        return *this;
    }
    void push_back(char c);
    void push_front(char c);
    void push_next(Node* ptr, char c);
    void push_prev(Node* ptr, char c);
    void pop_back();
    void pop_front();
    void pop_next(Node* ptr);
    void pop_prev(Node* ptr);
    void erase(Node* ptr);
    void clear();
    Node* begin() const;
    Node* end() const;
    int size() const;
    ~MyList();
};



#endif