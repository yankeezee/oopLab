#include "Furniture.cpp"
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

    Furniture object2(0.5,  0.5, 0.5, 0, 0, 0.5);
    assert(object2.getX() == 0.5);
    assert(object2.getY() ==  0.5);
    assert(object2.getZ() == 0.5);
    assert(object2.getCoordX() == 0);
    assert(object2.getCoordY() == 0);
    assert(object2.getCoordZ() == 0.5);

    Furniture object3(object2);
    assert(object2.getX() == 0.5);
    assert(object2.getY() ==  0.5);
    assert(object2.getZ() == 0.5);
    assert(object2.getCoordX() == 0);
    assert(object2.getCoordY() == 0);
    assert(object2.getCoordZ() == 0.5);

    // Тестирование класса KitchenCabinet
    KitchenCabinet cabinet1;
    assert(cabinet1.getMaterial() == "");

    KitchenCabinet cabinet2(object2, "Древесина");
    assert(cabinet2.getMaterial() == "Древесина");


    KitchenCabinet cabinet3(cabinet2);
    assert(cabinet3.getMaterial() == "Древесина");

    Furniture object4(0.6, 0.6, 0.6, 10, 10, 0);
    Furniture object5(2, 1, 1, 10, 10, 50);
    KitchenCabinet cabinet4(object4, "ДСП");
    KitchenCabinet cabinet5(object5, "Металл");

    assert(!cabinet2.intersects(object5)); 
    assert(cabinet2.intersects(object4));  

    Furniture* metallConstruct = &cabinet5; 
    metallConstruct -> identify(); // It is Металл kitchen cabinet!

     // Тестирование класса Appliance
    Appliance fridge("Холодильник", object4);
    assert(fridge.getName() == "Холодильник");
    assert(!fridge.isOn());
    Furniture* _fridge = &fridge; 
    _fridge -> identify(); // It is Холодильник!

    fridge.turnOn();
    assert(fridge.isOn());
    fridge.turnOff();
    assert(!fridge.isOn());

    // Тестирование класса KitchenPlan

    KitchenPlan kitchen(500.0, 500.0, 300.0);

    kitchen.addCabinet(cabinet2);

    kitchen.addCabinet(cabinet5);

    kitchen.addAppliance(fridge);

    assert(kitchen.checkPlan() == false);

    // Using polymorphism with a vector of base class pointers
    std::vector<Furniture*> furniture;

    furniture.push_back(new KitchenCabinet(object2, "Wood"));
    furniture.push_back(new Appliance("Чайник", object3));

    for (const auto& f : furniture) {
        f->identify();  // Output: It is Wood kitchen cabinet!
                        // It is Чайник!
    }

    for (auto& f : furniture) {
            delete f;
        }

    std::cout << "Все тесты пройдены успешно!" << std::endl;
    return 0;
}
