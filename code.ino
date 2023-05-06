#include <Servo.h>

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

Servo servo;

char auth[] = "NbaPH_I56JM0Phu42167h4qejhfTD6reL";//Enter your Blynk auth token

char ssid[] = "abc";//Enter your WIFI name

char pass[] = "12345678";//Enter your WIFI password

void setup() {

    Serial.begin(9600);
    servo.attach(D8);
    servo.write(0);
    Blynk.begin(auth, ssid, pass);

}

void loop() {
  
  Blynk.run();

}

int d,z;
BLYNK_WRITE(V5){

  z = param.asInt();

}
BLYNK_WRITE(V4){

  int y = param.asInt();
  
  if(1<=y && y<=3){
    if(z==1) d=1000;
    if(z==2) d=2000;
    if(z==3) d=3000;
  }
  if(4<=y && y<=6){
    if(z==1) d=4000;
    if(z==2) d=5000;
    if(z==3) d=6000;
  }  
  if(7<=y && y<=9){
    if(z==1) d=7000;
    if(z==2) d=8000;
    if(z==3) d=9000;
  } 


}

BLYNK_WRITE(V2){

  int x = param.asInt();
  if(x==0){
    servo.write(180); 
    delay(d);   
    servo.write(0);
  }
  

}
