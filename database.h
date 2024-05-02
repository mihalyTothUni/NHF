///heterogen kollekcio

#include "film.h"


#ifndef NHF_DATABASE_H
#define NHF_DATABASE_H

#define defCap 10

class Database{
    Film** pData;       //tarolo
    size_t size;        //elemek szama
    size_t capacity;    //tarolo kapacitas

    ///tarolot noveli (duplazza)
    void extend();

    /// megkeres egy filmet a taroloban
    /// \param title keresett cim
    /// \return pointer a talalatra
    /// \error char const* "entry not found"
    Film* search(std::string title);

public:
    /// database ctor
    /// \param cap kapacitas, default = defCap macro
    explicit Database(size_t cap = defCap);

    ///database dtor
    ~Database();

    /// film hozzadasa
    /// \param film hozzadando pointer
    void add(Film* film);

    /// film eltavolitasa
    /// \param title torlendo film cime
    void remove(std::string title);

    /// film keresese es adatok listazasa
    /// \param title keresett cim
    /// \param os  kiiras celja
    void searchAndList(std::string title, std::ostream& os);

    /// osszes film adatainak listazasa
    /// \param os kiiras celja
    void listAll(std::ostream& os);

    /// adatbazis importalas fajlbol
    /// \param filename file neve
    void import(std::string filename);

    /// adatbazis kiirasa fajlba
    /// \param filename file neve
    void exportdb(std::string filename);
};

#endif //NHF_DATABASE_H
