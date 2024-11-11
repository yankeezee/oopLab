#include "Furniture.h"
#include <cassert>
#include <iostream>

int main() {
    // Тестирование класса Furniture
    Furniture object1;
    assert(object1.getX() == 0);
    assert(object1.getY() == 0);
    assert(object1.getZ() == 0);
    assert(object1.getCoordX() == 0);
    assert(object1.getCoordY() == 0);
    assert(object1.getCoordZ() == 0);

    Furniture object2(1.5, 2, 0.5, 0, 0, 0.5);
    assert(object2.getX() == 1.5);
    assert(object2.getY() == 2);
    assert(object2.getZ() == 0.5);
    assert(object2.getCoordX() == 0);
    assert(object2.getCoordY() == 0);
    assert(object2.getCoordZ() == 0.5);

    Furniture object3(object2);
    assert(object3.getX() == 1.5);
    assert(object3.getY() == 2);
    assert(object3.getZ() == 0.5);
    assert(object3.getCoordX() == 0);
    assert(object3.getCoordY() == 0);
    assert(object3.getCoordZ() == 0.5);

    // Тестирование класса KitchenCabinet
    KitchenCabinet cabinet1;
    assert(cabinet1.getMaterial() == "");

    KitchenCabinet cabinet2(object2, "Древесина");
    assert(cabinet2.getMaterial() == "Древесина");


    KitchenCabinet cabinet3(cabinet2);
    assert(cabinet3.getMaterial() == "Древесина");

    Furniture object4(1, 1, 0.6, 1, 0, 0.6);
    Furniture object5(2, 1, 1, 10, 10, 50);
    KitchenCabinet cabinet4(object4, "ДСП");
    KitchenCabinet cabinet5(object5, "Металл");

    assert(!cabinet2.intersects(object5)); 
    assert(cabinet2.intersects(object4));  

     // Тестирование класса Appliance
    Appliance fridge("Холодильник", 0.6, 0.6, 1.8, 0, 0, 0);
    assert(fridge.getName() == "Холодильник");
    assert(!fridge.isOn());

    fridge.turnOn();
    assert(fridge.isOn());
    fridge.turnOff();
    assert(!fridge.isOn());

    std::cout << "Все тесты пройдены успешно!" << std::endl;
    return 0;
}
