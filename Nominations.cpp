//
// Created by chu on 11/21/2018.
//

#include "Nominations.h"
Nominations::Nominations()
{
}


Nominations::~Nominations()
{
}

Nominations::Nominations(unsigned int id,string award, string year, string winner, string name, string film) {

    ID= id;
    Year = std::move(award);
    Award = std::move(year);
    Winner = std::move(winner);
    Name = std::move(name);
    Film = std::move(film);
}


unsigned int Nominations::getID() const {
    return ID;
}
string Nominations::getAward() const{
    return Award;
}
string Nominations::getYear() const{
    return Year;
}
string Nominations::getWinner() const{
    return Winner;
}

string Nominations::getName() const{
    return Name;
}

string Nominations::getFilm()const {
    return Film;
}



void Nominations::setID(unsigned int id) {
    ID=id;
}
void Nominations::setYear(string year) {
    Year = std::move(year);
}

void Nominations::setAward(string award) {
    Award = std::move(award);
}

void Nominations::setWinner(string winner) {
    Winner = std::move(winner);
}

void Nominations::setName(string name) {
    Name = std::move(name);
}

void Nominations::setFilm(string film) {
    Film = std::move(film);
}