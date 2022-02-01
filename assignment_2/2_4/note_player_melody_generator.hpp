#ifndef _NOTE_PLAYER_MELODY_GENERATOR_HPP
#define _NOTE_PLAYER_MELODY_GENERATOR_HPP

#include "note_player.hpp"
#include "hwlib.hpp"
#include <iostream>
#include <fstream> 

// ===========================================================================
//
// Generates a melody cpp file
//
// ===========================================================================

class note_player_melody_generator : public note_player {
public: 
	note_player_melody_generator();

	void play( const note & n ) override;

	void close();
};

#endif
