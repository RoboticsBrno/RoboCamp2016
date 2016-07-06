/**
 * @desc: Support library for DFRobot Color Sensor
 * @author: Bedrich Said
 * 
 * Inspired by:
 * http://www.dfrobot.com/wiki/index.php?title=TCS3200_Color_Sensor_(SKU:SEN0101)
 */

#ifndef DF_ROBOT_COLOR_SENSOR
#define DF_ROBOT_COLOR_SENSOR

byte ColorSensor_counter = 0;
byte ColorSensor_countR = 0;
byte ColorSensor_countG = 0;
byte ColorSensor_countB = 0;
int ColorSensor_flag = 0;
int ColorSensor_s2 = 0;
int ColorSensor_s3 = 0;

class ColorSensor
{
  void timer0_init(void)
  {
    TCCR2A = 0x00;
    TCCR2B = 0x07;   //the clock frequency source 1024 points
    TCNT2 = 100;    //10 ms overflow again
    TIMSK2 = 0x01; //allow interrupt
  }

  static void ISR_INTO()
  {
    ColorSensor_counter++;
  }
  
public:
  void begin(int s0, int s1, int s2, int s3, int out)
  {
    ColorSensor_s2 = s2;
    ColorSensor_s3 = s3;
    pinMode(s0,OUTPUT);
    pinMode(s1,OUTPUT); 
    pinMode(s2,OUTPUT);
    pinMode(s3,OUTPUT);
    digitalWrite(s1,HIGH);
    digitalWrite(s0,HIGH);
    digitalWrite(s2,LOW); 
    digitalWrite(s3,LOW);
    attachInterrupt(0, ISR_INTO, CHANGE);
    timer0_init();
  }

  int red()
  {
    return ColorSensor_countR;
  }

  int green()
  {
    return ColorSensor_countG;
  }

  int blue()
  {
    return ColorSensor_countB;
  }
};

//The timer 2, 10ms interrupt overflow. Internal overflow interrupt executive function.
ISR(TIMER2_OVF_vect)
{
  TCNT2=100;
  switch(++ColorSensor_flag)
  {
  case 1:
    ColorSensor_countR = ColorSensor_counter;
    digitalWrite(ColorSensor_s2,HIGH);
    digitalWrite(ColorSensor_s3,HIGH);
    break;
  case 2:
    ColorSensor_countG = ColorSensor_counter;
    digitalWrite(ColorSensor_s2,LOW);
    digitalWrite(ColorSensor_s3,HIGH);
    break;
  case 3:
    ColorSensor_countB = ColorSensor_counter;
    digitalWrite(ColorSensor_s2,LOW);
    digitalWrite(ColorSensor_s3,LOW);
  default:
    ColorSensor_flag = 0;
  }
  ColorSensor_counter=0;
}

#endif // DF_ROBOT_COLOR_SENSOR
