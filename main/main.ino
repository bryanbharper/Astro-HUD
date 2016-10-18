#include <Helpers.h>

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
#include <Helpers.h>

/*************************************
* Sensor Objects
*************************************/
Adafruit_SSD1351 oled = Adafruit_SSD1351(cs, dc, mosi, sclk, rst);
const int num_sensors = 3;
Sensor sensors[num_sensors] = {
                      Sensor("Ox: ", A0, 90.0, 50.0, 100.0, 0.0, 100.0 / 1023.0, 0.0),
                      Sensor("CO2: ", A1, 500.0, 300.0, 600.0, 134.0, 600.0 / 1023.0, 200.0),
                      Sensor("X: ", A2, 700.0, 500.0, 1023, 0, 1, 0)
                    };

/*************************************
* Priority Slots / Coordinates
*************************************/
unsigned short int sensor_x = 20;
int priority_y [7] = {16*2, 16*3, 16*4, 16*5, 16*6, 16*7, 16*8};

/*************************************
* Declare Globals
*************************************/
int text_color;

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

  // Initialize any additional sensor properties not addressed in Constructor
  for(int i = 0; i < num_sensors; i++)
  {
    oled.setTextColor(BLACK);
    oled.setCursor( sensor_x, priority_y[i] );
    oled.print( sensors[i].display_name );
    sensors[i].display_value_x = oled.getCursorX();
    // Set last_display_value to arbitrary value
    sensors[i].last_display_value = -9999;
  }

}



/*************************************
*
*               LOOP
*
*************************************/
void loop() {
  for(int i = 0; i < num_sensors; i++)
  {
    sensors[i].update();
    if( sensors[i].display_me ){

      if( sensors[i].display_value != sensors[i].last_display_value ){
        // Overwrite any outdated value
        oled.setTextColor(BLACK);
        oled.setCursor( sensors[i].display_value_x, priority_y[i] );
        oled.print((int)sensors[i].last_display_value+(String)"\n");
      }
      // Display sensor name and value
      oled.setCursor( sensor_x, priority_y[i] );
      text_color = rgbTo16( 31, 63*(1-sensors[i].priority), 31*(1-sensors[i].priority));
      oled.setTextColor( text_color );
      oled.print( sensors[i].display_name );
      oled.print((int) sensors[i].display_value+(String)"\n");

      sensors[i].last_display_value = sensors[i].display_value;
    }
    else
    {
      oled.setCursor( sensor_x, priority_y[i] );
      oled.setTextColor(BLACK);
      oled.print( sensors[i].display_name );
      oled.print((int)sensors[i].last_display_value+(String)"\n");
    }
  }
  Serial.print(sensors[1].display_name + "\t" + sensors[1].priority + "\n");
}
