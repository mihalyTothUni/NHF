#include <iostream>

#include "documentary.h"

//docu ctor
Documentary::Documentary(std::string title, int runtime, int release, std::string desc): Film(title, runtime, release), description(desc) {}


/// leiras setter
/// \param desc leiras
void Documentary::setDescription(std::string desc) {
    description = desc;
}

/// leiras getter
/// \return string a leirassal
std::string Documentary::getDescription() {
    return description;
}

/// ostreamre listazza az adatokat
/// \param os kiiras celja
void Documentary::listAttributes(std::ostream &os) {
    os <<"Documentary\t" <<getTitle() << "\t" << getRuntime() << "\t" << getRelease() << "\t" << description << std::endl;
}

