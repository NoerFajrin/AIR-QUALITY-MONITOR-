void data_sensors(){
  // temp, pm1, pm25, pm10, co2, voc, hum, ch20, co, o3, no2;
  //temperature formula
      temp = ((((buff_winsen[11]*256)+ buff_winsen[12])-500)*0.1)*1.2;
      Serial.print("Temperature = ");
      temps = String (temp, 0); 
      Serial.print(temps);
   //PM1 formula
      pm1 = ((buff_winsen[2]*256)+ buff_winsen[3]);
      Serial.print("  PM 1.0 = ");
      pm1s = String (pm1);
      Serial.print(pm1s);
   //PM25
      pm25 = ((buff_winsen[4]*256)+ buff_winsen[5]);
      Serial.print("  PM 2.5 = ");
      pm25s = String (pm25);
      Serial.print(pm25s);
    //PM10
      pm10 = ((buff_winsen[6]*256)+ buff_winsen[7]);
      Serial.print("  PM 10 = ");
      pm10s = String (pm10);
      Serial.print(pm10s);
    //co2
      co2 = ((buff_winsen[8]*256)+ buff_winsen[9]);
      Serial.print("  CO2 = ");
      co2s = String (co2);
      Serial.print(co2s);
    //voc
      voc = buff_winsen[10];
      Serial.print("  VOC = ");
      vocs = String (voc);
      Serial.print(vocs);
    //ch20
      ch20 = ((buff_winsen[15]*256)+ buff_winsen[16])*0.001;
      Serial.print("  CH2O = ");
      ch20s = String (ch20);
      Serial.print(ch20s);
    //c0
      co = ((buff_winsen[17]*256)+ buff_winsen[18])*0.1;
      Serial.print("  CO = ");
      co_s = String (co);
      Serial.print(co_s);
     //03
      o3 = ((buff_winsen[19]*256)+ buff_winsen[20])*0.01;
      Serial.print("  O3 = ");
      o3s = String (o3);
      Serial.print(o3s);
    //NO2
      no2 = ((buff_winsen[21]*256)+ buff_winsen[22])*0.01;
      Serial.print("  NO2 = ");
      no2s = String (no2);
      Serial.print(no2s);
    //hum
      hum = ((buff_winsen[13]*256)+ buff_winsen[14]);
      Serial.print("  Humidity = ");
      hums = String (hum, 0);
      Serial.println(hums);

      //temps, pm1s, pm25s, pm10s, co2s, vocs, hums, ch20s, co_s, o3s, no2s;
    String post_data = "{";
    post_data += "\"temp\":";
    post_data += temps;
    post_data += ",";
    post_data += "\"hum\":";
    post_data += hums;
    post_data += ",";
    post_data += "\"co2\":";
    post_data += co2s;
    post_data += ",";
    post_data += "\"co\":";
    post_data += co_s;
    post_data += ",";
    post_data += "\"pm1\":";
    post_data += pm1s;
    post_data += ",";
    post_data += "\"pm25\":";
    post_data += pm25s;
    post_data += ",";
    post_data += "\"pm10\":";
    post_data += pm10s;
    post_data += ",";
    post_data += "\"O3\":";
    post_data += o3s;
    post_data += ",";
    post_data += "\"no2\":";
    post_data += no2s;
    post_data += ",";
    post_data += "\"uv\":";
    post_data += hums;
    post_data += "}";
    
    Serial.println (post_data);
    
      HTTPClient http;   
      
       http.begin("http://ptsv2.com/t/nextion/post");  //Specify destination for HTTP request
       http.addHeader("Content-Type", "application/json");             //Specify content-type header
                                        // "followers" : 987 
       int httpResponseCode = http.POST(post_data);   //Send the actual POST request
      
       if(httpResponseCode>0){
        String response = http.getString();                       //Get the response to the request
        Serial.println(httpResponseCode);   //Print return code
        Serial.println(response);           //Print request answer
       }
       else{
        Serial.print("Error on sending POST: ");
        Serial.println(httpResponseCode);
       }
       http.end();  //Free resources
  }
