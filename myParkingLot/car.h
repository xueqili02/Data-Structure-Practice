#ifndef MYQUEUE_CAR_H
#define MYQUEUE_CAR_H

#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

struct Car {
    int inTime, outTime, totalTime, parkingID;
    double charge;
    string plate;
    Car* next;
};

#endif //MYQUEUE_CAR_H
