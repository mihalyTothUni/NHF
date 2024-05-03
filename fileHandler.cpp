
#include <fstream>
#include <string>

#include "fileHandler.h"

/// filehandler ctor
fileHandler::fileHandler() {}

/// megnyitja a fajlt
std::ifstream fileHandler:: openFile(const std::string& fileName) {
    #TODO
    ///itt ennek a szarnak tudnia kéne hogy mi a faszom a file és beállítani a file változót d nem tudja mert egy kretén
    std::ifstream file(fileName);
    if(!file.is_open()) throw "file not found";
    return file;
}

/// beolvas egy sort
std::string fileHandler:: readLine() {
    std::string line;
    if (std::getline(file, line)) {
        return line;
    }
    return "";
}

/// bezarja a fajlt
void fileHandler:: closeFile() {
    if (file.is_open()) {
        file.close();
    }
}

/// filehandler dtor
fileHandler::~fileHandler() {
    closeFile();
}
