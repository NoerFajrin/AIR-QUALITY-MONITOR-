
void wifi_init() {
  while (!Serial) continue;
  StaticJsonDocument<200> doc;
       String ssid_pass = readFile(SPIFFS, "/network.json");
  DeserializationError error = deserializeJson(doc, ssid_pass);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
  }
 
  String ssid_wifi = doc["SSID"];
  String password_wifi = doc["PASSWORD"];
  Serial.println(ssid_wifi);
  Serial.println(password_wifi);
 
  
  Serial.println(ssid_pass);
  WiFi.begin(ssid_wifi.c_str(), password_wifi.c_str());
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  if (WiFi.status() == WL_CONNECTED) {   
    }
    else {
      Serial.println("not connected"); 
  }
  
  Serial.println("Connected to the WiFi network");

}
  
