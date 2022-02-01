#include "hwlib.hpp"
#include "generator.hpp"

int main( void ){

    WDT->WDT_MR = WDT_MR_WDDIS;

    auto scl = hwlib::target::pin_oc( hwlib::target::pins::scl );
    auto sda = hwlib::target::pin_oc( hwlib::target::pins::sda );

    auto i2c = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );

    auto display = hwlib::glcd_oled(i2c,  0x3C); // 0x3C not 0x3D

    auto min_button = hwlib::target::pin_in(hwlib::target::pins::d22);
    min_button.refresh();

    display.clear();
    constexpr auto sW = generator<20>();
    constexpr auto mW = generator<15>();
    constexpr auto hW = generator<10>();
    constexpr auto cubes = generatorCubes<25>();
    unsigned int seconds;
    auto center = hwlib::xy(32, 32);
    for(;;){
        for(int i = 0; i < 720;){
            for(int j = 0; j < 360; j = j + 6, i++){
                for(int k = 0; k < 360; k = k + 6){
                    seconds = hwlib::now_us();

                    display.clear();
                    cubes.drawRectangles(display);
                    auto sHand = hwlib::line(center, sW.get(k));
                    auto mHand = hwlib::line(center, mW.get(j));
                    auto hHand = hwlib::line(center, hW.get(i/2));
                    if(!min_button.read()){
                        j = j + 6;
                        i++;
                    }
                    min_button.refresh();
                    sHand.draw(display);
                    mHand.draw(display);
                    hHand.draw(display);
                    display.flush();
                    while( hwlib::now_us() < (seconds + 1000000)){}

                }
            }



        }
    }


}