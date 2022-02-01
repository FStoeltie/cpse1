#include <iostream>
#include "set.hpp"

int main() {
    Set myset;
    myset.add(1);
    myset.add(1);
    myset.add(2);
    myset.add(3);
    myset.add(4);
    myset.add(5);
    myset.add(6);
    myset.add(7);
    myset.add(8);
    myset.add(9);
    myset.add(10);
    myset.add(11);
    myset.remove(2);
    myset.add(11);
    std::cout << "myset: " << myset << std::endl;
    // myset.remove(3);
    // myset.remove(7);
    return -1;
}