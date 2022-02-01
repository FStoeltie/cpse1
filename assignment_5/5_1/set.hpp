#include <iostream> 
#include <algorithm>
#include <array> 
#ifndef SET_HPP
#define SET_HPP

class Set{
public:
    void add( int );
    void remove( int );
    bool contains( int );
    friend std::ostream operator<<( std::ostream &, const Set & );
private:
    std::array<int, 10> values;
    int pos = 0;
};
#endif