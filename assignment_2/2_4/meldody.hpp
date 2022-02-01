#ifndef _MELDODY_HPP
#define _MELDODY_HPP

#include "melody.hpp"

class meldody : public melody {
public:
   void play( note_player & p );
};

#endif
