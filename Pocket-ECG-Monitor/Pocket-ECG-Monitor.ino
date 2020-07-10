
/*
   This is developed by SAMEER TUTEJA and SANYAM CHHAJED and if required to modify it, please contact beforehand.
   https://github.com/sam-tj / https://github.com/Sanyam02
   This is tested for NODEMCU 1.0
   For any suggestions please contact us using GITHUB.
*/


#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
#include "index.h" //Our HTML webpage contents with javascripts
 
#define LED 2  //On board LED
 
//SSID and Password of your WiFi router
const char* ssid = "YOUR WIFI SSID";
const char* password = "PASSWORD";
 
ESP8266WebServer server(80); //Server on port 80
 
//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}
 
void handleADC()
{
    int a = analogRead(A0);
    int b=a/2;
    String adcValue = String(b);
 digitalWrite(LED,!digitalRead(LED)); //Toggle LED on data request ajax
 server.send(200, "text/plane", adcValue); //Send ADC value only to client ajax request
}
//==============================================================
//                  SETUP
//==============================================================
void setup(void){
  Serial.begin(9600);
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");
 
  //Onboard LED port Direction output
  pinMode(LED,OUTPUT); 
  pinMode(D1,OUTPUT);
  pinMode(D0,OUTPUT);
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
 
  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/readADC", handleADC); //This page is called by java Script AJAX
 
  server.begin();                  //Start server
  Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  server.handleClient();          //Handle client requests
}
