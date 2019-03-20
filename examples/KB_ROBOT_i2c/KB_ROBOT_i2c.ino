/*************************************************************
   Name: Examples_KB_ROBOT
   Device: KidBright32 V1.4
   Chip: ESP32-WROOM
   Compile: Node32s
   Create: 19/03/62
   Edit: 19/03/62
   By: Nattkarn.P
   Email: nattkarn@gravitechthai.com
**************************************************************/

#include "Adafruit_Crickit.h"
#include "seesaw_servo.h"
#include "seesaw_motor.h"
#include <seesaw_neopixel.h>
#include "Wire.h"
// #include <Adafruit_NeoPixel.h>

/*********************** Define Variable ********************/
#define sig_ch1 CRICKIT_SIGNAL1
#define sig_ch2 CRICKIT_SIGNAL2
#define sig_ch3 CRICKIT_SIGNAL3
#define sig_ch4 CRICKIT_SIGNAL4
#define sig_ch5 CRICKIT_SIGNAL5
#define sig_ch6 CRICKIT_SIGNAL6
#define sig_ch7 CRICKIT_SIGNAL7
#define sig_ch8 CRICKIT_SIGNAL8
#define NUMPIXELS 10
// #define neo_pin 17
#define neo_pin 20 //default
#define CRICKIT_NUM_TOUCH 4
#define CAPTOUCH_THRESH 500
#define speaker 27
bool flag_key;
/************************************************************/
Adafruit_Crickit crickit;

/*********************** Create Object **********************/
//Object Servo
seesaw_Servo myservo1(&crickit);
seesaw_Servo myservo2(&crickit);
seesaw_Servo myservo3(&crickit);
seesaw_Servo myservo4(&crickit);
//Object Motor
seesaw_Motor motor_a(&crickit);
seesaw_Motor motor_b(&crickit);
//Object Neo
// Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, neo_pin, NEO_GRB + NEO_KHZ800);
seesaw_NeoPixel strip = seesaw_NeoPixel(NUMPIXELS, neo_pin, NEO_GRB + NEO_KHZ800);

//Object
/************************************************************/

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    Wire.begin(4, 5);
    check_start();
    setup_function();
    Serial.println("Start Test");
    test_touch();
}

void loop()
{
    // put your main code here, to run repeatedly:
}

/************************************************************
 * Function Name: Setup Function
 * Description: Setup All Function
 * Variable: 
 * *********************************************************/
void setup_function()
{
    /****************** Setup Drive *************************/
    //our default frequency is 1khz
    crickit.setPWMFreq(CRICKIT_DRIVE1, 1000);
    crickit.setPWMFreq(CRICKIT_DRIVE2, 1000);
    crickit.setPWMFreq(CRICKIT_DRIVE3, 1000);
    crickit.setPWMFreq(CRICKIT_DRIVE4, 1000);
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
    /****************** Setup Servo *************************/
    //   myservo1.attach(CRICKIT_SERVO1);
    //   myservo2.attach(CRICKIT_SERVO2);
    //   myservo3.attach(CRICKIT_SERVO3);
    //   myservo4.attach(CRICKIT_SERVO4);
    /****************** Setup Motor *************************/
    motor_a.attach(CRICKIT_MOTOR_A1, CRICKIT_MOTOR_A2);
    motor_b.attach(CRICKIT_MOTOR_B1, CRICKIT_MOTOR_B2);
    /****************** Setup NeoPixel **********************/
    strip.begin();
    strip.show();
    /****************** Setup Speaker ***********************/
    pinMode(speaker, OUTPUT);
    /****************** Setup Touch ************************/
    Serial.println("Setup OK");
}

/*************************************************************
 * Function Name: Set Flag
 * Description: Setup Flag Token
 * Variable: byte flag_state
 * **********************************************************/
void set_flag(int flag_state)
{
    switch (flag_state)
    {
    case 1:
        /* code */
        flag_key = true;
        break;
    case 0:
        /* code */
        flag_key = false;
        break;
    default:
        Serial.println("set flag error");
        break;
    }
}

/*************************************************************
 * Function Name: Check_crickit_start
 * Description: Check Crckit Board Ready To Test
 * Variable: 
 * **********************************************************/
