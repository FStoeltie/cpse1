#include "hwlib.hpp"

extern "C" void print_asciz( const char * s );
extern "C" void uart_put_char( char c );
extern "C" void application();
extern "C" void test();
void uart_put_char( char c ){
   hwlib::cout << c;
}
void test() {
   print_asciz("test");
}
// void print_asciz( const char * s ){
//    while( *s != '\0'){
//       uart_put_char( *s );
//       ++s;
//    }
// }

// void application(){
//    print_asciz( "Hello world, the ANSWER is 42! @[]`{}~\n" );	
// }

int main( void ){	
   
   namespace target = hwlib::target;   
    
   // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application();
   application();
}