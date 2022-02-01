#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source & header files in this project (main.cpp is automatically assumed)

HEADERS += note.hpp
HEADERS += melody.hpp
HEADERS += note_player.hpp
HEADERS += fur_elise.hpp

HEADERS += note_player_windows.hpp
SOURCES += note_player_windows.cpp

HEADERS += note_player_gpio.hpp
SOURCES += note_player_gpio.cpp

HEADERS += rtttl_player.hpp
SOURCES += rtttl_player.cpp

# other places to look for files for this project
SEARCH  := 

CPP_LANGUAGE      ?= -std=c++17
C_LANGUAGE        ?= -std=c11

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
# include $(RELATIVE)Makefile.due
include $(RELATIVE)Makefile.native