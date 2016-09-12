/*** Assign Pins ***/
#define sclk 2
#define mosi 3
#define dc   4
#define cs   5
#define rst  6

/*** Color definitions ***/
#define  BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF

/*** Include Libraries ***/
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>

/* Create an OLED object */
Adafruit_SSD1351 oled = Adafruit_SSD1351(cs, dc, mosi, sclk, rst);

/* Declare Globals */
const int oxygen_sensor_pin = A0;
int oxygen_sensor_value;
double oxygen_level;

/*************************************
*
*               SETUP
*
*************************************/
void setup() {
  // Establish communication with Arduino
  Serial.begin(9600);
  /*************************************
   *    PIN SETUP 
   *************************************/
    

  /*************************************
   *    OLED SETUP
   *************************************/
  // Start up OLED
  oled.begin();

  // Clear the screen
  oled.fillScreen(BLACK);
}



/*************************************
*
*               LOOP
*
*************************************/
void loop() {

  /**** Sensor Data ****/
  oxygen_sensor_value = analogRead(oxygen_sensor_pin); // Read Oxygen Sensor
  oxygen_level = (oxygen_sensor_value/1023.0)*100.0;   // Convert into percentage

  /*** Display Sensory Data on OLED ***/
  oled.setCursor( oled.width()/2, oled.height()/2 ); 
  oled.setTextColor(RED);
  oled.setTextSize(5);
  oled.print((String)"Oxygen level: " + oxygen_level + (String)"%\n");

  /*** Display Sensory Data on Serial  ***/
  Serial.print((String)"Oxygen level: " + oxygen_level + (String)"%\n");
}

