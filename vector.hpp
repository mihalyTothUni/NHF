#ifndef NHF_VECTOR_H
#define NHF_VECTOR_H

#include <iostream>
#include "memtrace.h"

//generikus tarolo
template <typename T>
class Vector {
private:
    T* data;            //tarolo
    size_t capacity;    //kapacitas
    size_t size;        //meret

    void resize();      //tarolo novelo fuggveny

public:
    ///vector ctor
    explicit Vector() : data(new T[1]), capacity(1), size(0) {}

    ///vector ctor(size)
    explicit Vector(size_t cap) : data(new T[cap]), capacity(cap), size(0) {}

    ///vector dtor
    ~Vector();

    ///operator=
    Vector& operator=(const Vector& other);

    ///operator==
    /// \param other masik vector
    bool operator==(const Vector& other) const;

    ///operator!=
    bool operator!=(const Vector<T>& rhs) const;

    ///begin
    T* begin() {return data;}

    ///end
    T* end() {return data + size;}

    ///elem hozzaadasa
    void push_back(const T& value);

    ///elem hozzaadasa (duplicate check)
    void push_back_unique(const T& value);

    ///index operator
    T& operator[](size_t index);

    ///index operator const
    const T& operator[](size_t index) const;

    ///indexnel torles
    void del(size_t index);

    ///teljes torles
    void clear();

    ///meret lekerdezese
    size_t getSize() const;

    ///kapacitas lekerdezese
    size_t getCapacity() const;
};




///kapacitas lekerdezese
/// \return kapacitas
template<typename T>
size_t Vector<T>::getCapacity() const {
    return capacity;
}

///meret lekerdezese
/// \return meret
template<typename T>
size_t Vector<T>::getSize() const {
    return size;
}

///operator=
/// \param other masik vector
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector &other) {
    if(this == &other) return *this;
    delete[] data;
    data = new T[other.capacity];
    capacity = other.capacity;
    size = 0;
    for(size_t i = 0; i < other.size; ++i){
        push_back(other.data[i]);
    }
    return *this;
}

///operator==
/// \param other masik vector
template<typename T>
bool Vector<T>::operator==(const Vector& other) const{
    if(size != other.size) return false;
    for(size_t i = 0; i < size; ++i){
        if(data[i] != other.data[i]) return false;
    }
    return true;
}

///operator!=
/// \param other masik vector
/// \return egyenlotlenseg
template<typename T>
bool Vector<T>::operator!=(const Vector<T>& rhs) const{
    return !(*this == rhs);
}


///index operator
/// \param index index
/// \return indexhez tartozo elem
template<typename T>
T &Vector<T>::operator[](size_t index) {
    if (index >= size) {
        throw "index out of bounds";
    }
    return data[index];
}

///index operator const
/// \param index index
/// \return indexhez tartozo elem
template<typename T>
const T &Vector<T>::operator[](size_t index) const {
    if (index >= size) {
        throw "index out of bounds";
    }
    return data[index];
}

///elem hozzaadasa
/// \param value hozzaadando elem
template<typename T>
void Vector<T>::push_back(const T &value) {
    if (size == capacity) {
        resize();
    }
    data[size++] = value;
}

///elem hozzaadasa (duplicate check)
/// \param value hozzaadando elem
template<typename T>
void Vector<T>::push_back_unique(const T &value) {
    for(size_t i = 0; i < size; ++i){
        if(data[i] == value) return;
    }
    push_back(value);

}

///tarolo novelo fuggveny
template<typename T>
void Vector<T>::resize() {
    capacity *= 2;
    T* temp = new T[capacity];
    for (size_t i = 0; i < size; ++i) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
}

///adott elem torlese
/// \param index torlendo elem indexe
template<typename T>
void Vector<T>::del(size_t index) {
    if(index >= size){
        throw "index out of bounds";
    }
    delete data[index];
    data[index] = data[size-1];
    --size;
}

///teljes torles
template<typename T>
void Vector<T>::clear() {
    size = 0;
}

///dtor
template<typename T>
Vector<T>::~Vector() {
    for(size_t i = 0; i < size; ++i){
        delete data[i];
    }
    delete[] data;
}


#endif //NHF_VECTOR_H
