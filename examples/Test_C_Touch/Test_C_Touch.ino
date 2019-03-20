#include "Adafruit_Crickit.h"
#include <seesaw_neopixel.h>
#define PIN 20

seesaw_NeoPixel strip = seesaw_NeoPixel(10, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_Crickit crickit;


#define CRICKIT_NUM_TOUCH 4
#define CAPTOUCH_THRESH 500

void setup()
{
  Serial.begin(9600); 
  Serial.println("Cap Touch Demo");
  strip.begin();
  if (!crickit.begin())
  {
    Serial.println("ERROR Starting crickit");
    while (1);
  }
  else
    Serial.println("seesaw started");
}
void loop()
{
  test_touch();
}

/*************************************************************
   Function Name: test_touch
   Description: Test Function Touh Pad
   Variable:
 * **********************************************************/
void test_touch()
{
  int i;
  if (crickit.touchRead(0) > 900)
  {
    test_neo();
    
  }
  else if (crickit.touchRead(1) > 900)
  {
    Serial.println("test_servo");
  }
  else if (crickit.touchRead(2) > 900)
  {
    Serial.println("test_motor");
  }
  else if (crickit.touchRead(3) > 900)
  {
    Serial.println("test_signal");
  }
  else
  {
    Serial.println("test_neo");
  }
}

/*************************************************************
 * Function Name: test_neo
 * Description: Test Function NeoPixel
 * Variable: 
 * **********************************************************/
void test_neo()
{
  Serial.println("Test NeoPixel");
  strip.setPixelColor(0, strip.Color(0,150,0));
  delay(50);
  strip.setPixelColor(1, 0, 255, 0);
  delay(50);
  strip.setPixelColor(2, 255, 0, 0);
  delay(50);
  strip.setBrightness(50);
  strip.show();
  delay(100);
  test_touch();
}