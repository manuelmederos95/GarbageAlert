#include "UbidotsMicroESP8266.h"  

#define TOKEN  "BBFF-EOWLPFC2CqXVz6olPpcMMN1VTydEqU"  // Put here your Ubidots TOKEN
#define WIFISSID "ESGI" // Put here your Wi-Fi SSID
#define PASSWORD "Reseau-GES" // Put here your Wi-Fi password
#define maxBlockedTime 10000
#define idPoubelle "5cb73e2c1d847228b8ab8ac3" //Ici id de poubelle

const int led_green = D0;
const int led_red = D1;

Ubidots client(TOKEN);
int counter = 0;
bool isSend = false;

int i = 1;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);

  pinMode(led_green, OUTPUT); // ext. led
  pinMode(led_red, OUTPUT); // ext. led
  
  pinMode(D7, OUTPUT);
  pinMode(A0, INPUT);
  digitalWrite(D7,1);
  digitalWrite(led_red, 0);
  client.wifiConnection(WIFISSID, PASSWORD); // Setting wifi connection with ssid and password
  client.add(idPoubelle, 0);
  client.sendAll(false);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on pin D8:
  float pinRead0 = analogRead(A0);
  Serial.print(pinRead0);
  if (pinRead0 < 500) {
    counter++;
    Serial.print(" Blocked ");
    Serial.println(counter);
    if(counter == maxBlockedTime && isSend == false) {
      digitalWrite(led_red, 1);
      Serial.println("EVENT DECLANCHER");
      isSend = true;
      client.add(idPoubelle, 1);
      client.sendAll(false);
      counter = 0;
    }
  }else {
    Serial.print(" Pass ");
    Serial.println(counter);
    digitalWrite(led_green, 1);
    delay(100);
    digitalWrite(led_green, 0);
    counter = 0;
  }
}
