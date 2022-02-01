#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <string>
#include "set.hpp"


TEST_CASE( "Adding int" ){
    Set<int, 10> s;
    for (int i = -5; i < 15; i++) {
        s.add(i);
    }
    REQUIRE( s.contains(-5) == true ); 
    REQUIRE( s.contains(4) == true ); 
    REQUIRE( s.contains(-6) == false ); 
    REQUIRE( s.contains(5) == false ); 
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

    REQUIRE( s.contains(14) == true ); 
    REQUIRE( s.contains(15) == false ); 
    s.remove(14);
    s.contains(14);
    REQUIRE( s.contains(14) == false );
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
TEST_CASE( "Adding string" ){
    Set<std::string, 10> s;
    for (int i = -5; i < 15; i++) {
        s.add(std::to_string(i));
    }
    REQUIRE( s.contains("-5") == true ); 
    REQUIRE( s.contains("4") == true ); 
    REQUIRE( s.contains("-6") == false ); 
    REQUIRE( s.contains("5") == false ); 
}
TEST_CASE( "Testing max int" ){
    Set<int, 5> s;
    REQUIRE_THROWS( s.max());
    for (int i = -1; i < 4; i++) {
        s.add(i);
    }

    REQUIRE( s.max() == 3 );
    REQUIRE( s.max() != 2 );
    s.remove(3);
    REQUIRE( s.max() == 2 );
}

TEST_CASE( "Testing max string" ){
    Set<std::string, 5> s;
    REQUIRE_THROWS( s.max());
    s.add("a");
    s.add("b");
    s.add("c");
    s.add("d");
    s.add("e");
    s.add("f");

    REQUIRE( s.max() == "e" );
    s.remove("e");
    s.remove("d");
    REQUIRE( s.max() == "c" );
}