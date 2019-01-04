#include <utility>

#include <utility>

#include <utility>

#include <utility>

#include <utility>

#include <utility>

#include <utility>

#include <utility>

#include <utility>

#include <utility>

#include <utility>

#include <utility>

//
// Created by chu on 11/13/2018.
//

#include "Picture.h"

Picture::Picture() {

}

Picture::~Picture() {

}
Picture::Picture(unsigned int id,string name,string year,string nominations,string rating,string genre1,string genre2,string release,string metacritic,string synopsis) {

    ID=id;
    Year= std::move(year);
    Name= std::move(name);
    Nominations= std::move(nominations);
    Rating= std::move(rating);
    Genre1= std::move(genre1);
    Genre2= std::move(genre2);
    Release= std::move(release);
    Metacritic= std::move(metacritic);
    Synopsis= std::move(synopsis);

}

unsigned int Picture::getID() const {
    return ID;
}

string Picture::getName() const {
    return Name;
}

string Picture::getYear() const {
    return Year;
}

string Picture::getNominations() const {
    return Nominations;
}

string Picture::getRating() const {
    return Rating;
}

string Picture::getDurations() const {
    return Duration;
}

string Picture::getGenre1() const {
    return Genre1;
}

string Picture::getGenre2() const {
    return  Genre2;
}

string Picture::getRelease() const {
    return Release;
}

string Picture::getMetacritic() const {
    return Metacritic;
}

string Picture::getSynosis() const {
    return Synopsis;
}

void Picture::setId(unsigned int id) {
    ID=id;
}

void Picture::setName(string name) {
    Name= std::move(name);
}

void Picture::setYear(string year)  {
    Year= std::move(year);
}

void Picture::setNominations(string nominations) {
    Nominations= std::move(nominations);
}

void Picture::setRating(string rating) {
    Rating= std::move(rating);
}

void Picture::setDuration(string duration) {
    Duration= std::move(duration);
}

void Picture::setGenre1(string genre1) {
    Genre1= std::move(genre1);
}

void Picture::setGEnre2(string genre2) {
    Genre2= std::move(genre2);
}

void Picture::setRelease(string release) {
    Release= std::move(release);
}

void Picture::setMetacritic(string metacritic) {
    Metacritic= std::move(metacritic);
}

void Picture::setSynopsis(string synopsis) {
    Synopsis= std::move(synopsis);
}
