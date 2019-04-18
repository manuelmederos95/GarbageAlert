# GarbageAlert

IoT Project for 5AL at ESGI

Goal

The project main Goal is to create an alert system to notify when garbage bin is full and send a notification to the personal in charge

This will decrease the cleaning personal work charge and will avoid having overcharged garbage bins 

The project contains a web application to survey the state of bins

Components

1 Arduino Card ESP8266
1 Photodiode
2 LED lights
1 Laser projector 
2 Resistances of 10k ohms

How it Works ?

The arduino card wil create a Wifi connection. Than it the signal produced by the laser is not captured during a defined time an alert will be send to the ubidot cloud and from the cloud to the web application 

