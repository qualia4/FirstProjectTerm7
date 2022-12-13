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
        cout << this->money << endl;
        if(this->money<0){
            throw invalid_argument("No Money");
        }
    };

    void returnTicket(int ID){
        int returnedMoney = tickets.at(ID)->returnTicket();
        money += returnedMoney;
        delete tickets.at(ID);
        tickets.erase(ID);
        cout << ID << " ticket successfully returned! "<< returnedMoney << "$ returned to " << name << endl;
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