void check_start()
{
    if (!crickit.begin())
    {
        Serial.println("ERROR!");
        while (1)
        {
        }
    }
    else
    {
        Serial.println("Testing started");
    }
}

/*************************************************************
 * Function Name: led_green
 * Description: Setup LED Green From Function
 * Variable: String,int
 * **********************************************************/
void led_green(int function_num, int led_state)
{
    int led_green_pin;
    int led_status;
    if (function_num > 0)
    {
        switch (function_num)
        {
        case 1: //test_drive
            /* code */
            led_green_pin = 12;
            break;
        case 2: //test_servo
            /* code */
            led_green_pin = 14;
            break;

        case 3: //test_motor
            /* code */
            led_green_pin = 26;
            break;

        case 4: // test_neo & test_speaker
            /* code */
            led_green_pin = 25;
            break;

        case 5: //test_signal
            /* code */
            led_green_pin = 33;
            break;

        case 6: //test_touch
            /* code */
            led_green_pin = 32;
            break;

        default:
            Serial.println("LED Green ERROR");
            break;
        }
    }
    if (led_state > -1)
    {
        if (led_state == 1)
        {
            led_status = 1;
        }
        else if (led_state == HIGH)
        {
            led_status = 1;
        }
        else if (led_state == 0)
        {
            led_status = 0;
        }
        else if (led_state == LOW)
        {
            led_status = 0;
        }
        else
        {
            Serial.println("LED Status ERROR");
        }
    }
    digitalWrite(led_green_pin, led_status);
}

/*************************************************************
 * Function Name: test_drive
 * Description: Test Function Drive
 * Variable: 
 * **********************************************************/
void test_drive()
{
    set_flag(1);
    if (flag_key == true)
    {
        led_green(1, 1);
        Serial.println("Test Drive");
        //CH1
        crickit.analogWrite(CRICKIT_DRIVE1, CRICKIT_DUTY_CYCLE_OFF);
        delay(100);
        crickit.analogWrite(CRICKIT_DRIVE1, CRICKIT_DUTY_CYCLE_MAX);
        delay(100);
        crickit.analogWrite(CRICKIT_DRIVE1, CRICKIT_DUTY_CYCLE_OFF);
        //CH2
        crickit.analogWrite(CRICKIT_DRIVE2, CRICKIT_DUTY_CYCLE_OFF);
        delay(100);
        crickit.analogWrite(CRICKIT_DRIVE2, CRICKIT_DUTY_CYCLE_MAX);
        delay(100);
        crickit.analogWrite(CRICKIT_DRIVE2, CRICKIT_DUTY_CYCLE_OFF);
        //CH3
        crickit.analogWrite(CRICKIT_DRIVE3, CRICKIT_DUTY_CYCLE_OFF);
        delay(100);
        crickit.analogWrite(CRICKIT_DRIVE3, CRICKIT_DUTY_CYCLE_MAX);
        delay(100);
        crickit.analogWrite(CRICKIT_DRIVE3, CRICKIT_DUTY_CYCLE_OFF);
        //CH4
        crickit.analogWrite(CRICKIT_DRIVE4, CRICKIT_DUTY_CYCLE_OFF);
        delay(100);
        crickit.analogWrite(CRICKIT_DRIVE4, CRICKIT_DUTY_CYCLE_MAX);
        delay(100);
        crickit.analogWrite(CRICKIT_DRIVE4, CRICKIT_DUTY_CYCLE_OFF);
        led_green(1, LOW);
        set_flag(0);
        test_touch();
    }
    else
    {
        Serial.println("Drive No Flag");
    }
}

/*************************************************************
 * Function Name: test_servo
 * Description: Test Function Servo
 * Variable: 
 * **********************************************************/
