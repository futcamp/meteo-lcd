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

#ifndef __LCD_H__
#define __LCD_H__

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include <memory>


#define LCD_ADDR    0x3F
#define LCD_COLS    16
#define LCD_ROWS    2


typedef enum {
    METEO_DATA_TEMP,
    METEO_DATA_HUM
} MeteoDataType;

typedef struct {
    int value;
    MeteoDataType type;
    int x;
    int y;
} LcdPoint;


class ILcd
{
public:
    virtual void light() = 0;
    virtual void noLight() = 0;
    virtual void clear() = 0;
    virtual void showDatum(int8_t datum, MeteoDataType dtype, uint8_t row, uint8_t col) = 0;
};


class Lcd: public ILcd
{
public:
    Lcd(const std::shared_ptr<LiquidCrystal_I2C> &display);

    void light();

    void noLight();

    void clear();

    void showDatum(int8_t datum, MeteoDataType dtype, uint8_t row, uint8_t col);

private:
    const std::shared_ptr<LiquidCrystal_I2C> display_;
};


#endif
