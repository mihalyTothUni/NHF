#include <iostream>
#include "family.h"
#include "memtrace.h"




/// ostreamre listazza az adatokat
/// \param os kiirasi cel
void Family::listAttributes(std::ostream &os) {
    os <<"Family\t";
    Film::listAttributes(os);
    os  << rating << std::endl;
}

void Family::serialize(std::iostream& fs) {
    listAttributes(fs);
}

void Family::deserialize(std::iostream& fs) {
    Film::deserialize(fs);
    (fs >> rating).ignore(1);
}

bool Family::operator==(const Family &other) const {
    return Film::operator==(other) && rating == other.rating;
}

bool Family::operator!=(const Family &other) const {
    return !(*this == other);
}


