///film absztrakt osztaly
#ifndef NHF_FILM_H
#define NHF_FILM_H

#include <string>
#include <utility>

class Film{
    std::string title;  //cim
    int runtime;        //jatekido
    int release;        //kiadas eve
public:
    /// Film ctor
    /// \param title film cime
    /// \param runtime jatekido
    /// \param release kiadas eve
    Film(std::string title, int runtime, int release) :title(std::move(title)), runtime(runtime), release(release) {}

    ///default ctor
    Film(): runtime(0), release(0) {}

    /// title getter
    /// \return string a film cimevel
    std::string getTitle();

    /// ostreamre listazza az adatokat
    /// \param os kiirasi cel
    virtual void listAttributes(std::ostream& os);

    /// fajlba iras
    /// \param fs filestream
    virtual void serialize(std::iostream & fs);

    /// fajlbol olvasas
    /// \param fs filestream
    virtual void deserialize(std::iostream & fs);

    ///operator==
    /// \param other masik film
    /// \return egyenloseg
    bool operator==(const Film& other) const;

    ///operator!=
    /// \param other masik film
    /// \return egyenlotlenseg
    bool operator!=(const Film& other) const;

    ///virtual dtor
    virtual ~Film() = default;
};

#endif //NHF_FILM_H
