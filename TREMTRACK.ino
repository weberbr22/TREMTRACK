#include<Wire.h>

const int MPU=0x68; 
int16_t AcX1,AcY1,AcZ1,Tmp,GyX1,GyY1,GyZ1;
int16_t AcX2,AcY2,AcZ2,GyX2,GyY2,GyZ2;
int16_t AcX3,AcY3,AcZ3,GyX3,GyY3,GyZ3;


int red_light_pin= 4;
int green_light_pin = 5;
int blue_light_pin = 6;

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
  Serial.begin(9600);

  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}

  //analogWrite(red_light_pin, red_light_value);
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}

void Warning(){
  RGB_color(255, 0, 0); // Red
  delay(1000);
  RGB_color(0, 255, 0); // Green
  delay(1000);
  RGB_color(0, 0, 255); // Blue
  delay(1000);
  RGB_color(255, 255, 125); // Raspberry
  delay(1000);
  RGB_color(0, 255, 255); // Cyan
  delay(1000);
  RGB_color(255, 0, 255); // Magenta
  delay(1000);
  RGB_color(255, 255, 0); // Yellow
  delay(1000);
  RGB_color(255, 255, 255); // White
  delay(1000);
}

void input(){

  /*
  int AX[100];
  int AY[100];
  int AZ[100];

  int GX[100];
  int GY[100];
  int GZ[100];
  */

  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  

  AcX1=Wire.read()<<8|Wire.read();    
  AcY1=Wire.read()<<8|Wire.read();  
  AcZ1=Wire.read()<<8|Wire.read();  
  GyX1=Wire.read()<<8|Wire.read();  
  GyY1=Wire.read()<<8|Wire.read();  
  GyZ1=Wire.read()<<8|Wire.read();

  delay(167);

  AcX2=Wire.read()<<8|Wire.read();    
  AcY2=Wire.read()<<8|Wire.read();  
  AcZ2=Wire.read()<<8|Wire.read();  
  GyX2=Wire.read()<<8|Wire.read();  
  GyY2=Wire.read()<<8|Wire.read();  
  GyZ2=Wire.read()<<8|Wire.read();

  delay(167);

  AcX3=Wire.read()<<8|Wire.read();    
  AcY3=Wire.read()<<8|Wire.read();  
  AcZ3=Wire.read()<<8|Wire.read();  
  GyX3=Wire.read()<<8|Wire.read();  
  GyY3=Wire.read()<<8|Wire.read();  
  GyZ3=Wire.read()<<8|Wire.read();

  int X = 0, Y = 0, Z = 0;

  if(AcX1 - AcX2 > 5000 && AcX3 - AcX1 < 2000){
    X = 1;
  }
  else{X=0;}

  if(AcY1 - AcY2 > 5000 && AcY3 - AcY1 < 2000){
    Y = 1;
  }
  else{Y=0;}

  if(AcZ1 - AcZ2 > 5000 && AcZ3 - AcZ1 < 2000){
    Z = 1;
  }
  else{Z=0;}

  if(X=1 && Y=1 && Z=1){
    //Warning();
    Serial.print("WARNING");    
  }
  else{Serial.print("Nothing")}

  /*
  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(AcX1);
  Serial.print(" | Y = "); Serial.print(AcY1);
  Serial.print(" | Z = "); Serial.println(AcZ1); 


  
  Serial.print("Gyroscope: ");
  Serial.print("X = "); Serial.print(GyX1);
  Serial.print(" | Y = "); Serial.print(GyY1);
  Serial.print(" | Z = "); Serial.println(GyZ1);
  Serial.println(" ");
  delay(333);
  */
  
}

void loop(){
  
/*
  int buzzer = 10;          

  tone(buzzer, 262, 250);   
  delay(325);              
  noTone(buzzer);           

  tone(buzzer, 196, 125);
  delay(162);
  noTone(buzzer);

  tone(buzzer, 196, 250);
  delay(325);
  noTone(buzzer);

  tone(buzzer, 220, 250);
  delay(325);
  noTone(buzzer);

  tone(buzzer, 196, 250);
  delay(325);
  noTone(buzzer);

  tone(buzzer, 0, 250);
  delay(325);
  noTone(buzzer);

  tone(buzzer, 247, 250);
  delay(325);
  noTone(buzzer);

  tone(buzzer, 262, 250);
  delay(325);
  noTone(buzzer);

  delay(1000);

*/
  input();
  
}

