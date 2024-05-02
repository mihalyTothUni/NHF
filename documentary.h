///dokumentumfilm

#include "film.h"

#ifndef NHF_DOCUMENTARY_H
#define NHF_DOCUMENTARY_H

class Documentary: public Film{
    std::string description;    //rovid leiras
public:
    /// Documentary ctor
    /// \param title    cim
    /// \param runtime  jatekido
    /// \param release  kiadas eve
    /// \param desc     rovid leiras
    Documentary(std:: string title, int runtime, int release, std:: string desc);

    ///documentary dtor
    ~Documentary() = default;

    /// leiras setter
    /// \param desc leiras
    void setDescription(std::string desc);

    /// leiras getter
    /// \return string a leirassal
    std::string getDescription();

    /// ostreamre listazza az adatokat
    /// \param os kiiras celja
    void listAttributes(std::ostream &os) override;
};

#endif //NHF_DOCUMENTARY_H
