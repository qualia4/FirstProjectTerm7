#ifndef FIRSTPROJECT_USER_H
#define FIRSTPROJECT_USER_H
#include "Ticket.h"

class User {
    string name;
    int money;
    map<int, Ticket*> tickets;

public:
    User(string name, int money = 500){
        this->name = name;
        this->money = money;
    };

    void addTicket(Ticket* ticket, int money, int ID){
        tickets.insert({ID, ticket});
        this->money -= money;
    };

    void returnTicket(int ID){
        money += tickets.at(ID)->returnTicket();
        delete tickets.at(ID);
        tickets.erase(ID);
    };

    void view(){
        for(auto ticket: tickets){
            ticket.second->printTicket();
            cout << endl;
        }
    };

    void view(int ID){
        tickets.at(ID)->printTicket();
        cout << ", name: " + name << endl;
    };

    bool checkIfExists(int ID){
        if(tickets.find(ID) != tickets.end()){
            return true;
        }
        return false;
    };

    string getName(){
        return name;
    };

    int getMoney(){
        return money;
    };
};

#endif
