// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. 
// To get started please visit https://microsoft.github.io/azure-iot-developer-kit/docs/projects/connect-iot-hub?utm_source=ArduinoExtension&utm_medium=ReleaseNote&utm_campaign=VSCode
#include "AZ3166WiFi.h"
#include "AzureIotHub.h"
#include "DevKitMQTTClient.h"
#include "OledDisplay.h"
#include "Sensor.h"

#include "config.h"
#include "utility.h"
#include "SystemTickCounter.h"
#include "Arduino.h"
//#define RGB_LED_BRIGHTNESS  32
//static RGB_LED rgbLed;
static bool hasWifi = false;
int btnAState;
int btnBState;
int app_status = 0;

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Utilities
static void InitWifi()
{
  Screen.print(2, "Connecting...");
  
  if (WiFi.begin() == WL_CONNECTED)
  {
    IPAddress ip = WiFi.localIP();
    Screen.print(1, ip.get_address());
    hasWifi = true;
    Screen.print(2, "Running... \r\n");
  }
  else
  {
    hasWifi = false;
    Screen.print(1, "No Wi-Fi\r\n ");
  }
}

static void chooseRoad1()
{
      
  Screen.clean();
  Screen.print(1, "2 paths infront");    
  Screen.print(2,"A: Go Left");
  Screen.print(3,"B: Go Right");
  if (digitalRead(USER_BUTTON_A) == LOW)
  {
    //chooseRoad1();   
    //app_status =2;
     
  }
  else if (digitalRead(USER_BUTTON_B) == LOW)
  {
    //chooseRoad1();  
    //app_status =3;
  }


}

static void startAdventure()
{
  blinkLED();
  Screen.print(1, "Welcome to ");
  Screen.print(2, "Floop! Choose ");
  Screen.print(3,"your path wisely");
  

  if (digitalRead(USER_BUTTON_A) == LOW)
    {
      //chooseRoad1();   
      app_status =1;
      
    }
    else if (digitalRead(USER_BUTTON_B) == LOW)
    {
      //chooseRoad1();  
      app_status =1;
    }
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Arduino sketch
void setup()
{
  Screen.init();
  Screen.print(0, "IoT DevKit");
  Screen.print(2, "Initializing...");
  
  Screen.print(3, " > Serial");
  Serial.begin(115200);

  // Initialize the WiFi module
  Screen.print(3, " > WiFi");
  hasWifi = false;
  InitWifi();
  if (!hasWifi)
  {
    return;
  }

  // Initialize button
  pinMode(USER_BUTTON_A, INPUT);
  pinMode(USER_BUTTON_B, INPUT);
  btnAState = digitalRead(USER_BUTTON_A);
  btnBState = digitalRead(USER_BUTTON_B);
  


}

void loop()
{
  if (hasWifi)
  {
    switch(app_status)
    {
      case 0:
        startAdventure();
        break;
      case 1:
        chooseRoad1();
        break;
    }
    
  }
   
  delay(1000);
}
