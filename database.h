///heterogen kollekcio
#ifndef NHF_DATABASE_H
#define NHF_DATABASE_H

#include "vector.hpp"
#include "film.h"
#include "filehandler.h"

#define defCap 10

class Database{
    Vector<Film*> pData;        //tarolo
    FileHandler fh;             //filehandler


    /// megkeres egy filmet a taroloban
    /// \param title keresett cim
    /// \return pointer a talalatra
    /// \error char const* "entry not found"
    Film* search(const std::string& title);

public:
    /// database ctor
    /// \param cap kapacitas, default = defCap macro
    explicit Database(size_t cap=defCap) : pData(cap){}

    /// copy ctor
    /// \param other masik adatbazis
    Database(const Database& other);

    ///egyenloseg bool operator
    /// \param other masik adatbazis
    /// \return egyenloseg
    bool operator==(const Database& other) const;

    /// film hozzadasa
    /// \param film hozzadando pointer
    void add(Film* film);

    /// film eltavolitasa
    /// \param title torlendo film cime
    void remove(const std::string& title);

    /// teljes adatbazis torlese
    void clear();

    /// film keresese es adatok listazasa
    /// \param title keresett cim
    /// \param os  kiiras celja
    void searchAndList(const std::string& title, std::ostream& os);

    /// osszes film adatainak listazasa
    /// \param os kiiras celja
    void listAll(std::ostream& os);


    /// adatbazis importalas fajlbol
    /// \param filename file neve
    void import(const std::string& filename);

    /// adatbazis kiirasa fajlba
    /// \param filename file neve
    void exportdb(const std::string& filename);
};

#endif //NHF_DATABASE_H
