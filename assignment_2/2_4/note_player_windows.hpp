#ifndef _NOTE_PLAYER_WINDOWS_HPP
#define _NOTE_PLAYER_WINDOWS_HPP

#include "note_player.hpp"

// ===========================================================================
//
// simple note player for windows that prints to stdout
//
// ===========================================================================

class note_player_windows : public note_player {
public: 
   note_player_windows()
   {}
   
   void play( const note & n ) override;
};

#endif
