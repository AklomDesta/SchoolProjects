//#include <utility>

//#include <utility>

//#include <utility>

//#include <utility>

//#include <utility>

//#include <utility>

//#include <utility>

//
// Created by chu on 11/12/2018.
//

#include "Actor.h"

Actor::Actor()
{
}


Actor::~Actor()
{
}

Actor::Actor(unsigned int id,string award, string year, string winner, string name, string film) {

    ID= id;
    Year = std::move(award);
    Award = std::move(year);
    Winner = std::move(winner);
    Name = std::move(name);
    Film = std::move(film);
}


unsigned int Actor::getID() const {
    return ID;
}
string Actor::getAward() const{
    return Award;
}
string Actor::getYear() const{
    return Year;
}
string Actor::getWinner() const{
    return Winner;
}

string Actor::getName() const{
    return Name;
}

string Actor::getFilm()const {
    return Film;
}



void Actor::setID(unsigned int id) {
    ID=id;
}
void Actor::setYear(string year) {
    Year = std::move(year);
}

void Actor::setAward(string award) {
    Award = std::move(award);
}

void Actor::setWinner(string winner) {
    Winner = std::move(winner);
}

void Actor::setName(string name) {
    Name = std::move(name);
}

void Actor::setFilm(string film) {
    Film = std::move(film);
}









