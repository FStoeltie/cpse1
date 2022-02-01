#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "set.hpp"


TEST_CASE( "Adding int" ){
    Set<int, 10> s;
    for (int i = -5; i < 15; i++) {
        s.add(i);
    }
    REQUIRE( s.contains(-5) == true ); 
    REQUIRE( s.contains(5) == true ); 
    REQUIRE( s.contains(-6) == false ); 
    REQUIRE( s.contains(6) == false ); 
}
TEST_CASE( "Removing int" ){
    Set<int, 20> s;
    for (int i = -5; i < 25; i++) {
        s.add(i);
    }

    REQUIRE( s.contains(-6) == false );
    s.remove(-6);
    REQUIRE( s.contains(-6) == false );
    REQUIRE( s.contains(-5) == true ); 
    s.remove(-5);
    REQUIRE( s.contains(-5) == false ); 

    REQUIRE( s.contains(15) == true ); 
    REQUIRE( s.contains(16) == false ); 
}
TEST_CASE( "Adding float" ){
    Set<float, 10> s;
    for (int i = -5; i < 15; i++) {
        s.add(i-0.5);
    }
    REQUIRE( s.contains(-5.5) == true ); 
    REQUIRE( s.contains(3.5) == true ); 
    REQUIRE( s.contains(-6.5) == false ); 
    REQUIRE( s.contains(4.5) == false ); 
}
TEST_CASE( "Removing float" ){
    Set<float, 20> s;
    for (int i = -5; i < 25; i++) {
        s.add(i-0.5);
    }

    REQUIRE( s.contains(-5.4) == false );
    REQUIRE( s.contains(-5.6) == false );
    s.remove(-5.6);
    REQUIRE( s.contains(-5.6) == false );
    REQUIRE( s.contains(-5.5) == true ); 
    s.remove(-5.5);
    REQUIRE( s.contains(-6.5) == false ); 

    REQUIRE( s.contains(13.5) == true ); 
    REQUIRE( s.contains(14.5) == false ); 
}