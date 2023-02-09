#include <Blynk.h>
#include <BlynkSimpleEsp32.h>
#include <WiFi.h>
#include <WiFiClient.h>
unsigned long previousMillis = 0;
unsigned long interval = 600000;
#define x1 1
#define x2 2
#define y1 3
#define y2 4
#define z1 5
#define z2 6
#define v 7
#define sx1 8
#define sx2 9
#define sy1 10
#define sy2 11
#define sz1 12
#define sz2 13
#define sv A0

BLYNK_WRITE(V0){
    int value = param.asInt();
    
    if (value == 1){

int vacuoLig = 0;
int passos = 0;
  if (digitalRead(sx1) == true && passos == 0){
  digitalWrite(x1, HIGH);
  passos = 1;
  
  } 
   if (digitalRead(sx2) == true && digitalRead(sy1) == true && passos == 1 )
{
   digitalWrite(y1, HIGH);
  digitalWrite(x1, LOW); 
     passos = 2;

  }
  
   if (digitalRead(sy2) == true && digitalRead(sz1) == true && passos == 2)
{
  digitalWrite(z1, HIGH);
  digitalWrite(y1, LOW);
     passos = 3;

  }
     if (digitalRead(sx2) == true && digitalRead(sy2) == true && digitalRead(sz2) == true && passos == 3)
{
    delay(3000);
  digitalWrite(z1,LOW); 
  digitalWrite(v, HIGH);
  vacuoLig = 1;
       passos = 4;
     
  }
if (vacuoLig == 1 && passos == 4){
    delay(1500);
  digitalWrite(z2, HIGH);
    passos = 5;
}
 if(digitalRead(sz1)== true && vacuoLig == 1 && passos == 5)
 {
  delay(1500);
   digitalWrite(y2, HIGH);
   digitalWrite(z2, LOW);
   passos = 6;
 }
 if(digitalRead(sy1)== true && vacuoLig == 1 && passos == 6)
 {
   delay(1500);
   digitalWrite(x2, HIGH);
   digitalWrite(y2, LOW);
   passos = 7;
 }
  if(digitalRead(sx1)== true && vacuoLig == 1 && passos == 7)
 {
   delay(1500);
   digitalWrite(y1, HIGH);
   digitalWrite(x2, LOW);
   passos = 8;
 }
  
   if(digitalRead(sy2)== true && vacuoLig == 1 && passos == 8)
 {
   delay(1500);
   digitalWrite(z1, HIGH);
   digitalWrite(y1, LOW);
   passos = 9;
 }
   if(digitalRead(sz2)== true && vacuoLig == 1 && passos == 9)
 {
   delay(1500);
   digitalWrite(v, LOW);
   digitalWrite(z1, LOW);
   passos = 10;
   vacuoLig = 0;  
 }
   if(digitalRead(sz2)== true && vacuoLig == 0 && passos == 10)
 {
   delay(1500);
  digitalWrite(y1, LOW);
  digitalWrite(z1, LOW);   
  digitalWrite(y2, HIGH);
  digitalWrite(z2, HIGH);  
  passos = 11;   
 }
  if(digitalRead(sx1) == true && digitalRead(sy1) == true && digitalRead(sz1)== true && vacuoLig == 0 && passos == 11)
 {
   
    digitalWrite(y2, LOW);
  digitalWrite(z2, LOW);  
   delay(5000); 
  passos = 0;   
 }
      }

      else{
  digitalWrite(x1, LOW);
  digitalWrite(x2, LOW); 
  digitalWrite(y1, LOW);
  digitalWrite(y2, LOW); 
  digitalWrite(z1, LOW);
  digitalWrite(z2, LOW); 
  digitalWrite(v, LOW);
      }
}
BLYNK_WRITE(V1){
  int value2 = param.asInt();
  if(value2 == 1){
    digitalWrite(x1, HIGH);
  }
  else{
    digitalWrite(x1, LOW);
    }
  }
  BLYNK_WRITE(V2){
  int value3 = param.asInt();
  if(value3 == 1){
    digitalWrite(x2, HIGH);
  }
  else{
    digitalWrite(x2, LOW);
    }
  }
 BLYNK_WRITE(V3){
  int value4 = param.asInt();
  if(value4 == 1){
    digitalWrite(y1, HIGH);
  }
  else{
    digitalWrite(y1, LOW);
    }
  }
 BLYNK_WRITE(V4){
  int value5 = param.asInt();
  if(value5 == 1){
    digitalWrite(y2, HIGH);
  }
  else{
    digitalWrite(y2, LOW);
    }
  }
 BLYNK_WRITE(V5){
  int value6 = param.asInt();
  if(value6 == 1){
    digitalWrite(z1, HIGH);
  }
  else{
    digitalWrite(z1, LOW);
    }
  }
 BLYNK_WRITE(V6){
  int value7 = param.asInt();
  if(value7 == 1){
    digitalWrite(z2, HIGH);
  }
  else{
    digitalWrite(z2, LOW);
    }
  }
 BLYNK_WRITE(V7){
  int value8 = param.asInt();
  if(value8 == 1){
    digitalWrite(v, HIGH);
  }
  else{
    digitalWrite(v, LOW);
    }
  }
 
 



void setup() {
#define BLYNK_TEMPLATE_ID "TMPL4QCE0Xzw"
#define BLYNK_DEVICE_NAME "esp"
#define BLYNK_AUTH_TOKEN "mfRZEb7Xg3HCfZifN5OMbHYuk5RxoDtb"
#define BLYNK_PRINT Serial
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "CLARO_2G0A870D";
char pass[] = "380A870D";
BlynkTimer timer;

  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);
  pinMode(13,INPUT_PULLUP);
  pinMode(A0,INPUT_PULLUP);



Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
Serial.begin(115200);



}


void loop() {
  Blynk.run();
  unsigned long currentMillis = millis();
  //se a conexão cair tenta reconectar
// if WiFi is down, try reconnecting
if (currentMillis - previousMillis >=interval){
  Serial.println(millis());
  Serial.print("Reconnecting to WiFi...");
  ESP.restart();
  previousMillis = currentMillis;
}
  
}
