
#ifndef NHF_FILEHANDLER_H
#define NHF_FILEHANDLER_H


#include <fstream>
#include <string>

class fileHandler {
private:
    std::ifstream file;
public:
    fileHandler();

    std::ifstream openFile(const std::string& fileName);

    std::string readLine();

    void closeFile();

    ~fileHandler();
};
#endif //NHF_FILEHANDLER_H
