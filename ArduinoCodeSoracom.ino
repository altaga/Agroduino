#include "DHT.h"
#include <DS18B20.h>
#include <MKRGSM.h>             // GSM library
#define DHTPIN A1     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);
DS18B20 ds(A0);
GSM gsmAccess;    // GSM access: include a 'true' parameter for debug enabled
GPRS gprsAccess;  // GPRS access
GSMClient client; // Client service for TCP connection

const char PINNUMBER[] = "";
char apn[20] = "soracom.io";
char login[8] = "sora";
char password[8] = "sora";
char url[] = "harvest.soracom.io";
char path[] = "/";

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  gsmAccess.begin(PINNUMBER);
  gprsAccess.attachGPRS(apn, login, password);
}

void loop() {
      float h = dht.readHumidity();
      float t = dht.readTemperature();
      int output_value= analogRead(A2);
      output_value = map(output_value,550,0,0,100);
      String PostData = "{\"ET\":"+ String(ds.getTempC())+",\"H\":"+ String(h) +",\"T\":"+ String(t)  +",\"M\":"+ String(output_value) +"}";

      // Connect to Soracom harvest
      if(Serial) Serial.print("Connecting and sending POST request to harvest.soracom.io...");
      int res_connect;

      res_connect = client.connect(url, 80);

      // If connection is successful, POST JSON data
      if (res_connect) {
        client.println("POST / HTTP/1.1");
        client.println("Host: harvest.soracom.io");
        client.println("User-Agent: Arduino/1.0");
        client.println("Connection: close");
        client.print("Content-Length: ");
        client.println(PostData.length());
        client.println();
        client.println(PostData);

        if(Serial) Serial.println("Works");

        // Read abd print the response from the server
        if(Serial) Serial.print("Receiving response...");
        boolean test = true;
        while (test) {
          // if there are incoming bytes available, print them
          if (client.available()) {
            char c = client.read();
            if(Serial) Serial.print(c);
          }

          // if the server's disconnected, stop the client:
          if (!client.connected()) {
            client.stop();
            test = false;
          }
        }
      } else {
        // if we didn't get a connection to the server
        if(Serial) Serial.println("Server Error");
      }
    
  
  
  // Switching off GSM Access


  // Wait for 5mins until we send the next sensor reading
  delay(10000);


}
