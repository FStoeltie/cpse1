#include "hwlib.hpp"
#include "note_player_windows.hpp"

  
void note_player_windows::play( const note & n ){
   if (n.frequency == 0) {
      std::cout << "frequency, duration:(" << n.frequency << "," << n.duration << ")" << std::endl;
   } else {
      auto half_period = 1'000'000 / ( 2 * n.frequency ); 
      std::cout << "half period, frequency, duration:(" << half_period << "," << n.frequency << "," << n.duration << ")" << std::endl;
   }
   
}
