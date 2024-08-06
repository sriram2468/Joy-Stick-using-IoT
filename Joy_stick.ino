#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>

  
#define WiFi_NAME "Galaxy"
#define WiFi_PASSWORD "rhql7353"
#define FireBase_HOST "digital-horn-system-21069-default-rtdb.firebaseio.com"
#define FireBase_API "AIzaSyBWNjzjOqTxf1jq8O19fkRugjSJEiMXp0A"



void setup() {
  pinMode(D0, INPUT);// UP
  pinMode(D1, INPUT);// DOWN
  pinMode(D2, INPUT); // RIGHT
  pinMode(D6, INPUT); //LEFT
 
  Serial.begin(9600);
  
  
  WiFi.begin(WiFi_NAME,WiFi_PASSWORD);
  Serial.print("Connecting");
  
  while(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print("Connecting");
    delay(500);
  }

  Serial.println();
  Serial.print("CONNECTED");
  Serial.println(WiFi_NAME);
  
  Firebase.begin(FireBase_HOST, FireBase_API);
  

}

void loop() {
  
  if(digitalRead(D0))
  {
    Serial.print("UP");
    Firebase.setInt("DIRECTION",1);
    
  }
 else if(digitalRead(D1))
 {
  Serial.print("DOWN");
  Firebase.setInt("DIRECTION",2);
 
 }
  else if(digitalRead(D2))
 {
  Serial.print("RIGHT");
  Firebase.setInt("DIRECTION",3);
  
  
 }
  else if(digitalRead(D3))
 {
  Serial.print("LEFT");
  Firebase.setInt("DIRECTION",4);
  
  
 }
 else
 {
  Serial.print("Error Input");
  Firebase.setInt("Direction",0);
 // delay(500);   
  
 }
delay(10);
}
