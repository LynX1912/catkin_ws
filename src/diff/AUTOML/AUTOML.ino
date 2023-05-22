#include <PS2X_lib.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Point.h>
//#include <Servo.h>
#define PWMA 12    
#define DIRA1 34
#define DIRA2 35  
#define PWMB 8     
#define DIRB1 37
#define DIRB2 36  
#define PWMC 9   
#define DIRC1 43 
#define DIRC2 42  
#define PWMD 5    
#define DIRD1 A4  
#define DIRD2 A5 

#define PS2_DAT        52      
#define PS2_CMD        51  
#define PS2_SEL        53  
#define PS2_CLK        50  


//double car_length = 0.18, fast;

//Servo myservo;
int pos  ;

char speed;
// #define pressures   true
#define pressures   false
// #define rumble      true
#define rumble      false
PS2X ps2x; 
double dx_rev, omega_rev,control1, control2, mode;

ros::NodeHandle nh;   

//chuong trinh callback nhan du lieu dieu khien tu ROS
void messageCb( const geometry_msgs::Twist& receive_msg) {
  dx_rev = receive_msg.linear.x;
  omega_rev = receive_msg.angular.z;
  nh.loginfo("Vua nhan dc du lieu tu ROS");
}
void modechange(const geometry_msgs::Point& receive_msg)
{
    mode = receive_msg.x;
}
void controlmanual1( const geometry_msgs::Point& receive_msg) {
  control1 = receive_msg.x;
}
void controlmanual2( const geometry_msgs::Point& receive_msg) {
  control2 = receive_msg.x;
}

ros::Subscriber<geometry_msgs::Twist> sub1("/cmd_vel", &messageCb );  
ros::Subscriber<geometry_msgs::Point> sub2("/modear", &modechange );  
ros::Subscriber<geometry_msgs::Point> sub3("/manualar1", &controlmanual1 ); 
ros::Subscriber<geometry_msgs::Point> sub4("/manualar2", &controlmanual2 ); 


//geometry_msgs::Point encoder;
//ros::Publisher pub1("/velar", &encoder);


int error = 0;
byte type = 0;
byte vibrate = 0;



#define MOTORA_FORWARD(pwm)    do{digitalWrite(DIRA1,HIGH); digitalWrite(DIRA2,LOW);analogWrite(PWMA,pwm);}while(0)
#define MOTORA_STOP(x)         do{digitalWrite(DIRA1,LOW); digitalWrite(DIRA2,LOW); analogWrite(PWMA,0);}while(0)
#define MOTORA_BACKOFF(pwm)    do{digitalWrite(DIRA1,LOW);digitalWrite(DIRA2,HIGH); analogWrite(PWMA,pwm);}while(0)

#define MOTORB_FORWARD(pwm)    do{digitalWrite(DIRB1,HIGH); digitalWrite(DIRB2,LOW);analogWrite(PWMB,pwm);}while(0)
#define MOTORB_STOP(x)         do{digitalWrite(DIRB1,LOW); digitalWrite(DIRB2,LOW); analogWrite(PWMB,0);}while(0)
#define MOTORB_BACKOFF(pwm)    do{digitalWrite(DIRB1,LOW);digitalWrite(DIRB2,HIGH); analogWrite(PWMB,pwm);}while(0)

#define MOTORC_FORWARD(pwm)    do{digitalWrite(DIRC1,HIGH); digitalWrite(DIRC2,LOW);analogWrite(PWMC,pwm);}while(0)
#define MOTORC_STOP(x)         do{digitalWrite(DIRC1,LOW); digitalWrite(DIRC2,LOW); analogWrite(PWMC,0);}while(0)
#define MOTORC_BACKOFF(pwm)    do{digitalWrite(DIRC1,LOW);digitalWrite(DIRC2,HIGH); analogWrite(PWMC,pwm);}while(0)

#define MOTORD_FORWARD(pwm)    do{digitalWrite(DIRD1,HIGH); digitalWrite(DIRD2,LOW);analogWrite(PWMD,pwm);}while(0)
#define MOTORD_STOP(x)         do{digitalWrite(DIRD1,LOW); digitalWrite(DIRD2,LOW); analogWrite(PWMD,0);}while(0)
#define MOTORD_BACKOFF(pwm)    do{digitalWrite(DIRD1,LOW);digitalWrite(DIRD2,HIGH); analogWrite(PWMD,pwm);}while(0)


#define SERIAL  Serial

#define LOG_DEBUG

#ifdef LOG_DEBUG
#define M_LOG SERIAL.print
#else
#define M_LOG 
#endif

#define MAX_PWM   200
#define MIN_PWM   130

int Motor_PWMA ;
int Motor_PWMB ;
int Motor_PWMC;
int Motor_PWMD;

void pwm(unsigned char n)
  {
  Motor_PWMA = n;
  Motor_PWMB = n;
  Motor_PWMC = n;
  Motor_PWMD = n;
  }

void ADVANCE()
{
  MOTORA_FORWARD(Motor_PWMA);
  MOTORB_FORWARD(Motor_PWMB); 
  MOTORC_FORWARD(Motor_PWMC);
  MOTORD_FORWARD(Motor_PWMD);
}

