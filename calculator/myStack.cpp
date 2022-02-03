/*
Name: Li Xueqi
Number: 20301110
*/
#include <cstdio>
#include "myStack.h"

using namespace std; 

template class myStack<int>;  
template class myStack<double>;  
template class myStack<char>;

template <typename T>
myStack<T>:: myStack() {
    topNode = NULL;
}

template <typename T>
void myStack<T>:: push(T x) {
    auto* temp = new Node<T>();
    if(!temp) {
        printf("Memory overflow\n");
        return ;
    }
    temp -> val = x;
    temp -> next = topNode;
    topNode = temp;
}

template <typename T>
void myStack<T>:: pop() {
    if(isEmpty()) {
//        printf("Stack underflow\n");
        return ;
    }
    auto* temp = topNode;
    topNode = topNode -> next;
    delete temp;
}

template <typename T>
bool myStack<T>:: isEmpty() {
    return topNode == NULL;
}

template <typename T>
T myStack<T>:: top() {
    if(topNode != NULL) {
        return topNode -> val;
    } else {
//        printf("Stack is empty\n");
        return NULL;
    }
}

template <typename T>
int myStack<T>:: size() {
    int size = 0;
    Node<T>* temp = topNode;
    while(temp != NULL) {
        size++;
        temp = temp -> next;
    }
    return size;
}
