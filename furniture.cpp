// Новый магазин кухонных гарнитуров требуется заполнить мебелью и 
// бытовой техникой. Напишите приложение, проверяющее что мебель и 
// техника не пересекаются между собой, мебель из разных материалов 
// находится не ближе двух метров друг к другу, а техника не висит в воздухе.

// Кухонный шкаф: материал, габариты (x, y, z), координаты (x, y, z), метод проверки на 
// пересечение с другим шкафом в пространстве.

// Бытовая техника: наименование, габариты (x, y, z), координаты (x, y, z), метод включения/выключения техники.

// План кухни: габариты прямоугольной кухни, набор шкафов и техники, метод проверки выполнения условия задачи.


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

class Appliance {
private:
    std::string name;            
    double x, y, z;              
    double coord_x, coord_y, coord_z; 
    bool is_on;              

    void validateDimensions(double x, double y, double z) const;

public:
    // Конструкторы
    Appliance();
    Appliance(const std::string& _name, double _x, double _y, double _z, double _coord_x, double _coord_y, double _coord_z);
    Appliance(const Appliance& other);

    // Методы
    std::string getName() const;
    double getX() const;
    double getY() const;
    double getZ() const;
    double getCoordX() const;
    double getCoordY() const;
    double getCoordZ() const;
    bool isOn() const;
    void turnOn();
    void turnOff();
};

#endif // FURNITURE_H
