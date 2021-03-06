#include "hwlib.hpp"

extern "C" void print_asciz( const char * s );
extern "C" void uart_put_char( char c );

void uart_put_char( char c ){
   hwlib::cout << c;
}

// void print_asciz( const char * s ){
//    while( *s != '\0'){
//       uart_put_char( *s );
//       ++s;
//    }
// }

void application(){
   print_asciz( "Hello world, the ANSWER is 42! @[]`{}~\n" );	
}

int main( void ){	
   
   namespace target = hwlib::target;   
   hwlib::cout << "Starting application...\n";
   for(;;) {
      // wait for the PC console to start
      hwlib::wait_ms( 2000 );
      application();
   }

}