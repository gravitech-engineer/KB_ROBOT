#include "Adafruit_Crickit.h"

Adafruit_Crickit crickit;

#define sig_ch1 CRICKIT_SIGNAL1
#define sig_ch2 CRICKIT_SIGNAL2
#define sig_ch3 CRICKIT_SIGNAL3
#define sig_ch4 CRICKIT_SIGNAL4
#define sig_ch5 CRICKIT_SIGNAL5
#define sig_ch6 CRICKIT_SIGNAL6
#define sig_ch7 CRICKIT_SIGNAL7
#define sig_ch8 CRICKIT_SIGNAL8

void setup()
{
  Serial.begin(9600);
  Wire.begin(4, 5);
  if (!crickit.begin())
  {
    Serial.println("ERROR!");
    while (1)
      ;
  }
  else
    Serial.println("Crickit startezd");
  /****************** Setup Signal IO *********************/
  crickit.pinMode(sig_ch1, OUTPUT);
  crickit.pinMode(sig_ch2, OUTPUT);
  crickit.pinMode(sig_ch3, OUTPUT);
  crickit.pinMode(sig_ch4, OUTPUT);
  crickit.pinMode(sig_ch5, OUTPUT);
  crickit.pinMode(sig_ch6, OUTPUT);
  crickit.pinMode(sig_ch7, OUTPUT);
  crickit.pinMode(sig_ch8, OUTPUT);
  delay(100);
  crickit.digitalWrite(sig_ch1, HIGH);
  crickit.digitalWrite(sig_ch2, HIGH);
  crickit.digitalWrite(sig_ch3, HIGH);
  crickit.digitalWrite(sig_ch4, HIGH);
  crickit.digitalWrite(sig_ch5, HIGH);
  crickit.digitalWrite(sig_ch6, HIGH);
  crickit.digitalWrite(sig_ch7, HIGH);
  crickit.digitalWrite(sig_ch8, HIGH);
}

void loop()
{
  crickit.digitalWrite(sig_ch1, HIGH);
  delay(100);
  crickit.digitalWrite(sig_ch2, HIGH);
  delay(100);
  crickit.digitalWrite(sig_ch3, HIGH);
  delay(100);
  crickit.digitalWrite(sig_ch4, HIGH);
  delay(100);
  crickit.digitalWrite(sig_ch5, HIGH);
  delay(100);
  crickit.digitalWrite(sig_ch6, HIGH);
  delay(100);
  crickit.digitalWrite(sig_ch7, HIGH);
  delay(100);
  crickit.digitalWrite(sig_ch8, HIGH);
  delay(100);
  crickit.digitalWrite(sig_ch1, LOW);
  delay(100);
  crickit.digitalWrite(sig_ch2, LOW);
  delay(100);
  crickit.digitalWrite(sig_ch3, LOW);
  delay(100);
  crickit.digitalWrite(sig_ch4, LOW);
  delay(100);
  crickit.digitalWrite(sig_ch5, LOW);
  delay(100);
  crickit.digitalWrite(sig_ch6, LOW);
  delay(100);
  crickit.digitalWrite(sig_ch7, LOW);
  delay(100);
  crickit.digitalWrite(sig_ch8, LOW);
  delay(100);
}
