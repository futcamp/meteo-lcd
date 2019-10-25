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

#include "lcd.h"


static uint8_t tempCel[8] = { B11100,
                              B10100,
                              B11100,
                              B00000,
                              B00000,
                              B00000,
                              B00000 };


Lcd::Lcd(const std::shared_ptr<LiquidCrystal_I2C> &display):
              display_(std::move(display))
{
    Wire.begin(D1, D2);
    display_->init();
    display_->init();
    display_->backlight();
    display_->createChar(1, tempCel);
    display_->setCursor(0, 0);
    display_->clear();
    display_->print("  Future Camp");
    display_->setCursor(0, 1);
    display_->print(" Meteo Display");
}

void Lcd::clear()
{
    display_->clear();
}

void Lcd::light()
{
    display_->backlight();
}

void Lcd::noLight()
{
    display_->noBacklight();
}

void Lcd::showDatum(int8_t datum, MeteoDataType dtype, uint8_t row, uint8_t col)
{
    display_->setCursor(col, row);
  
    if (datum > 0)
        display_->print(' ');

    if (datum < 10 && datum > -10)
        display_->print(' ');

    display_->print(datum);

    switch (dtype)
    {
        case METEO_DATA_TEMP:
            display_->print("\1");
            break;
      
        case METEO_DATA_HUM:
            display_->print("%");
            break;
    }
}
