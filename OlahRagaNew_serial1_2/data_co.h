#include "data_sensor.h"
#include "data_display.h"

bool isData_winsen = false;
int n_winsen = 0;

void data_core(){
  
 if(winsen.available())
  {
    byte in = winsen.read();

    if(isData_winsen)
    {
      buff_winsen[n_winsen] = in;
      n_winsen++;
//      Serial.println("n :" + String(n_winsen));
    }

    if(n_winsen > 26)
    {
      n_winsen = 0;
      isData_winsen = false;
      for(int i = 0; i<sizeof(buff_winsen); i++)
      {
        Serial.print(buff_winsen[i],HEX);
        Serial.print(' ');
      }
      Serial.println();
       data_sensors();
       data_to_next();       
      memset(buff_winsen, 0, sizeof(buff_winsen));
    }

    if(in == 0xff && !isData_winsen)
    {
      buff_winsen[n_winsen] = in;
      isData_winsen = true;
      n_winsen++;
    }
  }
}

  
