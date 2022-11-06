#include<Wire.h>

const int MPU=0x68; 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

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

//void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 //{
  //analogWrite(red_light_pin, red_light_value);
  //analogWrite(green_light_pin, green_light_value);
  //analogWrite(blue_light_pin, blue_light_value);
//}

void loop(){
  //RGB_color(255, 0, 0); // Red
  //delay(1000);
  //RGB_color(0, 255, 0); // Green
  //delay(1000);
  //RGB_color(0, 0, 255); // Blue
  //delay(1000);
  //RGB_color(255, 255, 125); // Raspberry
  //delay(1000);
  //RGB_color(0, 255, 255); // Cyan
  //delay(1000);
  //RGB_color(255, 0, 255); // Magenta
  //delay(1000);
  //RGB_color(255, 255, 0); // Yellow
  //delay(1000);
  //RGB_color(255, 255, 255); // White
  //delay(1000);

  //int buzzer = 10;          

  //tone(buzzer, 262, 250);   
  //delay(325);              
  //noTone(buzzer);           

  //tone(buzzer, 196, 125);
  //delay(162);
  //noTone(buzzer);

  //tone(buzzer, 196, 250);
  //delay(325);
  //noTone(buzzer);

  //tone(buzzer, 220, 250);
  //delay(325);
  //noTone(buzzer);

  //tone(buzzer, 196, 250);
  //delay(325);
  //noTone(buzzer);

  //tone(buzzer, 0, 250);
  //delay(325);
  //noTone(buzzer);

  //tone(buzzer, 247, 250);
  //delay(325);
  //noTone(buzzer);

  //tone(buzzer, 262, 250);
  //delay(325);
  //noTone(buzzer);

  //delay(1000);

  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();  
  
  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(AcX);
  Serial.print(" | Y = "); Serial.print(AcY);
  Serial.print(" | Z = "); Serial.println(AcZ); 
  
  Serial.print("Gyroscope: ");
  Serial.print("X = "); Serial.print(GyX);
  Serial.print(" | Y = "); Serial.print(GyY);
  Serial.print(" | Z = "); Serial.println(GyZ);
  Serial.println(" ");
  delay(333);
}

