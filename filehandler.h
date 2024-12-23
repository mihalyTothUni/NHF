
#ifndef NHF_FILEHANDLER_H
#define NHF_FILEHANDLER_H


#include <fstream>
#include <string>
#include "film.h"

class FileHandler {
private:
    std::fstream file;
public:

    /// megnyitja a fajlt
    /// \param filename file neve
    void openFile(const std::string& filename, bool keep = false);

    /// beolvas egy sort
    /// \return string a beolvasott sor
    std::string readLine();

    /// bezarja a fajlt
    void closeFile();

    /// visszaadja a kovetkezo film objektumot
    /// \return Film* film objektum
    Film* getElement();

    /// kiir egy film objektumot a fajlba
    /// \param film film objektum
    void writeElement(Film* film);

    /// filehandler dtor
    ~FileHandler();
};
#endif //NHF_FILEHANDLER_H
