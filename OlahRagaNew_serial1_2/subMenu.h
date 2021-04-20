int wifiMenu = 0;
bool waitingInput = false;
String ssid_list[10] = {"","","","","","","","","",""};
String ssid = "";
String password = "";

void scanWifi(){
  Serial.println("Scanning SSID :");
  int n = WiFi.scanNetworks();
  if (n == 0) {
    Serial.println("no networks found");
  }
  else{
    
    if(n>9)
    {
      n=9;
    }
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      String id = "wifi" + String(i + 1) + ".txt=";
      nextion.print(id);  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
      nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
      nextion.print(WiFi.SSID(i));  // This is the text we want to send to that object and atribute mention before.
      //Serial.println(WiFi.SSID(i));  // This is the text we want to send to that object and atribute mention before.//
      nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
      nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
      nextion.write(0xff);
      nextion.write(0xff);
        Serial.print(i);
        Serial.print(": ");
        ssid_list[i] = (String)WiFi.SSID(i);
        //Serial.print(WiFi.SSID(i));//
        Serial.print(ssid_list[i]);//
        Serial.print(" (");//
        //Serial.print(WiFi.RSSI(i));//
        Serial.print(")");//
        Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");///
        nextion.print("wifi0.txt=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
        nextion.print("networks found");  // This is the text we want to send to that object and atribute mention before.
        nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
        nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        nextion.write(0xff);
        nextion.write(0xff);

        delay(10);
    }
     Serial.println();
    Serial.println("Pilih Wifi dengan memasukan angka diawali tanda #");
    waitingInput = true;
  }
  wifiMenu++;
}

void pilihWifi(){
  if(waitingInput)
  {
    if(cmd[0] == '#'){
       Serial.println(cmd);
      int input = cmd.substring(1,1).toInt();
      Serial.println(input);
      ssid = ssid_list[input];
      Serial.print("SSID \"");
      Serial.print(ssid);
      Serial.print("\" telah dipilih");
      Serial.println();
      waitingInput = false;
    }
     if(cmd == "+")
    {
      wifiMenu = 0;
      menu = 0;
    }
  
    if(cmd1[0] == '#'){
      int input1 = cmd1.substring(1,1).toInt();
      //int input1 = cmd1.substring(1,cmd1.length()).toInt();
      ssid = ssid_list[input1];
      nextion.print("cwifi.txt=");
      nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
      nextion.print(ssid);
      nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
      nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
      nextion.write(0xff);
      nextion.write(0xff);
      Serial.print("SSID \"");
      Serial.print(ssid);
      Serial.print("\" telah dipilih");
      Serial.println();
      waitingInput = false;
    }
    if(cmd1 == "+")
    {
      wifiMenu = 0;
      menu = 0;
    }
  
  }
  else{
    wifiMenu++;
  }
}

void inputPass(){
  
  if(waitingInput){
    
    if(cmd[0] == '#')
    {
      password = cmd.substring(1,cmd.length());
      Serial.print("Password telah dimasukan : \"");
      Serial.print(password);
      Serial.println("\"");
      wifiMenu++;
    }
     if(cmd == "+")
    {
      wifiMenu = 0;
      menu = 0;
    }
      if(cmd1[0] == '#'){
//        cmd1 = raw.substring(7,raw.length());
//        Serial.print("input pass :  ");
//        Serial.println(cmd1);
      password = cmd1.substring(1,cmd1.length());
      Serial.print("Password telah dimasukan : \"");
      Serial.print(password);
      Serial.println("\"");
      wifiMenu++;
    }
     if(cmd1 == "+")
    {
      wifiMenu = 0;
      menu = 0;
    } 
  }
  else{
    Serial.println("Masukan Password diawali tanda #");
    WiFi.disconnect();
    waitingInput = true;
  }
}

void connectWifi(){
  Serial.println("Mencoba menghubungkan ke jaringan");
//  WiFi.begin("Kirei-lt2","berakitkehulult2");
  WiFi.begin(ssid.c_str(),password.c_str());
  
  String network_json = "";
  network_json += "{\"SSID\":\"";
  network_json += ssid.c_str();
  network_json += "\",\"PASSWORD\":\"";
  network_json += password.c_str();
  network_json += "\"}";
  Serial.println (network_json);
  
  long int startTime = millis();
  while (WiFi.status() != WL_CONNECTED && (startTime + 10000) > millis()) {
        //jangan ngapa ngapain selama 10 detik
    }
    if (WiFi.status() == WL_CONNECTED) {
            
      writeFile(SPIFFS, "/network.json", network_json.c_str());
      readFile(SPIFFS, "/network.json");
      
              
        Serial.println("WiFi connected");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
        Serial.println();
        Serial.println("Kembali ke menu utama");
        Serial.println();

        
        wifiMenu = 0;
        menu = 0;
        IS_CONNECTED = true;
    }
    else {
      Serial.println("Gagal terhubung ke WiFi");
      Serial.println("Mengulang...");      
      wifiMenu = 0;
  }
}
void wifi_stat_nextion(){


      if(IS_CONNECTED == true){
        Serial.print("icwifi.pic=24");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial.write(0xff);
        Serial.write(0xff);
        }
      String ip_auto=WiFi.localIP().toString();
      nextion.print("ssid.txt=");
      nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
      nextion.print("Connected");  // This is the text we want to send to that object and atribute mention before.
      nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
      nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
      nextion.write(0xff);
      nextion.write(0xff);
    
     nextion.print("ipadd.txt=");
     nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
     nextion.print(ip_auto);  // This is the text we want to send to that object and atribute mention before.
     nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
     nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
     nextion.write(0xff);
     nextion.write(0xff);
  
     nextion.print("deviceID.txt=");
     nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
     nextion.print("1");  // This is the text we want to send to that object and atribute mention before.
     nextion.print("\"");  // Since we are sending text we need to send double quotes before and after the actual text.
     nextion.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
     nextion.write(0xff);
     nextion.write(0xff);
  }
