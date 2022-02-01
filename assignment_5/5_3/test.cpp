#include <iostream>
#include "set.hpp"

int main() {
    Set<int, 10> myset;
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
    std::cout << "myset max: " << myset.max() << std::endl;
    Set<float, 10> myfloatset;
    myfloatset.add(1.0);
    myfloatset.add(1.0);
    myfloatset.add(2.5);
    myfloatset.add(3.5);
    myfloatset.add(4.0);
    myfloatset.add(5.0);
    myfloatset.add(6.0);
    myfloatset.add(7.0);
    myfloatset.add(8.0);
    myfloatset.add(-30.4);
    myfloatset.add(14.5);
    myfloatset.add(11.5);
    myfloatset.remove(2.5);
    myfloatset.add(11.5);
    std::cout << "myfloatset: " << myfloatset << std::endl;
    std::cout << "myfloatset max: " << myfloatset.max() << std::endl;

    std::cout << "Creating stringset" << std::endl;
    Set<std::string, 10> mystringset;
    
    mystringset.add("1");
    mystringset.add("2");
    mystringset.add("3");
    mystringset.add("4");
    mystringset.add("5");
    mystringset.add("6");
    mystringset.add("7");
    mystringset.add("9");
    mystringset.add("10");
    mystringset.add("11");
    mystringset.add("12");
    mystringset.add("13");
    std::cout << "mystringset: " << mystringset << std::endl;
    mystringset.remove("2");
    std::cout << "Created stringset object" << std::endl;
    mystringset.add("11");
    
    std::cout << "created string: " << mystringset << std::endl;
    // std::cout << "mystringset max: " << mystringset.max() << std::endl;
    // myset.remove(3);
    // myset.remove(7);
    return -1;
}