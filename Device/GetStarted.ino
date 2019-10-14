// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. 
#include "AZ3166WiFi.h"
#include "AzureIotHub.h"
#include "DevKitMQTTClient.h"
#include "OledDisplay.h"
#include "Sensor.h"

#include "config.h"
#include "utility.h"
#include "SystemTickCounter.h"
#include "Arduino.h"
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


// Funtions which display sections of the adventure

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


static void chooseRoad1()
{
      
  Screen.clean();
  Screen.print(1, "2 paths infront");    
  Screen.print(2,"A: Go Left");
  Screen.print(3,"B: Go Right");
  if (digitalRead(USER_BUTTON_A) == LOW)
  {
    //Activates function leftRoad1();   
    app_status =2;
     
  }
  else if (digitalRead(USER_BUTTON_B) == LOW)
  {
    //Activates function rightRoad1(); 
    app_status =3;
  }


}

static void leftRoad1()
{
  Screen.clean();
  Screen.print(1, "A bear infront");    
  Screen.print(2,"A: Approach");
  Screen.print(3,"B: Go Back");

  if (digitalRead(USER_BUTTON_A) == LOW)
  {
    //Goes to approach1() 
    //NOTE: approach1 has not been coded yet, you must do it yourself   
     
    app_status =4;

     
  }
  else if (digitalRead(USER_BUTTON_B) == LOW)
  {
    //Goes back to chooseRoad1(); 
    app_status =1;
  }
}
static void rightRoad1()
{

  //CHANGE THIS TO THE PATH YOU WOULD LIKE IT TO BECOME
  Screen.clean();
  Screen.print(1, "An empty");    
  Screen.print(2,"  path.");
}

static void approach1()
{

  //CHANGE THIS TO THE PATH YOU WOULD LIKE IT TO BECOME
  Screen.clean();
  Screen.print(1, "The bear");    
  Screen.print(2,"killed you.");
  Screen.print(2,"The End.");
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
      case 2:
        leftRoad1();
        break;  
      case 3:
        rightRoad1();
        break;  
      case 4:
        approach1();
        break;    
    }
    
  }
   
  delay(100);
}
