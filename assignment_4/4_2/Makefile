#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################
.PHONY: main

main: main.o compressor.hpp decompressor.hpp my_decompressor.hpp match.hpp
	g++ -std=c++17 main.o -o main.exe

main.o: 
	g++ -std=c++17 -c main.cpp

# source files in this project (main.cpp is automatically assumed)
SOURCES :=

# header files in this project
HEADERS := match.hpp compressor.hpp decompressor.hpp my_decompressor.hpp

# other places to look for files for this project
SEARCH  := ../07-library




# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
# RELATIVE := $(RELATIVE)../
# include $(RELATIVE)Makefile.native
