#include <iostream>

#include "documentary.h"
#include "memtrace.h"




/// ostreamre listazza az adatokat
/// \param os kiiras celja
void Documentary::listAttributes(std::ostream &os) {
    os <<"Documentary\t";
    Film::listAttributes(os);
    os << description << std::endl;
}

void Documentary::serialize(std::iostream &fs) {
    listAttributes(fs);
}

void Documentary::deserialize(std::iostream &fs) {
    Film::deserialize(fs);
    (fs >> description).ignore(1);
}

bool Documentary::operator==(const Documentary &other) const {
    return Film::operator==(other) && description == other.description;
}

bool Documentary::operator!=(const Documentary &other) const {
    return !(*this == other);
}

