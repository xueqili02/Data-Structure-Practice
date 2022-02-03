#include "parking.h"

using namespace std;

parking::parking() {
    emptyNum = 10;
    srand((unsigned int)time(NULL));
    for(int i = 1; i <= emptyNum; i++) {
        p[i].id = i;
        p[i].park = false;
    }
}

string parking::rand_plate() {
    string str, pre = "京";
    char c;
    c = 'A' + rand() % 26;
    pre += c;
    pre += "·";
    for(int i = 0; i < 5; i++) {
        c = 'A' + rand() % 26;
        if(c == 'O' || c == 'I') c = 'B';
        str.push_back(c);
    }
    for(int i = 0; i < 3; i++) {
        int temp = rand() % 9 + 1;
        int pos = rand() % 5;
        str[pos] = '0' + temp - 1;
    }
    return pre + str;
}

void parking::park(int inTime, int id) {
    if(!p[id].park) {
        p[id].park = true;
        emptyNum--;
        p[id].car = new Car();
        p[id].car -> plate = rand_plate();
        p[id].car-> parkingID = id;
        p[id].car -> inTime = inTime;
        p[id].car -> totalTime = rand() % 31 + 14;
    }
}

bool parking::out(int currentTime, int id) {
    if(p[id].park && currentTime - p[id].car -> inTime == p[id].car -> totalTime) {
        p[id].park = false;
        emptyNum++;
        p[id].car -> charge = (p[id].car -> totalTime / 15) * price;
        p[id].car -> outTime = p[id].car -> inTime + p[id].car -> totalTime;
        return true;
    }
    else {
        return false;
    }
}

void parking::setNum(int num) {
    emptyNum = num;
}

int parking::getNum() {
    return emptyNum;
}

bool parking::full() {
    return emptyNum == 0;
}
