#ifndef MYQUEUE_PARKING_H
#define MYQUEUE_PARKING_H

#include <cstdlib>
#include <ctime>
#include "myQueue.h"

using namespace std;

struct parkingSpace {
    int id{};
    bool park = false;
    Car* car{};
};

class parking {
private:
    int emptyNum;
    double price = 1.5;
public:
    parkingSpace p[11];
    parking();
    void park(int inTime, int id);
    bool out(int currentTime, int id);
    void setNum(int num);
    int getNum();
    bool full();
    string rand_plate();
};

#endif //MYQUEUE_PARKING_H
