//*******************************************************************
//
// Future Camp Project
//
// Copyright(C) 2019 Sergey Denisov.
//
// Written by Sergey Denisov aka LittleBuster(DenisovS21@gmail.com)
// Github:  https://github.com/LittleBuster
//          https://github.com/futcamp
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public Licence 3
// as published by the Free Software Foundation; either version 3
// of the Licence, or(at your option) any later version.
//
//*******************************************************************

#include "hdk.h"
#include "configs.h"

#include <ESP8266WiFi.h>
#include <Arduino.h>


Hdk::Hdk()
{
}

void Hdk::switchPinMode(uint8_t pin, HdkPinModes mode)
{
    switch (mode)
    {
        case HDK_PIN_MODE_IN:
            pinMode(pin, INPUT);
            break;

        case HDK_PIN_MODE_OUT:
            pinMode(pin, OUTPUT);
            break;

        case HDK_PIN_MODE_IN_PULL_UP:
            pinMode(pin, INPUT_PULLUP);
            break;
    }
}

void Hdk::pinHigh(uint8_t pin)
{
    digitalWrite(pin, HIGH);
}

void Hdk::pinLow(uint8_t pin)
{
    digitalWrite(pin, LOW);
}

bool Hdk::readPin(uint8_t pin)
{
    if (digitalRead(pin) == LOW)
        return true;

    return false;
}

void Hdk::connectWifi(const String &ssid, const String &passwd)
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, passwd);

    while (WiFi.status() != WL_CONNECTED) 
    {
        sleep(500);
    }
}

unsigned long int Hdk::getCurSeconds()
{
    return millis() / 1000;
}

void Hdk::sleep(unsigned millis)
{
    delay(millis);
}
