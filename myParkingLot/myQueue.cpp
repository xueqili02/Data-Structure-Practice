#include "myQueue.h"

using namespace std;

myQueue::myQueue() {
    frontNode = nullptr;
    rearNode = nullptr;
}

bool myQueue::empty() {
    return frontNode == nullptr;
}

int myQueue::size() {
    int size = 0;
    Car* temp = rearNode;
    while(temp != nullptr) {
        size++;
        temp = temp -> next;
    }
    return size;
}

Car* myQueue::front() {
    return frontNode;
}

void myQueue::push(Car* in) {
    if(size() == 0) {
        frontNode = in;
        rearNode = in;
    } else {
        in -> next = rearNode;
        rearNode = in;
    }
}

void myQueue::pop() {
    Car* temp = rearNode;
    if(temp -> next == nullptr) {
        rearNode = nullptr;
        frontNode = nullptr;
        return ;
    }
    while(temp -> next != frontNode) {
        temp = temp -> next;
    }
    delete frontNode;
    frontNode = temp;
    frontNode -> next = nullptr;
}
