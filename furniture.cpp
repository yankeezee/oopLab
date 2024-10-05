// Новый магазин кухонных гарнитуров требуется заполнить мебелью и 
// бытовой техникой. Напишите приложение, проверяющее что мебель и 
// техника не пересекаются между собой, мебель из разных материалов 
// находится не ближе двух метров друг к другу, а техника не висит в воздухе.

// Кухонный шкаф: материал, габариты (x, y, z), координаты (x, y, z), метод проверки на 
// пересечение с другим шкафом в пространстве.

#include <string>
#include <cassert>
#include <iostream>
#include <vector>
class Furniture
{
    protected:
        double x, y, z;  // Габариты
        double coord_x, coord_y, coord_z; // Координаты
    public:
        // Проверка на корректность значений
        void validateDimensions(double x, double y, double z) const {
        assert(x > 0 && y > 0 && z > 0);
    }
        // Конструктор по умолчанию
        Furniture(): x(0), y(0), z(0), 
                     coord_x(0), coord_y(0), coord_z(0) {}

        // Конструктор инициализации
        Furniture(double _x, double _y, double _z,
                    double _coord_x, double _coord_y, double _coord_z){
                        validateDimensions(_x,_y,_z);
                        x=_x;
                        y=_y;
                        z=_z;
                        coord_x=_coord_x;
                        coord_y=_coord_y;
                        coord_z=_coord_z;
                    }
             

        // Конструктор копирования
        Furniture(const Furniture& other)
            : x(other.x), y(other.y), z(other.z),
            coord_x(other.coord_x), coord_y(other.coord_y), coord_z(other.coord_z) {}

        // Методы доступа
        double getX() const { return x; }
        double getY() const { return y; }
        double getZ() const { return z; }
        double getCoordX() const { return coord_x; }
        double getCoordY() const { return coord_y; }
        double getCoordZ() const { return coord_z; }

};

class KitchenCabinet: public Furniture
{
    std::string material;
    const Furniture& KitchenCab;
    public:
        // Конструктор по умолчанию
        Furniture t;
        KitchenCabinet(): KitchenCab(t), material(""){}

        // Конструктор инициализации
        KitchenCabinet(const Furniture& _KitchenCabiet, const std::string& mat): KitchenCab(_KitchenCabiet), material(mat){}

        // Конструктор копирования
        KitchenCabinet(const KitchenCabinet& other)
            : KitchenCab(other.KitchenCab), material(other.material) {}

        std::string getMaterial() const { return material; };

        // Метод проверки на пересечение с другим шкафом
        bool intersects(const Furniture& other) const {
            // Проверка, не пересекаются ли по x, y, z координате
            if ((coord_x + x < other.getCoordX() ||
                coord_x > other.getCoordX() + other.getX()) &&
                (coord_y + y < other.getCoordY() ||
                coord_y > other.getCoordY() + other.getY()) &&
                (coord_z + z < other.getCoordZ() ||
                coord_z > other.getCoordZ() + other.getZ())) {
                return false; // Нет пересечения
            }
            return true; // Пересечение есть
        }

};

int main() {

    // Тестирование конструктора по умолчанию класса Furniture
    Furniture object1;

    assert(object1.getX() == 0);
    assert(object1.getY() == 0);
    assert(object1.getZ() == 0);
    assert(object1.getCoordX() == 0);
    assert(object1.getCoordY() == 0);
    assert(object1.getCoordZ() == 0);

    // Тестирование конструктора по умолчанию класса KitchenCabinet
    KitchenCabinet cabinet1;

    assert(cabinet1.getMaterial() == "");

    // Тестирование конструктора инициализации класса Furniture
    Furniture object2(1.5, 2, 0.5, 0, 0, 0.5);

    assert(object2.getX() == 1.5);
    assert(object2.getY() == 2);
    assert(object2.getZ() == 0.5);
    assert(object2.getCoordX() == 0);
    assert(object2.getCoordY() == 0);
    assert(object2.getCoordZ() == 0.5);

    // Тестирование конструктора инициализации класса KitchenCabinet
    KitchenCabinet cabinet2(object2, "Древесина");
    assert(cabinet2.getMaterial() == "Древесина");

    // Тестирование конструктора копирования класса Furniture
    Furniture object3(object2);
    assert(object3.getX() == 1.5);
    assert(object3.getY() == 2);
    assert(object3.getZ() == 0.5);
    assert(object3.getCoordX() == 0);
    assert(object3.getCoordY() == 0);
    assert(object3.getCoordZ() == 0.5);

    // Тестирование конструктора копирования класса KitchenCabinet
    KitchenCabinet cabinet3(cabinet2);
    assert(cabinet3.getMaterial() == "Древесина");

    // Тестирование метода intersects
    Furniture object4(1, 1, 0.6, 1, 0, 0.6);
    Furniture object5(2, 1, 1, 10, 10, 50);
    KitchenCabinet cabinet4(object4, "ДСП");
    KitchenCabinet cabinet5(object5, "Металл");
    assert(!cabinet2.intersects(object5)); // Не должны пересекаться

    assert(cabinet2.intersects(object4)); // Должны пересекаться

    std::cout << "Все тесты пройдены успешно!";
    return 0;
};