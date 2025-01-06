#define BLYNK_TEMPLATE_ID "TMPL3yzDLnK6J"
#define BLYNK_TEMPLATE_NAME "fire"
#define BLYNK_AUTH_TOKEN "hyk-b5KP3stpBsXUPKwwifFUwlSXGjwn"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
 
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "987654321";  // type your wifi name
char pass[] = "987654321";  // type your wifi password
 

BlynkTimer timer;
int flag=0; 
void sendSensor(){ 
   int isButtonPressed = digitalRead(D1);
  if (isButtonPressed==0 && flag==0) {
    Serial.println("Fire in the House");  
    //Blynk.email("testemail@gmail.com", "Alert", "Fire Detected!");
    Blynk.logEvent("fire","Fire Detected");
    
    flag=1;
  }
  else if (isButtonPressed==1)
  {
    flag=0;
    
  }
  if(value < 50){
    Blynk.
  }


 
}

void setup(){
  pinMode(D1, INPUT);
 
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  //dht.begin();
  timer.setInterval(5000L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}