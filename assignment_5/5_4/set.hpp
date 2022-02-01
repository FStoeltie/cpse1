#ifndef SET_HPP
#define SET_HPP

#include <iostream> 
#include <algorithm>
#include <array> 
#include <exception> 

std::ostream& operator<<(std::ostream& o, const std::array<char, 3>& arr)
{
    std::cout << "(";
    for(auto &c : arr) {
        std::cout << c << ",";
    }
    std::cout << ")";
    return o;
}

template < typename T, unsigned int N> 
class Set{
public:
    void add( T val) {
        if (this->pos < this->values.max_size() && this->contains(val) == false) {
            this->values[pos++] = val;
        }
    }
    void remove( T val) {
        auto it = std::find(this->values.begin(), this->values.begin() + this->pos+1, val);
        if (it == this->values.begin() + this->pos+1 || pos == 0) {
            return;
        }
        for(auto i=it;i !=this->values.begin() + this->pos;i++)
        {
            *i = *(i+1);
        }
        pos--;
    }
    bool contains( T val) {
        if (this->pos == 0) {
            return false;
        }
        bool res = std::find(this->values.begin(), this->values.begin() + this->pos+1, val) != this->values.begin() + this->pos+1;
        return res;
    }
    T max() {
        if (pos == 0) { 
            std::cout << "throwing error" << std::endl;
            throw new std::length_error("Set is empty");
        }
        auto largest = *values.begin();
        for(auto i=values.begin();i !=this->values.begin()+this->pos;i++)
        {
            if (*i > largest) {
                largest = *i;
            }
        }
        return largest;
    }
    friend std::ostream& operator<<( std::ostream & o, const Set & s) {
        o << "( ";
        for(auto i=s.values.begin();i !=s.values.begin()+s.pos-1;i++)
        {
            o << *i << ", ";
        }
        o << *(s.values.begin()+s.pos-1) << " )" << std::endl;
        return o;
    }

    // friend bool operator> (T const& stuff, std::array<char, 3> const& other) {
    //     for (size_t spot = 0; spot < stuff.size(); ++spot) {
    //         if (stuff[spot] > other[spot]) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

private:
    std::array<T, N> values;
    int pos = 0;
};
#endif