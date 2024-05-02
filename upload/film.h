///film absztrakt osztaly

#include <string>

#ifndef NHF_FILM_H
#define NHF_FILM_H

class Film{
    std::string title;  //cim
    int runtime;        //jatekido
    int release;        //kiadas eve
public:
    /// Film ctor
    /// \param title film cime
    /// \param runtime jatekido
    /// \param release kiadas eve
    Film(std::string title, int runtime, int release);

    ///film dtor
    ~Film() = default;

    /// title getter
    /// \return string a film cimevel
    std::string getTitle();

    /// runtime getter
    /// \return jatekido
    int getRuntime();

    ///release getter
    /// \return kiadas eve
    int getRelease();

    /// title setter
    /// \param title film cime
    void setTitle(int title);

    /// runtime setter
    /// \param runtime jatekido
    void setRuntime(int runtime);

    /// ostreamre listazza az adatokat
    /// \param os kiirasi cel
    virtual void listAttributes(std::ostream& os);
};

#endif //NHF_FILM_H
