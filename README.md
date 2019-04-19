# GarbageAlert

IoT Project for 5AL at ESGI

**Goal :**

The project main Goal is to create an alert system to notify when garbage bin is full and send a notification to the personal in charge

This will decrease the cleaning personal work charge and will avoid having overcharged garbage bins 

The project contains a web application to survey the state of bins

**Components :**

1. Arduino Card ESP8266
<img src="https://leetechbd.com/wp-content/uploads/2018/01/WeMos-D1-Mini-V2-NodeMcu.jpg" alt="drawing" width="500"/>

2. Photodiode
<img src="https://media.digikey.com/photos/Sharp%20Photos/BS120,520.jpg" alt="drawing" width="500"/>

3. LED lights
<img src="https://www.kitronik.co.uk/media/catalog/product/cache/1/image/9df78eab33525d08d6e5fb8d27136e95/3/5/3550_large_white_5mm_mega_bright_led.jpg" alt="drawing" width="500"/>

4. Laser projector 
<img src="https://leeselectronic.com/26569-home_default/laser-pointer-small-3v-18ma-add-22-ohm-25ma.jpg" alt="drawing" width="500"/>

5. Resistances of 10k ohms
<img src="http://www.elektronique.fr/img/img_pr_news/electronique/resistances/800px-3_Resistors.jpg" alt="drawing" width="500"/>


**How it Works ?**

The arduino card will create a Wifi connection. Than it the signal produced by the laser is not captured during a defined time an alert will be send to the ubidot cloud and from the cloud to the web application and notifications by SMS. 

You need to set up your wifi connection : 
```
#define WIFISSID "xxxx" // Put here your Wi-Fi SSID
#define PASSWORD "xxxxxxxx" // Put here your Wi-Fi password
```

If you want to deploy it with to your own cloud, you need to add the credentials of Ubidots : 

```
#define TOKEN  "BBFF-EOWLPFC2CqXVz6olPpcMMN1VTydEqU"  // Put here your Ubidots TOKEN
#define idPoubelle "5cb73e2c1d847228b8ab8ac3" //Garbage id
```

**Web app :**

The cleaning personal can have the list of the filled garbage bins in the web page with the name of the garbage bin.  


**Problems encountered :**

* **when we wanted to add a buzzer on our Wemos ESP8226 R1 D1**

we tested the example of arduino digital toneKeyboard and the sound never stops
Once launched the sound remains at the same frequency 1000Hz and continues to ring
the delay does not work on it.
the problem is in the function tone() or noTone() ! the function not works
Even with the basic code it does not work:
```bash
int piezoPin = 8;

void setup() {
 
}

void loop() {

  tone(piezoPin, 1000, 500);
 
  //tone(piezoPin, 1000, 500);
  //delay(1000);
}
```
So we dropped the buzzer and we think that is a problem related to the arduino idea

* **when we used Ubidots and Blynk**

We have two solutions to save data in the cloud Ubidots and Blynk.
When we merge these solutions we have a conflict and the processus is slowed down
