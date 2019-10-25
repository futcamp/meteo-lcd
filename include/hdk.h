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

#ifndef __HDK_H__
#define __HDK_H__

#include <Arduino.h>
#include <memory>


typedef enum {
    HDK_PIN_MODE_IN,
    HDK_PIN_MODE_OUT,
    HDK_PIN_MODE_IN_PULL_UP
} HdkPinModes;


class IHdk
{
public:
    virtual void switchPinMode(uint8_t pin, HdkPinModes mode) = 0;
    virtual void pinHigh(uint8_t pin) = 0;
    virtual void pinLow(uint8_t pin) = 0;
    virtual bool readPin(uint8_t pin) = 0;
    virtual void connectWifi(const String &ssid, const String &passwd) = 0;
    virtual unsigned long int getCurSeconds() = 0;
    virtual void sleep(unsigned millis) = 0;
};


class Hdk: public IHdk
{
public:
    Hdk();

    /*
     * @breif Switching current pin mode
     *
     * @param [in] pin GPIO number
     * @param [in] mode New pin mode
     */
    void switchPinMode(uint8_t pin, HdkPinModes mode);

    /*
     * @breif Set high state to pin
     *
     * @param [in] pin GPIO number
     */
    void pinHigh(uint8_t pin);

    /*
     * @breif Set low state to pin
     *
     * @param [in] pin GPIO number
     */
    void pinLow(uint8_t pin);

    /*
     * @breif Reading pin state
     *
     * @param [in] pin GPIO number
     *
     * @returns true If pin has low state
     * @returns false If pin has high state
     */
    bool readPin(uint8_t pin);

    /*
     * @breif Connecting to WiFi spot
     *
     * @param [in] ssid Spot name
     * @param [in] passwd Spot password
     */
    void connectWifi(const String &ssid, const String &passwd);

    /*
     * @breif Get current seconds from start
     *
     * @returns seconds
     */
    unsigned long int getCurSeconds();

    /*
     * @breif Waiting
     *
     * @param [in] millis Milliseconds
     */
    void sleep(unsigned millis);
};


#endif
