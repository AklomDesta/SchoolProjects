//
// Created by chu on 11/13/2018.
//

#ifndef DESTA_FINAL_PROJECT_BINARY_TREE_PICTURE_H
#define DESTA_FINAL_PROJECT_BINARY_TREE_PICTURE_H

#include <iostream>
using namespace std;

class Picture {
private:
    unsigned int ID;
    string Name;
    string Year;
    string Nominations;
    string Rating;
    string Duration;
    string Genre1;
    string Genre2;
    string Release;
    string Metacritic;
    string Synopsis;
public:
   Picture();
   ~Picture();
    Picture(unsigned int id,string name,string year,string nominations,string rating,string genre1,string genre2,string release,string metacritic,string synopsis);
   unsigned int getID() const;
   string getName() const;
   string getYear() const;
   string getNominations() const;
   string getRating() const;
   string getDurations() const;
   string getGenre1() const;
   string getGenre2() const;
   string getRelease() const;
   string getMetacritic() const;
   string getSynosis() const;

   void setId(unsigned int);
   void setName(string);
   void setYear(string);
   void setNominations(string);
   void setRating(string);
   void setDuration(string);
   void setGenre1(string);
   void setGEnre2(string);
   void setRelease(string);
   void setMetacritic(string);
   void setSynopsis(string);

};


#endif //DESTA_FINAL_PROJECT_BINARY_TREE_PICTURE_H
