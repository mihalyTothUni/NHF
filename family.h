///csaladi film

#include "film.h"

#ifndef NHF_FAMILY_H
#define NHF_FAMILY_H

class Family: public Film{
    int rating;    //korhatar
public:
    /// Family ctor
    /// \param title    cim
    /// \param runtime  jatekido
    /// \param release  kidas eve
    /// \param rating   korhatar
    Family(std::string title, int runtime, int release, int rating);

    ///family dtor
    ~Family() = default;

    /// korhatar setter
    /// \param rating   korhatar
    void setRating(int rated);

    /// rating getter
    /// \return korhatar
    int getRating();

    /// ostreamre listazza az adatokat
    /// \param os kiirasi cel
    void listAttributes(std::ostream &os) override;
};

#endif //NHF_FAMILY_H
