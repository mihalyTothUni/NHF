#include <fstream>
#include <iostream>
#include "database.h"
#include "family.h"
#include "documentary.h"

/// database ctor
/// \param cap kapacitas, default = defCap macro
Database::Database(size_t cap){
    capacity = cap;
    pData = new Film * [cap];
    size = 0;
}

///database dtor
Database::~Database() {
    for(size_t i = 0; i < size; ++i){
        delete pData[i];
    }
    delete[] pData;

}

/// film hozzadasa
/// \param film hozzadando pointer
void Database::add(Film *film) {
    if(size == capacity) extend();
    pData[size++] = film;
}

///tarolot noveli (duplazza)
void Database::extend() {
    Film** temp = new Film*[capacity*2];
    for(size_t i = 0; i < size; ++i){
        temp[i] = pData[i];
    }
    delete[] pData;
    pData = temp;
    capacity *= 2;
}

/// megkeres egy filmet a taroloban
/// \param title keresett cim
/// \return pointer a talalatra
/// \error char const* "entry not found"
Film *Database::search(std::string title) {
    for(size_t i = 0; i < size; ++i){
        if(pData[i]->getTitle() == title) return pData[i];
    }
    throw "entry not found";
}

/// film eltavolitasa
/// \param title torlendo film cime
void Database::remove(std::string title) {
    for(size_t i = 0; i < size; ++i){
        if(pData[i]->getTitle() == title){
            delete pData[i];
            pData[i] = pData[size-1];
            --size;
            return;
        }
    }
    throw "entry not found";
}

/// film keresese es adatok listazasa
/// \param title keresett cim
/// \param os  kiiras celja
void Database::searchAndList(std::string title, std::ostream &os) {
        search(title)->listAttributes(os);
}

/// osszes film adatainak listazasa
/// \param os kiiras celja
void Database::listAll(std::ostream &os) {
    for(size_t i = 0; i < size; ++i){
        pData[i]->listAttributes(os);
    }
}

/// adatbazis importalas fajlbol
/// \param filename file neve
void Database::import(std::string filename) {
    std::ifstream input(filename);
    if (input.is_open()) {
        std::string type;
        while (input >> type) {
            if (type == "Family") {
                std::string title;
                int runtime;
                int release;
                int age;
                input >> title >> runtime >> release >> age;
                add(new Family(title, runtime, release, age));
            } else if (type == "Documentary") {
                std::string title;
                int runtime;
                int release;
                std::string desc;
                input >> title >> runtime >> release >> desc;
                add(new Documentary(title, runtime, release, desc));
            }
            ///itt bovitheto a tovabbi tipusok importalasa
        }
    input.close();
    } else throw "file not found";

}

/// adatbazis kiirasa fajlba
/// \param filename file neve
void Database::exportdb(std::string filename) {
    std::ofstream output(filename);
    if (output.is_open()) {
        for (size_t i = 0; i < size; ++i) {
            pData[i]->listAttributes(output);
        }
    output.close();
    } else throw "file not found";
}
