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
#include <vector>

class Furniture {
protected:
    double x, y, z;         
    double coord_x, coord_y, coord_z; 

    void validateDimensions(double x, double y, double z) const;

public:

    Furniture();
    Furniture(double _x, double _y, double _z, double _coord_x, double _coord_y, double _coord_z);
    Furniture(const Furniture& other);
    virtual void identify() const;
    virtual ~Furniture();



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

public:

    KitchenCabinet();
    KitchenCabinet(const Furniture& _KitchenCabinet, const std::string& mat);
    KitchenCabinet(const KitchenCabinet& other);

    std::string getMaterial() const;
    bool intersects(const Furniture& other) const;
    bool isDistanceSafe(const KitchenCabinet& other) const;
    void identify() const override;
};

class Appliance : public Furniture{
private:
    std::string name;            
    bool is_on;              

    void validateDimensions(double x, double y, double z) const;

public:
    Appliance();
    Appliance(const std::string& _name, const Furniture& _Appliance);
    Appliance(const Appliance& other);
    void identify() const override;

    std::string getName() const;
    bool isOn() const;
    void turnOn();
    void turnOff();
    bool isOnGround() const;
};

class KitchenPlan {
private:
    double width, length, height;
    std::vector<KitchenCabinet> cabinets;
    std::vector<Appliance> appliances;

public:
    KitchenPlan(double _width, double _length, double _height);
    void addCabinet(const KitchenCabinet& cabinet);
    void addAppliance(const Appliance& appliance);
    bool checkPlan() const; 
};

#endif // FURNITURE_H
