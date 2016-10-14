/*************************************
* SSD1351  Pin Assignments
*************************************/
#define sclk 2
#define mosi 3
#define dc   4
#define cs   5
#define rst  6

/*************************************
* Color Definitions
*************************************/
#define  BLACK          0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF

/*************************************
* Include Libraries
*************************************/
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <Sensor.h>

/*************************************
* Create Objects
*************************************/
Adafruit_SSD1351 oled = Adafruit_SSD1351(cs, dc, mosi, sclk, rst);
Sensor oxygen = Sensor("Ox: ",A0, 90.0, 50.0, 100.0, 0.0, 100.0 / 1023.0, 0.0);
Sensor co2 = Sensor("CO2: ",A1, 500.0, 300.0, 800.0, 200.0, 600.0 / 1023.0, 200.0);
/*************************************
* Declare Globals
*************************************/

float old_oxygen_level;
unsigned short int oxygen_cursor_x;
unsigned short int oxygen_cursor_y;
float old_co2_level;
unsigned short int co2_cursor_x;
unsigned short int co2_cursor_y;

/*************************************
*
*               SETUP
*
*************************************/
void setup() {
  Serial.begin(9600); // I think this can be removed...
  /*************************************
   *    Arduino PIN SETUP
   *************************************/


  /*************************************
   *    OLED SETUP
   *************************************/
  oled.begin(); // Start up OLED
  oled.fillScreen(BLACK); // Clear the screen
  oled.setTextSize(1); // Set default text size
}



/*************************************
*
*               LOOP
*
*************************************/
void loop() {

  oxygen.update();
  if( oxygen.display_me ){

    if( oxygen.display_value != old_oxygen_level ){
      oled.setTextColor(BLACK);
      oled.setCursor( oxygen_cursor_x, oxygen_cursor_y );
      oled.print((int)old_oxygen_level+(String)"%\n");
     }

    oled.setCursor( 20, oled.height()/2 );
    oled.setTextColor(RED);
    oled.print( oxygen.display_name );
    oxygen_cursor_x = oled.getCursorX(); // For clearing value
    oxygen_cursor_y = oled.getCursorY(); // For clearing value
    oled.print((int)oxygen.display_value+(String)"%\n");

    old_oxygen_level = oxygen.display_value;
  }
  else
  {
    oled.setCursor( 20, oled.height()/2 );
    oled.setTextColor(BLACK);
    oled.print( oxygen.display_name );
    oled.print((int)old_oxygen_level+(String)"%\n");
  }


  co2.update();
  if( co2.display_me ){

    if( co2.display_value != old_co2_level ){
      oled.setTextColor(BLACK);
      oled.setCursor( co2_cursor_x, co2_cursor_y );
      oled.print((int)old_co2_level+(String)"\n");
     }

    oled.setCursor( 20, oled.height()/4 );
    oled.setTextColor(RED);
    oled.print( co2.display_name );
    co2_cursor_x = oled.getCursorX(); // For clearing value
    co2_cursor_y = oled.getCursorY(); // For clearing value
    oled.print((int)co2.display_value+(String)"\n");

    old_co2_level = co2.display_value;
  }
  else
  {
    oled.setCursor( 20, oled.height()/4 );
    oled.setTextColor(BLACK);
    oled.print( co2.display_name );
    oled.print((int)old_co2_level+(String)"\n");
  }


}
// Comment blergsss
