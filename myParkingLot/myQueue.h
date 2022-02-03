#ifndef MYQUEUE_MYQUEUE_H
#define MYQUEUE_MYQUEUE_H

#include <cstdio>
#include "car.h"

using namespace std;


class myQueue {
private:
    Car* frontNode;
    Car* rearNode;
public:
    myQueue();
    bool empty();
    int size();
    Car* front();
    void push(Car* in);
    void pop();
};

#endif //MYQUEUE_MYQUEUE_H
