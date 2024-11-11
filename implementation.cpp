#ifndef FURNITURE_H
#define FURNITURE_H

#include <string>

class Furniture {
protected:
    double x, y, z;          // Габариты
    double coord_x, coord_y, coord_z; // Координаты

    void validateDimensions(double x, double y, double z) const;

public:
    // Конструкторы
    Furniture();
    Furniture(double _x, double _y, double _z, double _coord_x, double _coord_y, double _coord_z);
    Furniture(const Furniture& other);

    // Методы доступа
    double getX() const;
    double getY() const;
    double getZ() const;
    double getCoordX() const;
    double getCoordY() const;
    double getCoordZ() const;
};

class KitchenCabinet : public Furniture {
private:
    std::string material;
    const Furniture& KitchenCab;

public:
    // Конструкторы
    KitchenCabinet();
    KitchenCabinet(const Furniture& _KitchenCabinet, const std::string& mat);
    KitchenCabinet(const KitchenCabinet& other);

    // Методы
    std::string getMaterial() const;
    bool intersects(const Furniture& other) const;
};

void Appliance::validateDimensions(double x, double y, double z) const {
    assert(x > 0 && y > 0 && z > 0);
}

Appliance::Appliance() : name(""), x(0), y(0), z(0), coord_x(0), coord_y(0), coord_z(0), is_on(false) {}

Appliance::Appliance(const std::string& _name, double _x, double _y, double _z, double _coord_x, double _coord_y, double _coord_z)
    : name(_name), x(_x), y(_y), z(_z), coord_x(_coord_x), coord_y(_coord_y), coord_z(_coord_z), is_on(false) {
    validateDimensions(_x, _y, _z);
}

Appliance::Appliance(const Appliance& other)
    : name(other.name), x(other.x), y(other.y), z(other.z),
      coord_x(other.coord_x), coord_y(other.coord_y), coord_z(other.coord_z), is_on(other.is_on) {}

std::string Appliance::getName() const { return name; }
double Appliance::getX() const { return x; }
double Appliance::getY() const { return y; }
double Appliance::getZ() const { return z; }
double Appliance::getCoordX() const { return coord_x; }
double Appliance::getCoordY() const { return coord_y; }
double Appliance::getCoordZ() const { return coord_z; }
bool Appliance::isOn() const { return is_on; }
void Appliance::turnOn() { is_on = true; }
void Appliance::turnOff() { is_on = false; }

#endif // FURNITURE_H
