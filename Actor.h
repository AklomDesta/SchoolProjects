//
// Created by chu on 11/12/2018.
//

#ifndef DESTA_FINAL_PROJECT_BINARY_TREE_ACTOR_H
#define DESTA_FINAL_PROJECT_BINARY_TREE_ACTOR_H

#include <iostream>
using namespace std;

class Actor {
private:           // Variables declaration
    unsigned int ID;
    string Year;
    string Award;
    string Winner;
    string Name;
    string Film;
public:
    Actor();    // Constructor
    ~Actor();  // Destructor
    Actor(unsigned int id, string award, string year, string winner, string name, string film);

    unsigned int getID() const ;
    string getYear()  const;
    string getAward()  const;
    string getWinner()  const;
    string getName() const;
    string getFilm()  const;

    void setID(unsigned int);
    void setYear(string );
    void setAward(string );
    void setWinner(string );
    void setName(string);
    void setFilm(string);

};


#endif //DESTA_FINAL_PROJECT_BINARY_TREE_ACTOR_H
