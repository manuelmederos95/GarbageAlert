#include "UbidotsMicroESP8266.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


#define TOKEN  "BBFF-EOWLPFC2CqXVz6olPpcMMN1VTydEqU"  // Put here your Ubidots TOKEN
#define WIFISSID "ESGI" // Put here your Wi-Fi SSID
#define PASSWORD "Reseau-GES" // Put here your Wi-Fi password
#define maxBlockedTime 3000
#define idPoubelle "5cb73e2c1d847228b8ab8ac3" //Ici id de poubelle
#define BLYNK_PRINT Serial
#define nomPoubelle "POUBELLE2" //name in blink notification 

// You should get Auth Token in the Blynk App.
char auth[] = "9965480b40994ffbb077346f70c5e632";
const int led_green = D0;
const int led_red = D1;
Ubidots client(TOKEN);
int counter = 0;
bool isSend = false;
int pinValue; //reset pinValue
float pinRead0; //photoreceptor read value
WidgetLED led1(V0); //warning led in application


int i = 1;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);

  pinMode(led_green, OUTPUT); // ext. led
  pinMode(led_red, OUTPUT); // ext. led

  pinMode(D7, OUTPUT);
  pinMode(A0, INPUT);
  digitalWrite(D7, 1);
  digitalWrite(led_red, 0);
  client.wifiConnection(WIFISSID, PASSWORD); // Setting wifi connection with ssid and password
  client.add(idPoubelle, 0);
  client.sendAll(false);

  Blynk.begin(auth, WIFISSID, PASSWORD);
  
}



// This function will be called in loop
// Every time Reset button is pushed it will reset counter and turn off warning led in app
BLYNK_WRITE(V1)
{
  pinValue = param.asInt();
  if (pinValue == 1) {
    counter = 0;
    led1.off();
  }
}

// the loop routine runs over and over again forever:
void loop() {
  //execute Blynk function
  Blynk.run();

  // read the input on pin D8:
  pinRead0 = analogRead(A0);
  Serial.print(pinRead0);
  if (pinRead0 < 500) {
    counter++;
    Serial.print(" Blocked ");
    Serial.println(counter);
    if (counter == maxBlockedTime) {
      digitalWrite(led_red, 1);
      Serial.println("EVENT DECLANCHER");
      char mess[] = " IS FULL"; 
      char * fullalert = (char *) malloc(1 + strlen(nomPoubelle)+ strlen(mess) );
      strcpy(fullalert, nomPoubelle);
      strcat(fullalert, mess);
      Serial.println(fullalert);
      Blynk.notify(fullalert);
      led1.on();
      client.add(idPoubelle, 1);
      client.sendAll(false);
    }
  } else {
    Serial.print(" Pass ");
    Serial.println(counter);
    digitalWrite(led_green, 1);
    delay(100);
    digitalWrite(led_green, 0);
    counter = 0;
    led1.off();
  }
}
