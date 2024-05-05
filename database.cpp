#include <fstream>
#include <iostream>
#include <sstream>
#include "database.h"
#include "family.h"
#include "documentary.h"
#include "filehandler.h"

/// database ctor
/// \param cap kapacitas, default = defCap macro
Database::Database(size_t cap){
    capacity = cap;
    pData = new Film * [cap];
    size = 0;
}

/// copy ctor
/// \param other masik adatbazis
Database::Database(const Database &other) {
    capacity = other.capacity;
    size = other.size;
    pData = new Film*[capacity];
    for(size_t i = 0; i < size; ++i){
        pData[i] = other.pData[i];
    }

}

///database dtor
Database::~Database() {
    for(size_t i = 0; i < size; ++i){
        delete pData[i];
    }
    delete[] pData;

}

///getSize
/// \return size
size_t Database::getSize() {
    return size;
}

/// film hozzadasa
/// \param film hozzadando pointer
void Database::add(Film *film) {
    if(size == capacity) extend();
    pData[size++] = film;
}

///tarolot noveli (duplazza)
void Database::extend() {
    std::cout << "Database extended from " << capacity << " to " << capacity*2 << std::endl;
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
    FileHandler handler;
    handler.import(filename);
    databaseReceive(handler.senddb());
}

/// adatbazis kiirasa fajlba
/// \param filename file neve
void Database::exportdb(std::string filename) {
    FileHandler handler;
    handler.receiveDb(*this);
    handler.exportdb(filename);
    }


void Database::databaseReceive(Database &other) {
    for (size_t i = 0; i < other.size; ++i) {
        add(other.pData[i]);
    }
}

/// database ertekadas operator
Database &Database::operator=(const Database &other) {
    if(this == &other) return *this;
    for(size_t i = 0; i < size; ++i){
        delete pData[i];
    }
    delete[] pData;
    capacity = other.capacity;
    size = other.size;
    pData = new Film*[capacity];
    for(size_t i = 0; i < size; ++i){
        pData[i] = other.pData[i];
    }
    return *this;
}


