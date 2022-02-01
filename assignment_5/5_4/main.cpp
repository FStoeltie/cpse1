#include "hwlib.hpp"

extern "C" {

   // don't chance this function: it is the bridge 
   // between the C and assembler 'world' and C++.
   void put_char( char c ){
      hwlib::cout << c;
   }
   void application();
   void swap();
   void print_asciz();
   void decode();
}

// Do not change the code below. Execution starts in C++, 
// then continues in application(). Make your modifications 
// there in the extern "C" { . . . }; part, and in the separate .asm file.
int main(){	        
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
    
   // wait for the PC console to start
   hwlib::wait_ms( 500 );
   decode();
   while(true) {
	hwlib::wait_ms( 1500 );
   	   hwlib::cout << '\n';
   		hwlib::cout << "testing";
   		hwlib::cout << '\n';
   		//application();
   		//swap();
         
   		//print_asciz();
   }

}