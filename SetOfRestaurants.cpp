#include "SetOfRestaurants.h"
#include <fstream>
#include <iostream>

template<typename T>
SetOfRestaurants<T>::SetOfRestaurants():
    capacity(DEFAULT_CAPACITY), size(0) {
    restaurants = new T[capacity]; 
}

template<typename T>
SetOfRestaurants<T>::SetOfRestaurants(const SetOfRestaurants& other) {
    size = other.size;
    capacity = other.capacity;

    restaurants = new T[capacity];

    for (unsigned long i = 0; i < size; ++i) {
        restaurants[i] = other.restaurants[i];
    }
}


template<typename T>
SetOfRestaurants<T>::~SetOfRestaurants() {
    delete[] restaurants;
}

template<typename T>
void SetOfRestaurants<T>::clear() {
    size = 0;
}

template<typename T>
unsigned long SetOfRestaurants<T>::getSize() const {
    return size;
}

template<typename T>
bool SetOfRestaurants<T>::containsElement(const T& restaurant) const {
    for (unsigned long i = 0; i < size; ++i) {
            if (restaurants[i] == restaurant) {
                return true;
            }
        }
        return false;
}

template<typename T>
void SetOfRestaurants<T>::insertElement(const T& restaurant) {
    if (!containsElement(restaurant)) {
            restaurants[size++] = restaurant;
        }
}

template<typename T>
void SetOfRestaurants<T>::deleteElement(const T& restaurant) {
    for (unsigned long i = 0; i < size; ++i) {
            if (restaurants[i] == restaurant) {
                // Сдвиг элементов влево
                for (size_t j = i; j < size - 1; ++j) {
                    restaurants[j] = restaurants[j + 1];
                }
                --size;
                return;
            }
        }
}

template<typename T>
bool SetOfRestaurants<T>::operator==(const SetOfRestaurants& other) const {
    if (size != other.size) return false;
    for (unsigned long i = 0; i < size; ++i) {
        if (!other.containsElement(restaurants[i])) {
            return false;
        }
    }
    return true;
}

template<typename T>
SetOfRestaurants<T> SetOfRestaurants<T>::operator&&(const SetOfRestaurants& other) const {
    SetOfRestaurants<T> result;
    for (unsigned long i = 0; i < size; ++i) {
        if (other.containsElement(restaurants[i])) {
            result.insertElement(restaurants[i]);
        }
    }
    return result;
}

template<typename T>
void SetOfRestaurants<T>::saveToFile(const std::string& filepath) const {
    std::ofstream outFile(filepath);
        if (!outFile.is_open()) {
            throw std::runtime_error("Не удалось открыть файл для записи.");
        }
        for (unsigned long i = 0; i < size; ++i) {
            outFile << restaurants[i] << "\n";
        }
        outFile.close();
}

template<typename T>
void SetOfRestaurants<T>::loadFromFile(const std::string& filepath) {
    std::ifstream inFile(filepath);
    if (!inFile.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для чтения.");
    }
    clear();
    T restaurant;
    while (inFile >> restaurant) {
        insertElement(restaurant);
    }
    inFile.close();
}

template<typename T>
void SetOfRestaurants<T>::printElements() const {
    for (unsigned long i = 0; i < size; ++i) {
            std::cout << restaurants[i] << std::endl;
        }
}

template<typename T>
T SetOfRestaurants<T>::operator[](size_t index) const {
    if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return restaurants[index];
    }