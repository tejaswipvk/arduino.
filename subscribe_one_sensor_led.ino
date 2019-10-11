#include "config.h"
// set up the 'counter' feed
AdafruitIO_Feed *led = io.feed("led");
int ledpin=5;
int threshold=120;

void setup() {
pinMode(ledpin,OUTPUT);
  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  Serial.print("Connecting to Adafruit IO");

  // start MQTT connection to io.adafruit.com
  io.connect();

  
  led->onMessage(handleMessage);

  
  while(io.mqttStatus() < AIO_CONNECTED) {
    Serial.print(".");
    delay(50000);
  }


  led->get();

  // we are connected
  Serial.println("Hi this is avinash");
  Serial.println(io.statusText());

}

void loop() {

  
  io.run();

 
}


void handleMessage(AdafruitIO_Data *data) {

  Serial.print("got <- ");
  Serial.println(data->value());
  if (data->toInt() == 1)
  {
    digitalWrite(5,HIGH);
  }
  else
  {
    digitalWrite(5,LOW);
  }
  

}
