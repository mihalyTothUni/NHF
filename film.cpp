#include <iostream>
#include "film.h"
#include "memtrace.h"




/// title getter
/// \return string a film cimevel
std::string Film::getTitle() {
    return title;
}


/// ostreamre listazza az adatokat
/// \param os kiirasi cel
void Film::listAttributes(std::ostream &os) {
    os << title << "\t" << runtime << "\t" << release << "\t";
}

void Film::serialize(std::iostream & fs) {
    listAttributes(fs);
}

void Film::deserialize(std::iostream& fs) {
    (fs >> title).ignore(1);
    (fs >> runtime).ignore(1);
    (fs >> release).ignore(1);
}

bool Film::operator==(const Film &other) const {
    return title == other.title && runtime == other.runtime && release == other.release;
}

bool Film::operator!=(const Film &other) const {
    return !(*this == other);
}


