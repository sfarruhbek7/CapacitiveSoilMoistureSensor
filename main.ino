#include<ESP8266WiFi.h>
const char* ssid= "Unusual";
const char* pass= "UT12345678";
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid,pass);
  Serial.print("Connecting to ");
  Serial.print(ssid);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }
  Serial.println(" ");
  Serial.println("connected succesfully");


  server.begin();
  Serial.print("Server begin at IP ");
  Serial.println(WiFi.localIP());
}

void loop() {
 WiFiClient myclient  = server.available();
 if(!myclient)
 return;

 Serial.println("New Client");

 String request = myclient.readString();
 Serial.println(request);
 hh=analogRead(A0);
 Serial.println(hh+" %");
 String response ="HTTP/1.1 200 OK\r\n Content-type:text/html\r\n\r\n {{humidity: "+hh+"}}";
myclient.print(response);
  
myclient.stop();
}
