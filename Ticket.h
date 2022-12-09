#ifndef FIRSTPROJECT_TICKET_H
#define FIRSTPROJECT_TICKET_H
#include "Flight.h"

class Ticket {
    Flight* flight;
    string seatName;

public:
    Ticket(Flight* flight, string seatName){
        this->flight = flight;
        this->seatName = seatName;
    }
    int returnTicket(){
        return flight->returnTicket(seatName);
    }
    void printTicket(){
        cout << "Flight: " + flight->getNumber() + ", date: " + flight->getDate() + ", seat: "+ seatName
                + ", price: " + to_string(flight->getPrice(seatName));
    }
};


#endif
