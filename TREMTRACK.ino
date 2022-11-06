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

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}

void Warning(){
  RGB_color(255, 0, 0); // Red
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

  int Sensvals[1000];
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  

  for(int i = 0; i<8; i+3){

    AcX1=Wire.read()<<8|Wire.read();    
    AcY1=Wire.read()<<8|Wire.read();  
    AcZ1=Wire.read()<<8|Wire.read();

    Sensvals[i] = AcX1;
    Sensvals[i+1] = AcY1;
    Sensvals[i+2] = AcZ1;

    delay(167);
  }

  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(Sensvals[0]);
  Serial.print(" | Y = "); Serial.print(Sensvals[1]);
  Serial.print(" | Z = "); Serial.println(Sensvals[2]); 

  Serial.print("X = "); Serial.print(Sensvals[3]);
  Serial.print(" | Y = "); Serial.print(Sensvals[4]);
  Serial.print(" | Z = "); Serial.println(Sensvals[5]); 

  Serial.print("X = "); Serial.print(Sensvals[6]);
  Serial.print(" | Y = "); Serial.print(Sensvals[7]);
  Serial.print(" | Z = "); Serial.println(Sensvals[8]); 



  



  

  /*

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

  if(AcX1 - AcX2 > 3000 && AcX3 - AcX1 < 2000){
    X = X+1;
  }
  else{}

  if(AcY1 - AcY2 > 3000 && AcY3 - AcY1 < 2000){
    Y = Y+1;
  }
  else{}

  if(AcZ1 - AcZ2 > 3000 && AcZ3 - AcZ1 < 2000){
    Z = Z+1;
  }
  else{}

  if(X==1 && Y==1 && Z==1){
    //Warning();
    //Serial.print("WARNING");    
  }
  else{Serial.print("Nothing");}

  */
  
}

void loop(){

  input();
  Warning();
}

