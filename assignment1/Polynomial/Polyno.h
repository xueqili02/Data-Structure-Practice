#ifndef POLYNOMIAL_POLYNO_H
#define POLYNOMIAL_POLYNO_H
#include <cstdio>

struct Node {
    int co, exp;
    Node* next;
};

class Polyno {
public:
    void build(FILE *file, Node *head);
    void input(Node *first, Node *second);
    void print(Node *head, int &cnt);
    void add(Node *first, Node *second, Node *ans);
    void multiply(Node *first, Node *second, Node *ans);
    void output(Node *ans1, Node *ans2, int cnt1, int cnt2);
};

#endif //POLYNOMIAL_POLYNO_H
