/*
Name: Li Xueqi
Number: 20301110
*/
#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <cstdio>
#include <algorithm>

struct Node {
    int val;
    Node* next;
};

class Linkedlist {
public:
    void build(Node* head);
    Node* insert(Node* head, Node* ins);
    Node* del(Node* head, int x);
    void print(Node* head);
};

#endif //LINKEDLIST_LINKEDLIST_H
