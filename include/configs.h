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

#ifndef __CONFIGS_H__
#define __CONFIGS_H__


//#define CFG_BOARD_ESP01
#define CFG_BOARD_ESP8266

#define CFG_WIFI_SSID    ""
#define CFG_WIFI_PASSWD  ""

#ifdef CFG_BOARD_ESP01
#define CFG_BOARD_NAME  "esp01"
#endif

#ifdef CFG_BOARD_ESP8266

#define CFG_BOARD_NAME  "esp8266"

#endif

#define CFG_LCD_ADDR    0x27
#define CFG_LCD_COLS    16
#define CFG_LCD_ROWS    2


#endif
