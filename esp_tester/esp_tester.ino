//Put all files from libraries to the same folder as program
#include <vscp.hpp>
//#include <Arduiono.h>

#ifdef USE_LVGL
#  undef USE_LVGL
#endif

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial);

  Serial.println("Initializing protocol...");

  try{
    while(Protocol::isInitialized() == false)
    {
        Serial.println("Waiting for protocol initialization...");
        Protocol::init("VSCP Emulator", "1.0.0");
        delay(100);
    }
  } catch (const Exception& e) {
      e.print();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  sendMessage("Hello from ESP32!");
  String response = receiveMessage().c_str();
  Serial.println("Received: " + response); 
  */

  // Example usage of update
  try{
      auto response = Protocol::update("sensor_001");
      for (const auto& [key, value] : response) {
          Serial.println(key.c_str() + String(": ") + value.c_str());
      }
  } catch (const Exception& e) {
      e.print();
  }
  delay(1000);
}
