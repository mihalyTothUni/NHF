///csaladi film
#ifndef NHF_FAMILY_H
#define NHF_FAMILY_H

#include <utility>
#include "film.h"

class Family: public Film{
    int rating;    //korhatar
public:
    /// Family ctor
    /// \param title    cim
    /// \param runtime  jatekido
    /// \param release  kidas eve
    /// \param rating   korhatar
    Family(std::string title, int runtime, int release, int rating) : Film(std::move(title), runtime, release), rating(rating){}

    ///default ctor
    Family(): Film(), rating(0) {}

    /// ostreamre listazza az adatokat
    /// \param os kiirasi cel
    void listAttributes(std::ostream &os) override;

    /// fajlba iras
    /// \param fs filestream
    void serialize(std::iostream& fs) override;

    /// fajlbol olvasas
    /// \param fs filestream
    void deserialize(std::iostream& fs) override;

    ///operator==
    /// \param other masik film
    /// \return egyenloseg
    bool operator==(const Family& other) const;

    ///operator!=
    /// \param other masik film
    /// \return egyenlotlenseg
    bool operator!=(const Family& other) const;
};

#endif //NHF_FAMILY_H
