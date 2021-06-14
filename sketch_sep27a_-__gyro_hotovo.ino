// MPU-6050 Short Example Sketch
// By Arduino User JohnChi
// August 17, 2014
// Public Domain
#include<Wire.h>
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
void setup(){

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
}
void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  
  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.println(AcY);
  delay(500);

  if(AcX >= 0){
    Serial.println("Pravý náklon");
  }
  else{
    Serial.println("Levý náklon");
  }
  
  
//+ hodnoty x
  
  if(AcX >= 1500 && AcX <= 3500 ){
    digitalWrite(5, HIGH); 
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH); 
  }
  
  else if(AcX >= 3500 && AcX <= 6000){
    digitalWrite(5, HIGH); 
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW); 
  }
  
  else if(AcX >= 6000){
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  
//- hodnoty x

  else if(AcX >= -1500){
    digitalWrite(5, LOW); 
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH); 
  }
  
  else if(AcX <= -1500 && AcX >= -3500 ){
    digitalWrite(5, HIGH); 
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH); 
  }
  
  else if(AcX <= -3500 && AcX >= -6000){
    digitalWrite(5, HIGH); 
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW); 
  }
  
  else if(AcX <= -6000){
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }


  if(AcY >= 0){
    Serial.println("Klesání");
  }
  else{
    Serial.println("Stoupání");
  }
  
  //+ hodnoty y
  
  if(AcY >= 1500 && AcY <= 3500 ){
    digitalWrite(8, HIGH); 
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH); 
  }
  
  else if(AcY >= 3500 && AcY <= 6000){
    digitalWrite(8, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW); 
  }
  
  else if(AcY >= 6000){
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
  }
  
//- hodnoty y

  else if(AcY >= -1500){
    digitalWrite(8, LOW); 
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH); 
  }
  
  else if(AcY <= -1500 && AcY >= -3500 ){
    digitalWrite(8, HIGH); 
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH); 
  }
  
  else if(AcY <= -3500 && AcY >= -6000){
    digitalWrite(8, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW); 
  }
  
  else if(AcY <= -6000){
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
  }
  
}
