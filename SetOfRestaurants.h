#ifndef SETOFRESTAURANTS_H
#define SETOFRESTAURANTS_H

#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <stdexcept>
#define DEFAULT_CAPACITY 30


template<typename T>
class SetOfRestaurants {
private:
    T* restaurants;
    unsigned long capacity;
    unsigned long size;


public:
    SetOfRestaurants();
    SetOfRestaurants(const SetOfRestaurants& other);
    ~SetOfRestaurants();

    void clear();

    size_t getSize() const;

    void insertElement(const T& restaurant);

    void deleteElement(const T& restaurant);

    bool containsElement(const T& restaurant) const;

    bool operator==(const SetOfRestaurants& other) const;

    SetOfRestaurants operator&&(const SetOfRestaurants& other) const;

    void saveToFile(const std::string& filepath) const;

    void loadFromFile(const std::string& filepath);

    void printElements() const;

    T operator[](size_t index) const;

};

#endif