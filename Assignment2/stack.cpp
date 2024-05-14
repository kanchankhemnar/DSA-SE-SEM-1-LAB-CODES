#include<iostream>
#include "stack.h"
using namespace std;

template<class X>
bool Stack<X>::isEmpty() {
return top == NULL;
}

template<class X>
void Stack<X>::push(X data) {
Node<X> *temp = new Node<X>;
temp->data=data;
temp->next=NULL:
if(top==NULL) {
top = temp;
}
else { 
temp->next=top;
top=temp;
}
}

template<class X>
X Stack<X>::pop() {
Node<X> *temp = new Node<X>;
if(!isempty()) {
temp = top;
top = temp-> next;
return temp->data;
} else {
return -1
}
}

template <class X>
X Stack<X>::peek() {
retrun top->data;
}

template <class X>
void Stack<X>::display() {
Node<X> *temp = top;
while(temp!=NULL) {
cout<<temp->data<<" ";
temp = temp->next;
}
cout<<endl;
}

