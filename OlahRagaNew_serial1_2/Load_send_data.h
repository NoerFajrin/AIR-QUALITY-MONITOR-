#include "subMenu.h"

#include "data_co.h"


void loadSensor(){
// Serial.println("Gara gara datacore");
  if(millis() - counter_winsen > POOL_DURATION){
  winsen.write(cmd_winsen,sizeof(cmd_winsen));
  counter_winsen = millis();
  }
    data_core();

}

void wifiOption(){
  
  switch(wifiMenu){
    case 0:
      scanWifi();
      break;
    case 1:
      pilihWifi();
      break;
    case 2:
      inputPass();
      break;
    case 3:
      connectWifi();
      break;
    default:
      Serial.println("TIRO");
      break; 
  }
}
