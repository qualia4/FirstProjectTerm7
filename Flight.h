#ifndef FIRSTPROJECT_FLIGHT_H
#define FIRSTPROJECT_FLIGHT_H
#include "Seat.h"
#include "map"
#include "vector"
#include <sstream>


class Flight {
    string number;
    map<string, Seat> seats;
    string date;

public:

    Flight(string flightInfo){ // some data here placed
        this->date = split(flightInfo, ' ')[0];
        this->number = split(flightInfo, ' ')[1];
        int rows = stoi((split(flightInfo, ' ')[2]));
        string firstPart = split(flightInfo, ' ')[3];
        int firstPrice = stoi(split(flightInfo, ' ')[4]);
        string secondPart = split(flightInfo, ' ')[5];
        int secondPrice = stoi(split(flightInfo, ' ')[6]);
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        for(int i = 0; i < rows; i++){
            char letter = toupper(alphabet[i]);
            int firstSeat = stoi(split(firstPart, '-')[0]);
            int lastSeat = stoi(split(firstPart, '-')[1]);
            for(int i = firstSeat; i <= lastSeat; i++){
                string seatNumber = letter + to_string(i);
                Seat newSeat(firstPrice);
                seats.insert({seatNumber, newSeat});
            }
            firstSeat = stoi(split(secondPart, '-')[0]);
            lastSeat = stoi(split(secondPart, '-')[1]);
            for(int i = firstSeat; i <= lastSeat; i++){
                string seatNumber = letter + to_string(i);
                Seat newSeat(secondPrice);
                seats.insert({seatNumber, newSeat});
            }
        }
    };

    void check(){
        for(auto seat: seats){
            if(!seat.second.check()){
                cout << seat.first << " ";
            }
        }
        cout << endl;
    };

    int book(string seatName){
        return seats.at(seatName).book();
    };

    int returnTicket(string seatName){
        return seats.at(seatName).returnTicket();
    };

    string getDate(){
        return date;
    };

    string getNumber(){
        return number;
    };

    int getPrice(string seatName){
        return seats.at(seatName).getPrice();
    };

private:
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
};


#endif