void BACK()
{
  MOTORA_BACKOFF(Motor_PWMA);MOTORB_BACKOFF(Motor_PWMB); 
  MOTORC_BACKOFF(Motor_PWMC);MOTORD_BACKOFF(Motor_PWMD);
}

void RIGHT()
{
  MOTORA_FORWARD(Motor_PWMA);MOTORB_BACKOFF(Motor_PWMB);
  MOTORC_BACKOFF(Motor_PWMC);MOTORD_FORWARD(Motor_PWMD);
}
void LEFT()
{
  MOTORA_BACKOFF(Motor_PWMA);MOTORB_FORWARD(Motor_PWMB); 
  MOTORC_FORWARD(Motor_PWMC);MOTORD_BACKOFF(Motor_PWMD); 
}

void STOP()
{
  MOTORA_STOP(Motor_PWMA); MOTORB_STOP(Motor_PWMB);
  MOTORC_STOP(Motor_PWMC);MOTORD_STOP(Motor_PWMD);
}

void IO_init()
{
  pinMode(PWMA, OUTPUT);
  pinMode(DIRA1, OUTPUT);
  pinMode(DIRA2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRB1, OUTPUT);
  pinMode(DIRB2, OUTPUT);
  pinMode(PWMC, OUTPUT);
  pinMode(DIRC1, OUTPUT);
  pinMode(DIRC2, OUTPUT);
  pinMode(PWMD, OUTPUT);
  pinMode(DIRD1, OUTPUT);
  pinMode(DIRD2, OUTPUT);
  STOP();
}
void setup()
{
  nh.initNode();
  nh.subscribe(sub1);
  nh.subscribe(sub2);
  nh.subscribe(sub3);
  nh.subscribe(sub4);
//  nh.advertise(pub1);
//  myservo.attach(13);
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
  IO_init();
//  pinMode(PIN_DO, INPUT);
//  pulses = 0;
//  timeOld = 0;
//  attachInterrupt(digitalPinToInterrupt(PIN_DO), counter, FALLING);
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
  if (error == 0) {
    if (pressures)
    {}
    else
    if (rumble)
    Serial.println("true)");
    else
    Serial.println("false");
  }
  else if (error == 1)
  {
//    resetFunc();   
  }

  else if (error == 2)
{}
  else if (error == 3)
{

  type = ps2x.readType();
  switch (type) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  }
}
}

void Manual1() {

  if (control1 == 8 )
  {
  pwm(90);
  ADVANCE();  
  }
  if (control1 == 5 )
  {
  pwm(90);
  BACK();  
  }
  if (control1 == 2 )
  {
  STOP();
  }
  if (control2 == 4 )
  {
  pwm(90);
  LEFT();  
  }
  if (control2 == 6 )
  {
  pwm(90);
  RIGHT();
  }
  
  delay(20);
  //nh.spinOnce();
}

void Manual2() 
{
  ps2x.read_gamepad(false, vibrate); 
  if(ps2x.Button(PSB_PAD_UP))
  {
  pwm(90);
  ADVANCE();  
  }
  else if(ps2x.Button(PSB_PAD_DOWN))
  {
  pwm(90);
  BACK();  
  }
  else if(ps2x.Button(PSB_PAD_LEFT))
  {
  pwm(90);
  LEFT();  
  }
  else if(ps2x.Button(PSB_PAD_RIGHT))
  {
  pwm(90);
  RIGHT();  
  }
  
  if(ps2x.Button(PSB_SELECT))
  {
  STOP();  
  }
  delay(20);
}

void Auto() 
{
  if(dx_rev == 0 && omega_rev == 0)
  STOP();
  if(omega_rev > 0.16)
  {
  pwm(45);
  LEFT();
  delay(20);
  }
  else if(omega_rev < -0.16)
  {
  pwm(45);
  RIGHT();
  delay(20);
  }
  else if(omega_rev >= -0.16 && omega_rev <= 0.16)
  {
    if(dx_rev > 0)
    {
    pwm(90);
    ADVANCE();
    delay(20);
    }
    if(dx_rev < 0)
    {
    pwm(90);
    BACK();
    delay(20);
    }
  }
  //delay(10);
}

void loop() {
  if (mode == 11)  
  {
  Manual1();
  }
  else if(mode == 12)
  {
  Manual2();
  }
  else if(mode == 2)
  {
  Auto();
  }
 // Auto();
//  if (millis() - timeOld >= 1000)
//  {
//    detachInterrupt(digitalPinToInterrupt(PIN_DO));
//    rpm = (pulses * 60) / (HOLES_DISC);
//    timeOld = millis();
//    pulses = 0;
//    attachInterrupt(digitalPinToInterrupt(PIN_DO), counter, FALLING);  
//  }
  
//  encoder.x = rpm;
//  encoder.y = pos;
//  Serial.println(rpm);
//  Serial.println(pos);
  //pub1.publish(&encoder);
  nh.spinOnce();
  delay(10);
}
