///dokumentumfilm
#ifndef NHF_DOCUMENTARY_H
#define NHF_DOCUMENTARY_H

#include <utility>
#include "film.h"

class Documentary: public Film{
    std::string description;    //rovid leiras
public:
    /// Documentary ctor
    /// \param title    cim
    /// \param runtime  jatekido
    /// \param release  kiadas eve
    /// \param desc     rovid leiras
    Documentary(std::string title, int runtime, int release, std::string desc): Film(std::move(title), runtime, release), description(std::move(desc)) {}

    ///default ctor
    Documentary(): Film(){}

    /// ostreamre listazza az adatokat
    /// \param os kiiras celja
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
    bool operator==(const Documentary& other) const;

    ///operator!=
    /// \param other masik film
    /// \return egyenlotlenseg
    bool operator!=(const Documentary& other) const;
};

#endif //NHF_DOCUMENTARY_H
