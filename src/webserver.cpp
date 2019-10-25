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

#include <Arduino.h>
#include <functional>
#include <ESP8266WiFi.h>

#include "webserver.h"
#include "configs.h"


WebServer::WebServer(const std::shared_ptr<ESP8266WebServer> &server,
                        const std::shared_ptr<IHdk> &hdk,
                        const std::shared_ptr<ILcd> &lcd):
                     server_(std::move(server)),
                     hdk_(std::move(hdk)),
                     lcd_(std::move(lcd))
{
}

void WebServer::start()
{
    server_->on("/", std::bind(&WebServer::indexHandler, this));
    server_->on("/display", std::bind(&WebServer::displayHandler, this));
    server_->on("/update", std::bind(&WebServer::updateHandler, this));
    server_->onNotFound(std::bind(&WebServer::notFoundHandler, this));
    server_->begin();

    lcdPts[0].x =  0;
    lcdPts[0].y =  0;

    lcdPts[1].x =  0;
    lcdPts[1].y =  4;

    lcdPts[2].x =  0;
    lcdPts[2].y =  8;

    lcdPts[3].x =  0;
    lcdPts[3].y =  12;

    lcdPts[4].x =  1;
    lcdPts[4].y =  0;

    lcdPts[5].x =  1;
    lcdPts[5].y =  4;

    lcdPts[6].x =  1;
    lcdPts[6].y =  8;

    lcdPts[7].x =  1;
    lcdPts[7].y =  12;

    for (int i = 0; i < 8; i++)
        data[i] = 0;
}

void WebServer::process()
{
    server_->handleClient();
}

/*
 * Private functions
 */

String WebServer::getDevId()
{
    String id = "";

    for (auto c : WiFi.macAddress())
        if (c != ':')
            id += c;
    id.toLowerCase();

    return id;
}

void WebServer::indexHandler()
{
    String response;

    response = "{\"module\":\"meteo-lcd\",\"id\":\"" + getDevId() +
               "\",\"board\":\"" + CFG_BOARD_NAME + "\"}";

    server_->send(WEB_SERVER_RESPONSE_OK, "application/json", response);
}

void WebServer::displayHandler()
{
    String  response;

    lcd_->clear();
    for (int i = 0; i < 8; i++)
    {
        if (lcdPts[i].value != 0)
        {
            lcd_->showDatum(lcdPts[i].value, lcdPts[i].type, lcdPts[i].x, lcdPts[i].y);
        }
    }

    server_->send(WEB_SERVER_RESPONSE_OK, "application/json", "{\"result\":true}");
}

void WebServer::updateHandler()
{
    MeteoDataType type = METEO_DATA_TEMP;
    String  response;

    int id = server_->arg("id").toInt();
    int value = server_->arg("value").toInt();
    String sType = server_->arg("type");

    if (sType == "temp")
    {
        type = METEO_DATA_TEMP;
    }
    else if (sType == "hum")
    {
        type = METEO_DATA_HUM;
    }

    lcdPts[id].type = type;
    if (value == 0)
        lcdPts[id].value = 1;
    else
        lcdPts[id].value = value;

    server_->send(WEB_SERVER_RESPONSE_OK, "application/json", "{\"result\":true}");
}

void WebServer::notFoundHandler()
{
    String response;

    response = "{\"module\":\"meteo-lcd\",\"error\":\"Not found\"}";

    server_->send(WEB_SERVER_RESPONSE_OK, "application/json", response);
}
