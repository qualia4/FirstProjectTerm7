#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
using namespace std;
int ID = 1;

vector<string> split(const string line, char delim);

int main(){
    vector<Flight*> flights;
    map<string, User*> users;
    ifstream myFile;
    myFile.open("flights.txt");
    string line;
    getline(myFile, line);
    int length = stoi(line);
    for(int i = 0; i < length; i++){
        getline(myFile, line);
        cout << line << endl;
        Flight *flight = new Flight(line);
        flights.push_back(flight);
    }
    string command;
    string entered;
    while(true) {
        cout << "Enter command: ";
        getline(cin, entered);
        vector<string> parametrs = split(entered, ' ');
        command = parametrs[0];
        if(command == "stop"){
            break;
        }
        else if(command == "check"){
            string date = parametrs[1];
            string flightNum = parametrs[2];
            for(int i = 0; i < flights.size(); i++){
                if(flights[i]->getDate() == date && flights[i]->getNumber() == flightNum){
                    flights[i]->check();
                    break;
                }
            }
        }
        else if(command == "book"){
            for(int i = 0; i < flights.size(); i++){
                string date = parametrs[1];
                string flightNum = parametrs[2];
                string seatName = parametrs[3];
                string userName = parametrs[4];
                if(flights[i]->getDate() == date && flights[i]->getNumber() == flightNum){
                    int money = flights[i]->book(seatName);
                    Ticket* ticket = new Ticket(flights[i], seatName);
                    if(users.find(userName) != users.end()){
                        users.at(userName)->addTicket(ticket, money, ID);
                        ID++;
                    }
                    else{
                        User* user = new User(userName);
                        users.insert({userName, user});
                        users.at(userName)->addTicket(ticket, money, ID);
                        ID++;
                    }
                    cout << "Your ticket booked with ID: " << ID - 1 << endl;
                }
            }
        }
        else if(command == "return"){
            int ticketID = stoi(parametrs[1]);
            for(auto user: users){
                if(user.second->checkIfExists(ticketID)){
                    user.second->returnTicket(ticketID);
                    break;
                }
            }
        }
        else if(command == "viewID"){
            int ticketID = stoi(parametrs[1]);
            for(auto user: users){
                if(user.second->checkIfExists(ticketID)){
                    user.second->view(ticketID);
                    break;
                }
            }
        }
        else if (command == "view"){
            string name = parametrs[1];
            users.at(name)->view();
        }
    }
    for(int i = 0; i < flights.size(); i++){
        delete flights[i];
    }
    for(auto user: users){
        delete user.second;
    }
}

vector<string> split(const string line, char delim) {
    vector<string> result;
    string part = "";
    for(int i = 0; i < line.length(); i++){
        if(line[i] != delim && line.length() - 1 != i){
            part += line[i];
        }
        else if(line.length() - 1 == i){
            part += line[i];
            result.push_back(part);
        }
        else{
            result.push_back(part);
            part = "";
        }
    }
    return result;
};
