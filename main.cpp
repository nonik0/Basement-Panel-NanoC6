#include <Arduino.h>

#include "tunnel_runner.h"
#include "wifi_services.h"

TunnelRunnerTaskHandler tunnelRunner;
WifiServices wifiServices;

void setup()
{
  Serial.begin(115200);
  log_i("Starting setup...");

  Wire.setPins(2, 1);

  wifiServices.setup(DEVICE_NAME);
  wifiServices.createTask();

  tunnelRunner.createTask();

  wifiServices.registerSetDisplayCallback([](bool display)
                                          { tunnelRunner.setDisplay(display); });

  log_i("Setup complete");
}

void loop()
{
  log_d("Looping...");
  delay(1000);
}