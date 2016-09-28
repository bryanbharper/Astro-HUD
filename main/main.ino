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
#define  BLACK           0x0000
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
#include <math.h>
#include <Sensor.h>

/*************************************
* Create Objects
*************************************/
Adafruit_SSD1351 oled = Adafruit_SSD1351(cs, dc, mosi, sclk, rst);
//Sensor example(13);

/*************************************
* Declare Globals
*************************************/
const int oxygen_sensor_pin = A0;
int oxygen_sensor_value;
double oxygen_level;
double old_oxygen_level;
int oxygen_cursor_x;
int oxygen_cursor_y;

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

  /**** Sensor Data ****/
  oxygen_sensor_value = analogRead(oxygen_sensor_pin); // Read Oxygen Sensor
  oxygen_level = round( (oxygen_sensor_value/1023.0)*100.0 );   // Convert into percentage

  /* Only refresh display if a value has changed. */
  if( oxygen_level != old_oxygen_level ){
    oled.setTextColor(BLACK);
    oled.setCursor( oxygen_cursor_x, oxygen_cursor_y );
    oled.print((int)old_oxygen_level+(String)"%\n");
   }

  /*** Display Sensory Data on OLED ***/
  oled.setCursor( 20, oled.height()/2 );
  oled.setTextColor(RED);
  oled.print((String)"Oxygen: ");
  oxygen_cursor_x = oled.getCursorX(); // For clearing value
  oxygen_cursor_y = oled.getCursorY(); // For clearing value
  oled.print((int)oxygen_level+(String)"%\n");

  /*** Store old oxygen_level ***/
  old_oxygen_level = oxygen_level;
}
<<<<<<< HEAD

//snoop;
//hello everybody

// Twiggy diggy doop.
//My verses still be serving
=======
>>>>>>> origin/master
