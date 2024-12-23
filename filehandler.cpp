
#include <string>
#include <sstream>

#include "filehandler.h"
#include "family.h"
#include "documentary.h"
#include "memtrace.h"




/// megnyitja a fajlt
/// \param filename file neve
void FileHandler:: openFile(const std::string& filename, bool keep) {
    if(keep) file.open(filename, std::ios::in | std::ios::out | std::ios::app);
    else file.open(filename, std::ios::in | std::ios::out | std::ios::trunc);
    if(!file.is_open()) throw "file not found";
}

/// beolvas egy sort
std::string FileHandler:: readLine() {
    std::string line;
    if (std::getline(file, line)) {
        return line;
    }
    return "";
}

/// bezarja a fajlt
void FileHandler:: closeFile() {
    if (file.is_open()) {
        file.close();
    }
}

/// filehandler dtor
FileHandler::~FileHandler() {
    closeFile();
}

Film* FileHandler::getElement() {
    std::string line = readLine();
    std::stringstream iss(line);
    std::string type;
    (iss >> type).ignore(1);
    if (type == "Documentary") {
        Film* docu = new Documentary();
        docu->deserialize(iss);
        return docu;
    } else if (type == "Family") {
        Film* fam = new Family();
        fam->deserialize(iss);
        return fam;
    }
    else if(type.empty()) return nullptr;
    closeFile();
    throw "invalid input";
}

void FileHandler::writeElement(Film *film) {
    film->serialize(file);
}



