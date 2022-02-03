#ifndef STACK_MYSTACK_H
#define STACK_MYSTACK_H

#include <cstdio>

using namespace std;

template <typename T>
struct Node {
    T val;
    Node* next;
};

template <typename T>
class myStack {
private:
    Node<T>* topNode;
public:
    myStack();
    void push(T x);
    void pop();
    bool isEmpty();
    T top();
    int size();
};

#endif //STACK_MYSTACK_H
