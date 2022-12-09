using namespace std;
#include "string"
#include <iostream>
#ifndef FIRSTPROJECT_SEAT_H
#define FIRSTPROJECT_SEAT_H


class Seat {
    bool booked;
    int price;

public:
    Seat(int price){
        this->price = price;
        booked = false;
    };
    int book(){
        booked = true;
        return price;
    };
    bool check(){
        return booked;
    };
    int returnTicket(){
        booked = false;
        return price;
    };
    int getPrice(){
        return price;
    };
};


#endif
