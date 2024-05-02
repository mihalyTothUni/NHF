#include <iostream>
#include "film.h"

/// film ctor
Film::Film(std::string title, int runtime, int release) :title(title), runtime(runtime), release(release) {}


/// title getter
/// \return string a film cimevel
std::string Film::getTitle() {
    return title;
}

/// runtime getter
/// \return jatekido
int Film::getRuntime() {
    return runtime;
}

/// title setter
/// \param title film cime
void Film::setTitle(int title) {
    Film::title = title;
}

/// runtime setter
/// \param runtime jatekido
void Film::setRuntime(int runtime) {
    Film::runtime = runtime;
}

/// ostreamre listazza az adatokat
/// \param os kiirasi cel
void Film::listAttributes(std::ostream &os) {
    os << title << "\t" << runtime << "\t" << release << std::endl;
}

int Film::getRelease() {
    return release;
}

