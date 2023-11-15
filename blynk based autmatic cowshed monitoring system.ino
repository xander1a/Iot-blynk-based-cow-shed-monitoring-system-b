

//#define BLYNK_TEMPLATE_ID "TMPLDa5K6ya4"
//#define BLYNK_DEVICE_NAME "cowshed"
//#define BLYNK_AUTH_TOKEN "ousSt83fxKeVe8Wp5BrsLQXTLm4Ni329"
//#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>  
//#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

////////////////////////////////////////////////////////////////////
//char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "I have no life";  // Enter your Wifi Username
char pass[] = "1234567890";  // Enter your Wifi password
///////////////////////////////////////////////////////
Servo myservo;
long trig = D5;
long echo = D6;

long trig2 = D7;
long echo2 = D8;
int servo =D5;
long duration;
long distance;
long duration2;
long distance2;
int pump_pin =A0;
int pin;
int pin2;

//BLYNK_WRITE(V1)
//{
//    pin=param.asInt();
//    Serial.print("servo:");
//    Serial.print(pin);
//    if(pin==0){
//  
//     myservo.write(180); 
//     delay(15);
//  }
//      else if(pin==1){
//      myservo.write(90); 
//      delay(15);
//    }
// 
//   }
//////////////////////////////////////////////////////////////////   
//   BLYNK_WRITE(V2)
//{
//
//  
//  pin2=param.asInt();
//
//  digitalWrite(pump_pin,pin2);
//
//   if(pin2==HIGH){
//     digitalWrite(servo,LOW);
//    
//    }
//else{
//
// digitalWrite(servo,HIGH);  
//}
//
//
//  
//  
//   }

void setup() {
  
   Serial.begin(115200);
  //Blynk.begin(auth, ssid, pass,"blynk-cloud.com", 8080);
 // Blynk.begin(auth, ssid, pass);     
  //Blynk.begin(auth, ssid, pass);  
   myservo.attach(D4);  
   ////////////////////////////////
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
    pinMode(trig2,OUTPUT);
    pinMode(echo2,INPUT);
    pinMode(pump_pin,OUTPUT);
    pinMode(servo,OUTPUT);
    //digitalWrite(pump_pin,LOW);
    //  myservo.write(90); 

}

void loop() {
  water();
  grass();
//   Blynk.virtualWrite(V0, distance);
//   Blynk.run(); 
  Serial.print("pump:");
   Serial.print(pin2);
    Serial.print("servo:");
    Serial.print(pin);
    delay(1000);
}
void water(){
  
  
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance=duration*0.017;
 Serial.println("Distance1:");
  Serial.println(distance);
 if (distance<7){
   // digitalWrite(pump_pin, LOW);
       
      }
        
       
 
}

void grass(){
  
  
  digitalWrite(trig2,LOW);
  delayMicroseconds(2);
  digitalWrite(trig2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2,LOW);
  duration2 = pulseIn(echo2,HIGH);
  distance2=duration2*0.017;
 Serial.println("Distance2:");
  Serial.println(distance2);
 if (distance2<7){
   // digitalWrite(pump_pin, LOW);
       
      }
        
       
 
}
