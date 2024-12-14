#include <iostream>
#include <cassert>
#include "SetOfRestaurants.cpp"

int main() {
    // Проверки по лабе
    SetOfRestaurants<std::string> set1;
    assert(set1.getSize() == 0);

    set1.insertElement("Restaurant1");
    assert(set1.getSize() == 1);

    set1.insertElement("Restaurant1");
    assert(set1.getSize() == 1);

    set1.deleteElement("Restaurant1");
    assert(set1.getSize() == 0);

    SetOfRestaurants<std::string> set2;
    set2.insertElement("Restaurant2");
    set2.clear();
    assert(set2.getSize() == 0);

    SetOfRestaurants<std::string> set3, set4;
    set3.insertElement("Restaurant3");
    SetOfRestaurants<std::string> intersection1 = set3 && set4;
    assert(intersection1.getSize() == 0);

    SetOfRestaurants<std::string> set5;
    set5.insertElement("Restaurant4");
    SetOfRestaurants<std::string> intersection2 = set5 && set5;
    assert(intersection2.getSize() == set5.getSize());

    SetOfRestaurants<std::string> set6 = set5;
    assert(set6 == set5);

    set5.saveToFile("set5.txt");
    SetOfRestaurants<std::string> set7;
    set7.loadFromFile("set5.txt");
    assert(set7 == set5);

    std::cout << "Все тесты пройдены успешно!" << std::endl;

    // Работа задания
    SetOfRestaurants<std::string> writer1, writer2, writer3;

    writer1.insertElement("Restaurant A");
    writer1.insertElement("Restaurant B");
    writer1.insertElement("Restaurant C");

    writer2.insertElement("Restaurant B");
    writer2.insertElement("Restaurant C");
    writer2.insertElement("Restaurant D");

    writer3.insertElement("Restaurant C");
    writer3.insertElement("Restaurant E");
    writer3.insertElement("Restaurant B");

    SetOfRestaurants<std::string> commonRestaurants = writer1 && writer2 && writer3;

    std::cout << "Common Restaurants for all writers: " << std::endl;
    commonRestaurants.printElements();
    return 0;
}