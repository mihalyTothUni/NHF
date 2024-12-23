#include <iostream>
#include "database.h"
#include "family.h"
#include "documentary.h"
#include "memtrace.h"



/// film hozzadasa
/// \param film hozzadando pointer
void Database::add(Film *film) {
    pData.push_back_unique(film);
}

/// megkeres egy filmet a taroloban
/// \param title keresett cim
/// \return pointer a talalatra
/// \error char const* "entry not found"
Film *Database::search(const std::string& title) {
    for(auto i: pData){
        if(i->getTitle() == title) return i;
    }
    throw "entry not found";
}

/// film eltavolitasa
/// \param title torlendo film cime
void Database::remove(const std::string& title) {
    for(size_t i = 0; i< pData.getSize(); ++i){
        if(pData[i]->getTitle() == title){
            pData.del(i);
            return;
        }
    }
    throw "entry not found";
}

/// film keresese es adatok listazasa
/// \param title keresett cim
/// \param os  kiiras celja
void Database::searchAndList(const std::string& title, std::ostream &os) {
        search(title)->listAttributes(os);
}

/// osszes film adatainak listazasa
/// \param os kiiras celja
void Database::listAll(std::ostream &os) {
    for(auto i : pData){
        i->listAttributes(os);
    }
}

/// adatbazis importalas fajlbol
/// \param filename file neve
void Database::import(const std::string& filename) {
    fh.openFile(filename, true);
    Film* tmp;
    while((tmp = fh.getElement())){
        add(tmp);
    }
    fh.closeFile();
}


///egyenloseg bool operator
/// \param other masik adatbazis
/// \return egyenloseg
bool Database::operator==(const Database &other) const{
    if (pData.getSize() != other.pData.getSize()) return false;
    for (size_t i = 0; i < pData.getSize(); ++i) {
        if (*(pData[i]) != *(other.pData[i])) return false;
    }
    return true;
}

void Database::exportdb(const std::string& filename) {
    fh.openFile(filename);
    for(auto i : pData){
        fh.writeElement(i);
    }
    fh.closeFile();
}

/// copy ctor
/// \param other masik adatbazis
Database::Database(const Database &other) {
    pData = other.pData;
}

/// teljes adatbazis torlese
void Database::clear() {
    pData.clear();
}





