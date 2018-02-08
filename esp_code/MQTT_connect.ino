/**
 * Connect or re-connect to the MQTT Server
 * This is executed at every cycle to manage possible connection loss
 * It tries endlessly until successful
 */
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (psub_client.connected()) {
    return;
  }

  Serial.println("Connecting to MQTT Dashboard... ");

  //uint8_t retries = 3;
  while (!psub_client.connect("Hydra Controller", DBRD_KEY, NULL)) { 
    Serial.println("Failed MQTT Connection:" + psub_client.state());
    Serial.println("Retrying MQTT connection in 5 seconds...");
    psub_client.disconnect();
    delay(5000);  // wait 5 seconds
  }
  Serial.println("MQTT Connected!");
}
