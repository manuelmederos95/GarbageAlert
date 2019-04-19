# Problems encountered :

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

