
#ifndef NHF_FILEHANDLER_H
#define NHF_FILEHANDLER_H


#include <fstream>
#include <string>
#include "database.h"

class FileHandler {
private:
    Database *db;
    std::fstream file;
public:
    FileHandler();

    void openFile(const std::string& filename);

    std::string readLine();

    void closeFile();

    void import(std::string filename);

    Database& senddb();

    void receiveDb(Database& other);

    void exportdb(std::string filename);

    ~FileHandler();
};
#endif //NHF_FILEHANDLER_H
