#include <array>
#include "hwlib.hpp"

constexpr double drone = 0.0174532925;
constexpr double power( double a, int pwr ){
   double rvalue = a;
   while( pwr > 1 ){
       rvalue *= a;
       --pwr;
   }
   return rvalue;
}

constexpr double factorial( int a ){
   double rvalue = 1;
   while( a > 0 ){
       rvalue *= a;
       --a;
   }
   return rvalue;
}

constexpr double sin( double a ){
   // Infinite series
   return a - (1/factorial(3)*power(a, 3)) 
            + (1/factorial(5)*power(a, 5))
            - (1/factorial(7)*power(a, 7))
            + (1/factorial(9)*power(a, 9))
            - (1/factorial(11)*power(a, 11))
            + (1/factorial(13)*power(a, 13))
            - (1/factorial(15)*power(a, 15))
            + (1/factorial(17)*power(a, 17))
            - (1/factorial(19)*power(a, 19))
            + (1/factorial(21)*power(a, 21));
}
constexpr double cos( double a ){
   // Infinite series
   return 1 - (1/factorial(2)*power(a, 2)) 
            + (1/factorial(4)*power(a, 4))
            - (1/factorial(6)*power(a, 6))
            + (1/factorial(8)*power(a, 8))
            - (1/factorial(10)*power(a, 10))
            + (1/factorial(12)*power(a, 12))
            - (1/factorial(14)*power(a, 14))
            + (1/factorial(16)*power(a, 16))
            - (1/factorial(18)*power(a, 18))
            + (1/factorial(20)*power(a, 20));
}

constexpr int sinPoints( int degrees, int radius ){
   return (float)(radius) * sin( drone * degrees ) + 20;
}

constexpr int cosPoints( int degrees, int radius ){
   return (float)(radius) * cos( drone * degrees ) + 20;
}

template<int radius, int N=360 >
class generator {
private:
   std::array< hwlib::xy, N > values = {};

public:
   constexpr generator(){
      for( int i = 0; i < N; ++i ){
          values[ i ] = hwlib::xy(cosPoints( i, radius ) + radius, sinPoints( i, radius) + radius);
      }
   }

   constexpr hwlib::xy get( int n ) const {
      return values[ n ];
   }
};

class myRect{
public:
   hwlib::xy p1;
   hwlib::xy p2;
   constexpr myRect() {

   }
   constexpr myRect(hwlib::xy p1, hwlib::xy p2) : p1{p1}, p2{p2} {
      this->p1 = p1;
      this->p2 = p2;
   } 
};
template<int radius, int N=12 >
class generatorCubes {
private:
   std::array< myRect, N > values = {};

public:
   constexpr generatorCubes(){
      for( int hour = 0; hour < 12; hour++ ){
         int hOffset = hour * 30;
         int cos_m = cosPoints( hOffset, radius ) + 6;
         int sin_m = sinPoints( hOffset, radius ) + 6;
         hwlib::xy p1(cos_m, sin_m);
         hwlib::xy p2(cos_m+6, sin_m+6);

         values[ hour ] = myRect(p1, p2);
      }
   }

   constexpr hwlib::rectangle get( int n ) const {
      return values[ n ];
   }

   constexpr void drawRectangles( hwlib::glcd_oled& display) const {
      for(int hour = 0; hour < 12; hour++){
         hwlib::rectangle rec(values[hour].p1, values[hour].p2);
         rec.draw(display);
      }
   }
};
