#include "Furniture.h"
#include <cassert>
#include <iostream>
#include <cmath>
// Методы класса Furniture

void Furniture::validateDimensions(double x, double y, double z) const {
    assert(x > 0 && y > 0 && z > 0);
}

Furniture::Furniture() : x(0), y(0), z(0), coord_x(0), coord_y(0), coord_z(0) {}

Furniture::Furniture(double _x, double _y, double _z, double _coord_x, double _coord_y, double _coord_z) {
    validateDimensions(_x, _y, _z);
    x = _x;
    y = _y;
    z = _z;
    coord_x = _coord_x;
    coord_y = _coord_y;
    coord_z = _coord_z;
}

Furniture::Furniture(const Furniture& other)
    : x(other.x), y(other.y), z(other.z),
      coord_x(other.coord_x), coord_y(other.coord_y), coord_z(other.coord_z) {}

void Furniture::identify() const {
    std::cout << "Something it is" << std::endl;
}

double Furniture::getX() const { return x; }
double Furniture::getY() const { return y; }
double Furniture::getZ() const { return z; }
double Furniture::getCoordX() const { return coord_x; }
double Furniture::getCoordY() const { return coord_y; }
double Furniture::getCoordZ() const { return coord_z; }

Furniture::~Furniture() {}


// Методы класса KitchenCabinet

KitchenCabinet::KitchenCabinet() : Furniture(), material("") {}

KitchenCabinet::KitchenCabinet(const Furniture& _KitchenCabinet, const std::string& mat)
    : Furniture(_KitchenCabinet), material(mat) {}

KitchenCabinet::KitchenCabinet(const KitchenCabinet& other)
    : Furniture(other), material(other.material) {}

std::string KitchenCabinet::getMaterial() const { return material; }

void KitchenCabinet::identify() const {
    std::cout <<"It is "<< getMaterial() << " kitchen cabinet!"<<std::endl;
}

bool KitchenCabinet::intersects(const Furniture& other) const {
    return !((coord_x + x < other.getCoordX() ||
              coord_x > other.getCoordX() + other.getX()) &&
             (coord_y + y < other.getCoordY() ||
              coord_y > other.getCoordY() + other.getY()) &&
             (coord_z + z < other.getCoordZ() ||
              coord_z > other.getCoordZ() + other.getZ()));
}

bool KitchenCabinet::isDistanceSafe(const KitchenCabinet& other) const {
    if (material != other.getMaterial()) {
        double distance = std::sqrt(std::pow(coord_x - other.coord_x, 2) +
                                    std::pow(coord_y - other.coord_y, 2) +
                                    std::pow(coord_z - other.coord_z, 2));
        return distance >= 2.0;
    }
    return true;
}

// Методы класса Appliance

void Appliance::validateDimensions(double x, double y, double z) const {
    assert(x > 0 && y > 0 && z > 0);
}

Appliance::Appliance() : name(""), is_on(false) {}

Appliance::Appliance(const std::string& _name, const Furniture& _Appliance)
    : Furniture(_Appliance), name(_name), is_on(false) {}

Appliance::Appliance(const Appliance& other)
    : Furniture(other), name(other.name), is_on(other.is_on) {}

void Appliance::identify() const {
    std::cout <<"It is "<< getName() << "!"<<std::endl;
}

std::string Appliance::getName() const { return name; }
bool Appliance::isOn() const { return is_on; }
void Appliance::turnOn() { is_on = true; }
void Appliance::turnOff() { is_on = false; }

bool Appliance::isOnGround() const {
    return coord_z == 0;
}

// Методы класса KitchenPlan

KitchenPlan::KitchenPlan(double _width, double _length, double _height)
    : width(_width), length(_length), height(_height) {}

void KitchenPlan::addCabinet(const KitchenCabinet& cabinet) {
    cabinets.push_back(cabinet);
}

void KitchenPlan::addAppliance(const Appliance& appliance) {
    appliances.push_back(appliance);
}

bool KitchenPlan::checkPlan() const {
    for (size_t i = 0; i < cabinets.size(); ++i) {
        for (size_t j = i + 1; j < cabinets.size(); ++j) {
            if (cabinets[i].intersects(cabinets[j]) || !cabinets[i].isDistanceSafe(cabinets[j])) {
                return false;
            }
        }
    }

    for (const auto& appliance : appliances) {
        if (!appliance.isOnGround()) {
            return false;
        }
        for (const auto& cabinet : cabinets) {
            if (cabinet.intersects(appliance)) {
                return false;
            }
        }
    }

    return true;
}