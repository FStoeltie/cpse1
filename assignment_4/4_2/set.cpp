#include "set.hpp"
void Set::add( T val) {
    if (this->pos < this->values.max_size() && this->contains(val) == false) {
        this->values[pos++] = val;
    }
}

void Set::remove( T val) {
    auto it = std::find(this->values.begin(), this->values.end(), val);
    if (it == this->values.end() || pos == 0) {
        return;
    }
    
    for(auto i=it;i !=this->values.end();i++)
    {
        *i = *(i+1);
    }
    pos--;
}
bool Set::contains( T val) {
    if (this->pos == 0) {
        return false;
    }
    int res = std::find(this->values.begin(), this->values.end(), val) != this->values.end();

    return res;
}

std::ostream operator<<( std::ostream & o, const Set & s) {
    o << "( ";
    for(auto i=s.values.begin();i !=s.values.begin()+s.pos-1;i++)
    {
        o << *i << ", ";
    }
    o << *(s.values.begin()+s.pos-1) << " )" << std::endl;
}