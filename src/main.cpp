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

#include "configs.h"
#include "hdk.h"
#include "webserver.h"
#include "app.h"
#include "lcd.h"


auto display = std::make_shared<LiquidCrystal_I2C>(CFG_LCD_ADDR, CFG_LCD_COLS, CFG_LCD_ROWS);
auto lcd = std::make_shared<Lcd>(display);
auto http = std::make_shared<ESP8266WebServer>();
auto hdk = std::make_shared<Hdk>();
auto server = std::make_shared<WebServer>(http, hdk, lcd);
auto app = std::make_shared<App>(hdk, server);


void setup()
{
    app->start();
}

void loop()
{
    app->loop();
}
