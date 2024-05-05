
#include <fstream>
#include <string>
#include <sstream>

#include "filehandler.h"
#include "family.h"
#include "documentary.h"

/// filehandler ctor
FileHandler::FileHandler() {}

/// megnyitja a fajlt
void FileHandler:: openFile(const std::string& filename) {
    file.open(filename);
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

void FileHandler::import(std::string filename) {
    openFile(filename);
    std::string line;
    while (!(line = readLine()).empty()) {
        std::istringstream iss(line);
        std::string title;
        int runtime;
        int release;
        std::string type;
        std::string description;
        int rating;

        iss >> type >> title >> runtime >> release;

        if (type == "Documentary") {
            iss >> description;
            db->add(new Documentary(title, runtime, release, description));
        } else if (type == "Family") {
            iss >> rating;
            db->add(new Family(title, runtime, release, rating));
        }
    }
    closeFile();

}

Database &FileHandler::senddb() {
    return *db;
}

void FileHandler::receiveDb(Database &other) {
    db = &other;

}


void FileHandler::exportdb(std::string filename) {
    openFile(filename);
    db->listAll(file);
    closeFile();
}
