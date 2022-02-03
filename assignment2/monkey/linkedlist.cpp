/*
Name: Li Xueqi
Number: 20301110
*/
#include <cstdio>
#include <algorithm>
#include "linkedlist.h"

using namespace std;

void Linkedlist:: build(Node* head) {
    head -> val = 1;
    Node* temp = head;
    for(int i = 1; i < 10; i++) {
        Node* data = new Node();
        data -> val = i + 1;
        temp -> next = data;
        temp = data;
    }
    temp -> next = head;
}

Node* Linkedlist:: del(Node* head, int x) {
    Node* temp = head;
    Node* pre = temp;
    if(head -> val == x) {
        head = head -> next;
        delete temp;
        return head;
    }
    while(temp != NULL) {
        if(temp -> val == x) {
            Node* del = temp;
            pre -> next = temp -> next;
            delete del;
            return head;
        }
        pre = temp;
        temp = temp -> next;
    }
    printf("Node does not exist.\n");
    return head;
}

Node* Linkedlist:: insert(Node* head, Node* ins) {
    Node* temp = head;
    Node* pre = temp;
    if(ins -> val <= head -> val) {
        ins -> next = head;
        return ins;
    }
    while(temp != NULL) {
        if(ins -> val <= temp -> val && ins -> val >= pre -> val) {
            ins -> next = temp;
            pre -> next = ins;
            return head;
            break;
        }
        pre = temp;
        temp = temp -> next;
    }
    pre -> next = ins;
    return head;
}

void Linkedlist:: print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp -> val);
        temp = temp -> next;
    }
    printf("\n");
}
