/*
    ESP-NOW Broadcast Slave
    Lucas Saavedra Vaz - 2024

    This sketch demonstrates how to receive broadcast messages from a master device using the ESP-NOW protocol.

    The master device will broadcast a message every 5 seconds to all devices within the network.

    The slave devices will receive the broadcasted messages. If they are not from a known master, they will be registered as a new master
    using a callback function.
*/

const int LEFT_FORWARD = 3;
const int LEFT_REVERSE = 2;
const int RIGHT_FORWARD= 11;
const int RIGHT_REVERSE = 10;

#include "ESP32_NOW.h"
#include "WiFi.h"

#include <esp_mac.h>  // For the MAC2STR and MACSTR macros

#include <vector>

/* Definitions */

#define ESPNOW_WIFI_CHANNEL 6

const char car_id = '0';
/* Classes */

void run_motor(int number) {
  int left_speed = 255;
  int right_speed = 255;

  // Turn left
  if (number < 0) {
    left_speed = left_speed - (abs(number));
  }
  // Turn right 
  else { 
    right_speed = right_speed - (abs(number));
  }

  // Reset reverse and forward before setting new values
  analogWrite(LEFT_REVERSE, 0);
  analogWrite(LEFT_FORWARD, 0);
  analogWrite(RIGHT_REVERSE, 0);
  analogWrite(RIGHT_FORWARD, 0);

  // Add clamps in case of bad number input
  if (left_speed < 0) {
    analogWrite(LEFT_REVERSE, (left_speed * -1) % 256);
  } 
  else {
    analogWrite(LEFT_FORWARD, left_speed % 256);
  }
  
  if (right_speed < 0) {
    analogWrite(RIGHT_REVERSE, (right_speed * -1) % 256);
  } 
  else {
    analogWrite(RIGHT_FORWARD, right_speed % 256);
  }
  // Serial.printf("Left: %d, Right: %d \n", left_speed, right_speed);
}

// Creating a new class that inherits from the ESP_NOW_Peer class is required.

class ESP_NOW_Peer_Class : public ESP_NOW_Peer {
public:
  // Constructor of the class
  ESP_NOW_Peer_Class(const uint8_t *mac_addr, uint8_t channel, wifi_interface_t iface, const uint8_t *lmk) : ESP_NOW_Peer(mac_addr, channel, iface, lmk) {}

  // Destructor of the class
  ~ESP_NOW_Peer_Class() {}

  // Function to register the master peer
  bool add_peer() {
    if (!add()) {
      log_e("Failed to register the broadcast peer");
      return false;
    }
    return true;
  }

  // Function to print the received messages from the master
  void onReceive(const uint8_t *data, size_t len, bool broadcast) {

    Serial.printf("Received a message from master " MACSTR " (%s)\n", MAC2STR(addr()), broadcast ? "broadcast" : "unicast");
    Serial.printf("  Message: %s\n", (char *)data);
    // delay(10);
    if (data[0] == car_id) {
      int hundreds = data[3] - '0';
      int tens = data[4] - '0';
      int ones = data[5] - '0';
      int number_received = hundreds * 100 + tens * 10 + ones * 1;
      if (data[2] == '-') {
        number_received = number_received * -1;
      }
      run_motor(number_received);
    }
  }
};

/* Global Variables */

// List of all the masters. It will be populated when a new master is registered
std::vector<ESP_NOW_Peer_Class> masters;

/* Callbacks */

// Callback called when an unknown peer sends a message
void register_new_master(const esp_now_recv_info_t *info, const uint8_t *data, int len, void *arg) {
  if (memcmp(info->des_addr, ESP_NOW.BROADCAST_ADDR, 6) == 0) {
    Serial.printf("Unknown peer " MACSTR " sent a broadcast message\n", MAC2STR(info->src_addr));
    Serial.println("Registering the peer as a master");

    ESP_NOW_Peer_Class new_master(info->src_addr, ESPNOW_WIFI_CHANNEL, WIFI_IF_STA, NULL);

    masters.push_back(new_master);
    if (!masters.back().add_peer()) {
      Serial.println("Failed to register the new master");
      return;
    }
  } else {
    // The slave will only receive broadcast messages
    log_v("Received a unicast message from " MACSTR, MAC2STR(info->src_addr));
    log_v("Igorning the message");
  }
}

/* Main */

void setup() {
  Serial.begin(115200);
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_REVERSE, OUTPUT);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_REVERSE, OUTPUT);

  // Initialize the Wi-Fi module
  WiFi.mode(WIFI_STA);
  WiFi.setChannel(ESPNOW_WIFI_CHANNEL);
  while (!WiFi.STA.started()) {
    delay(10);
  }

  Serial.println("ESP-NOW Example - Broadcast Slave");
  Serial.println("Wi-Fi parameters:");
  Serial.println("  Mode: STA");
  Serial.println("  MAC Address: " + WiFi.macAddress());
  Serial.printf("  Channel: %d\n", ESPNOW_WIFI_CHANNEL);

  // Initialize the ESP-NOW protocol
  if (!ESP_NOW.begin()) {
    Serial.println("Failed to initialize ESP-NOW");
    Serial.println("Reeboting in 5 seconds...");
    delay(5000);
    ESP.restart();
  }

  // Register the new peer callback
  ESP_NOW.onNewPeer(register_new_master, NULL);

  Serial.println("Setup complete. Waiting for a master to broadcast a message...");
  pinMode(23, OUTPUT);
  digitalWrite(23, HIGH);
  delay(5000);
  digitalWrite(23, LOW);
}

void loop() {
  delay(10);
  //run_motor(received_packet);
}
