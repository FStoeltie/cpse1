#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "set.hpp"


TEST_CASE( "Adding" ){
    Set s;
    for (int i = -5; i < 15; i++) {
        s.add(i);
    }
    REQUIRE( s.contains(-5) == true ); 
    REQUIRE( s.contains(5) == true ); 
    REQUIRE( s.contains(-6) == false ); 
    REQUIRE( s.contains(6) == false ); 
}
TEST_CASE( "Removing" ){
    Set s;
    for (int i = -5; i < 15; i++) {
        s.add(i);
    }

    REQUIRE( s.contains(-6) == false );
    s.remove(-6);
    REQUIRE( s.contains(-6) == false );
    REQUIRE( s.contains(-5) == true ); 
    s.remove(-5);
    REQUIRE( s.contains(-5) == false ); 
}