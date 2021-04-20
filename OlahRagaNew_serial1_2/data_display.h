void data_to_next(){
  nextion.print("hum.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print(hums);  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);
  
  nextion.print("temp.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print(temps);  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);
  
  nextion.print("co.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print(co_s);  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);

  nextion.print("co2.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print(co2s);  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);

  nextion.print("voc.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print(vocs);  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);

  nextion.print("ch2o.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print(ch20s);  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);

  nextion.print("o3.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print(o3s);  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);

  nextion.print("no2.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print(no2s);  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);

  nextion.print("pm1.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print(pm1s);  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);

  nextion.print("pm25.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print(pm25s);  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);

  nextion.print("AQ.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print(pm25s);  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);

  nextion.print("pm10.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print(pm10s);  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);
  
  
  if(pm25>= 0 && pm25 <= 50){
  nextion.print("statAQ.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print("GOOD");  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);
  }
  if(pm25>= 51 && pm25 <= 100){
  nextion.print("statAQ.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print("MODERATE");  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);
  }

  if(pm25>= 101 && pm25 <= 150){
  nextion.print("statAQ.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print("UNHEALTHY");  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);
  }

  if(pm25>= 151 && pm25 <= 200){
  nextion.print("statAQ.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print("UNHEALTHY");  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);
  }

  if(pm25>= 201 && pm25 <= 300){
  nextion.print("statAQ.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print("VERY UNHEALTH");  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);
  }
  
  if(pm25>= 201 && pm25 <= 300){
  nextion.print("statAQ.txt=");
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.print("HAZARDOUS");  // This is the text we want to send to that object and atribute mention before.
  nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
  nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  nextion.write(0xff);
  nextion.write(0xff);
  }
  }
