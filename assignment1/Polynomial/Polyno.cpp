/*
Name: Li Xueqi
Number: 20301110
*/
#include "Polyno.h"
#include <cstdio>
#include <algorithm>
using namespace std;

void Polyno::build(FILE *file, Node *head) {
    int a, n, co, exp;
    fscanf(file, "%d", &a);
    n = a;

    fscanf(file, "%d", &a);
    head->co = a;
    fscanf(file, "%d", &a);
    head->exp = a;

    Node *data = head;
    Node *temp;
    for (int i = 1; i <= n - 1; i++) {
        temp = data;
        data = new Node();
        fscanf(file, "%d", &a);
        data->co = a;
        fscanf(file, "%d", &a);
        data->exp = a;
        temp->next = data;
    }
}

void Polyno::input(Node *first, Node *second) {
    FILE *file;
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("File does not exist.\n");
        return;
    }
    build(file, first);
    build(file, second);
    fclose(file);
}

void Polyno::print(Node *head, int &cnt) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->co != 0) {
            printf("%d %d\n", temp->co, temp->exp);
            cnt++;
        }
        temp = temp->next;
    }

}

void Polyno::add(Node *first, Node *second, Node *ans) {
    Node *f = first;
    Node *s = second;

    while (f != NULL) {
        Node *mid = new Node();
        mid->co = f->co;
        mid->exp = f->exp;
        s = second;
        while (s != NULL) {
            if (f->exp == s->exp) {
                mid->co = f->co + s->co;
                mid->exp = f->exp;
                break;
            }
            s = s->next;
        }

        Node *temp = ans;
        Node *ne = temp->next;
        while (temp != NULL) {
            if (mid->exp <= temp->exp && mid->exp >= ne->exp) {
                mid->next = temp->next;
                temp->next = mid;
                break;
            }
            temp = temp->next;
            ne = temp->next;
        }
        f = f->next;
    }
    ans = ans->next;

    s = second;
    while (s != NULL) {
        Node *insert = new Node();
        insert->exp = s->exp;
        insert->co = s->co;
        Node *temp = ans;
        Node *ne = temp->next;
        while (temp != NULL) {
            if (insert->exp == ne->exp || insert->exp == temp->exp) break;
            if (insert->exp < temp->exp && insert->exp > ne->exp) {
                insert->next = temp->next;
                temp->next = insert;
                break;
            }
            temp = temp->next;
            ne = temp->next;
        }
        s = s->next;
    }
}

void Polyno::multiply(Node *first, Node *second, Node *ans) {
    Node *f = first;
    Node *s = second;
    Node *term = new Node();
    Node *i = term;
    while (f != NULL) {
        s = second;
        while (s != NULL) {
            Node *temp = new Node();
            temp->co = f->co * s->co;
            temp->exp = f->exp + s->exp;
            bool flag = false;
            Node *j = term;
            while (j != NULL) {
                if (j->exp == temp->exp) {
                    flag = true;
                    j->co += temp->co;
                    break;
                }
                j = j->next;
            }
            if (!flag) {
                i->next = temp;
                i = temp;
            }
            s = s->next;
        }
        f = f->next;
    }
    Node *temp = new Node();
    temp->co = 0;
    temp->exp = 0;
    add(term, temp, ans);
}

void Polyno::output(Node *ans1, Node *ans2, int cnt1, int cnt2) {
    FILE *file;
    file = fopen("answer.txt", "w");
    if (file == NULL) {
        printf("File does not exist.\n");
        return;
    }
    Node *temp = ans1;
    fprintf(file, "%d ", cnt1);
    while (temp != NULL) {
        if (temp->co != 0) {
            fprintf(file, "%d %d ", temp->co, temp->exp);
        }
        temp = temp->next;
    }
    fprintf(file, "\n%d ", cnt2);
    temp = ans2;
    while (temp != NULL) {
        if (temp->co != 0) {
            fprintf(file, "%d %d ", temp->co, temp->exp);
        }
        temp = temp->next;
    }
    fclose(file);
}
