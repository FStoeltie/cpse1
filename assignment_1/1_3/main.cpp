#include "hwlib.hpp"

extern "C" void print_asciz( const char * s );
extern "C" void uart_put_char( char c );
extern "C" void application();
extern "C" char to_capital(char c);
void uart_put_char( char c ){
   hwlib::cout << c;
}
// Looking at the ASCII table, the characters swapped from 
// capital case to lower case and visa versa.
char to_capital( char c ) {
   if (c >= 65 && c <= 90) {
      return c+32;
   } else if (c >= 97 && c <= 122) {
      return c-32;
   }
   return c;
}

int main( void ){	
   
   namespace target = hwlib::target;   
    
   // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application();
   application();
}