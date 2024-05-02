#include <iostream>
#include "family.h"

//family ctor
Family::Family(std::string title, int runtime, int release, int rating) : Film(title, runtime, release), rating(rating){}

/// korhatar setter
/// \param rating   korhatar
void Family::setRating(int rating) {
    this->rating = rating;
}

/// rating getter
/// \return korhatar
int Family::getRating() {
    return rating;
}

/// ostreamre listazza az adatokat
/// \param os kiirasi cel
void Family::listAttributes(std::ostream &os) {
    os <<"Family\t" <<getTitle() << "\t" << getRuntime() << "\t" << getRelease() << "\t" << rating << std::endl;
}


