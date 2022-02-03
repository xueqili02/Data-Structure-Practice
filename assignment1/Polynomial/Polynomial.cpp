/*
Name: Li Xueqi
Number: 20301110
*/

#include <cstdio>
#include <algorithm>
#include "Polyno.h"
using namespace std;

int main() {
    Polyno p;
    Node* first = new Node();
    Node* second = new Node();
    p.input(first, second);
    int cnt1 = 0;
    Node* ans_addition = new Node();
    ans_addition -> co = 0;
    ans_addition -> exp = max(first -> exp, second -> exp);
    Node* tail = new Node();
    tail -> co = 0;
    tail -> exp = -1e9 - 7;
    ans_addition -> next = tail;

    int cnt2 = 0;
    Node* ans_multiplication = new Node();
    ans_multiplication -> co = 0;
    ans_multiplication -> exp = first -> exp + second -> exp;
    ans_multiplication -> next = tail;

    //addition
    p.add(first, second, ans_addition);
    p.print(ans_addition, cnt1);
    printf("\n");

    //multiplication
    p.multiply(first, second, ans_multiplication);
    p.print(ans_multiplication, cnt2);
    p.output(ans_addition, ans_multiplication, cnt1, cnt2);
    return 0;
}