void test_servo()
{
    /****************** Setup Servo *************************/
    myservo1.attach(CRICKIT_SERVO1);
    myservo2.attach(CRICKIT_SERVO2);
    myservo3.attach(CRICKIT_SERVO3);
    myservo4.attach(CRICKIT_SERVO4);
    set_flag(1);
    if (flag_key == true)
    {
        led_green(2, HIGH);
        delay(300);
        Serial.println("Test Servo");
        myservo1.write(0);
        myservo2.write(0);
        myservo3.write(0);
        myservo4.write(0);
        delay(500);
        myservo1.write(180);
        myservo2.write(180);
        myservo3.write(180);
        myservo4.write(180);
        delay(500);
        set_flag(0);
        led_green(2, LOW);
        test_touch();
    }
    else
    {
        Serial.println("Servo No Flag");
    }
}

/*************************************************************
 * Function Name: test_motor
 * Description: Test Function Servo
 * Variable: 
 * **********************************************************/
void test_motor()
{
    set_flag(1);
    if (flag_key == true)
    {
        led_green(3, HIGH);
        delay(300);
        Serial.println("Test Motor");
        motor_a.throttle(1);
        motor_b.throttle(0);
        delay(500);
        motor_a.throttle(0);
        motor_b.throttle(1);
        delay(500);
        motor_a.throttle(0);
        motor_b.throttle(0);
        delay(500);
        set_flag(0);
        led_green(3, LOW);
        test_touch();
    }
    else
    {
        Serial.println("Motor No Flag");
    }
}

/*************************************************************
 * Function Name: test_neo
 * Description: Test Function NeoPixel
 * Variable: 
 * **********************************************************/
void test_neo()
{
    set_flag(1);
    if (flag_key == true)
    {
        led_green(4, HIGH);
        delay(300);
        Serial.println("Test NeoPixel");
        int temp_r = random(0, 255);
        int temp_g = random(0, 255);
        int temp_b = random(0, 255);
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        for (int i = 0; i < NUMPIXELS; i++)
        {
            strip.setPixelColor(i, strip.Color(temp_r, temp_g, temp_b));
            delay(50);
        }
        strip.setBrightness(100);
        strip.show(); // This sends the updated pixel color to the hardware.
        delay(10);    // Delay for a period of time (in milliseconds).
        test_speaker();
    }
    else
    {
        Serial.println("NeoPixel No Flag");
    }
}

/*************************************************************
 * Function Name: test_speaker
 * Description: Test Function Speaker
 * Variable: 
 * **********************************************************/
void test_speaker()
{
    Serial.println("Test Speaker");
    unsigned char i;
    for (i = 0; i < 100; i++)
    {
        digitalWrite(speaker, HIGH);
        delay(1); //wait for 1ms
        digitalWrite(speaker, LOW);
        delay(1); //wait for 1ms
    }
    //output another frequency
    /*for (i = 0; i < 10; i++)
  {
    digitalWrite(speaker, HIGH);
    delay(20); //wait for 2ms
    digitalWrite(speaker, LOW);
    delay(20); //wait for 2ms
  }*/
    set_flag(0);
    test_touch();
}

/*************************************************************
 * Function Name: test_signal
 * Description: Test Function Signal I/O
 * Variable: 
 * **********************************************************/
void test_signal()
{
    set_flag(1);
    if (flag_key == true)
    {
        // led_green(5, HIGH);
        delay(100);
        Serial.println("Test Signal");
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
        set_flag(0);
        // led_green(5, LOW);
        test_touch();
    }
    else
    {
        Serial.println("Signal No Flag");
    }
}

/*************************************************************
 * Function Name: test_touch
 * Description: Test Function Touh Pad
 * Variable: 
 * **********************************************************/
void test_touch()
{
    if (crickit.touchRead(0) > 900)
    {
        // Serial.println("test_drive");
        test_drive();
    }
    else if (crickit.touchRead(1) > 900)
    {
        // Serial.println("test_servo");
        test_servo();
    }
    else if (crickit.touchRead(2) > 900)
    {
        // Serial.println("test_motor");
        test_motor();
    }
    else if (crickit.touchRead(3) > 900)
    {
        // Serial.println("test_signal");
        test_signal();
    }
    else
    {
        // Serial.println("test_neo");
        test_neo();
        test_speaker();
        // test_temp();
    }
}

void test_temp()
{
    Serial.println("Test Temp");
    delay(1000);
    test_touch();
}

void test_temp2()
{
    Serial.println("Test Temp2");
    delay(1000);
    test_touch();
}
