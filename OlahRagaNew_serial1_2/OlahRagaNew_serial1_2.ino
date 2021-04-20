#include <elapsedMillis.h>
#include "WiFi.h"
#define RXD2 16
#define TXD2 17
#define winsen Serial1
#define nextion Serial2
#include <Arduino.h>
#define LENG 23  
#include "spiff.h"
#include "wifi_init.h"
#define RXD1 4
#define TXD1 2
#include <HTTPClient.h>
#define POOL_DURATION 1000

//winsen
byte cmd_winsen[] = {0xFF,0x01,0x86,0x00,0x00,0x00,0x00,0x00,0x79};
byte buff_winsen[26] = {};
unsigned long counter_winsen = 0;


String temps, pm1s, pm25s, pm10s, co2s, vocs, hums, ch20s, co_s, o3s, no2s;
float temp, pm1, pm25, pm10, co2, voc, hum, ch20, co, o3, no2;


int menu = 0;
bool inMainMenu = true;
String cmd = "";
String cmd1 ="";
String raw ="";
int x,y ;



//unsigned char buf[LENG];
float sensorVoltage; 
int sensorValue=0;
float indexUv=0;


bool IS_CONNECTED = false;

#include "Load_send_data.h"
elapsedMillis timerTick;

void setup() {
  Serial.begin(9600);
  winsen.begin(9600,SERIAL_8N1,RXD1,TXD1);
  nextion.begin(9600, SERIAL_8N1, RXD2, TXD2);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  init_spiff();
  wifi_init();
  Serial.println("Init Wifi");
  Serial.println("coba masukan perintah ++");
  delay(900);
}
unsigned int repeat = 0;

void loop() {

  if(Serial.available()){
    cmd = Serial.readString();
    Serial.print ("ini raw");
    Serial.println (cmd);
    if(cmd == "++" && inMainMenu){
      menu = menu + 1 > 1 ? menu = 0 : menu + 1;
    }
  }

  if(nextion.available()){
    
    raw = nextion.readString();
//    Serial.println ("ini raw");
//    Serial.println (raw.length());
    
    if(raw.length()>15){
     x= raw.indexOf("++");
     cmd1 = raw.substring(x, x+2);
//     Serial.println(cmd1);
    }
    else {
      cmd1=raw;
//      Serial.println(cmd1);
      }
      
      if (cmd1 == "++" && inMainMenu){
          menu = menu + 1 > 1 ? menu = 0 : menu + 1;
       }
  }
      switch(menu){
      case 0:
        inMainMenu = true;
        loadSensor();
        break;
      case 1:
        inMainMenu = false;
        wifiOption();
        break;
    } 

  cmd = "";
  cmd1 = "";
}
