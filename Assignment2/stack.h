#include <iostream>
#ifndef stack
using namespace std;

template <class t> 
class node{
    public:
    t data;
    node<t>* next;
    //constructor
    node(){
       data=0;
       next=NULL; 
    }
};

template <class t>
class Stack{
    public:
    
    node<t> *top;
    
    int isOperator(t data);
    bool isEmpty();
    void push(t data);
    t pop();
    void display();
    t peek();
    Stack();
};
#endif