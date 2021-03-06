/*

  S K Y L I F T
  https://ahprojects.com/skylift
  Adam Harvey 2017

  Send multiple beacon frames with custom SSID/BSSID

  This example shows how to Beacon Frames with multiple custom BSSIDs using the ESP8266
  Compiled with Arduino 1.6.12 on ES8266 NodeMCU 0.9 12

  Based on the original WiFi Beacon Jammer code by @kripthor
  https://github.com/kripthor/WiFiBeaconJam)

*/


#include <ESP8266WiFi.h>
extern "C" {
#include "user_interface.h"
}

//#define USE_HIDDEN_SSID // uncomment to use hidden SSIDs
#define nn 6 // number of networks
uint8_t ncounter = 0; // network counter

char* ssids[nn] = {
  "Network1",
  "Network2",
  "Network3",
  "Network4",
  "Network5",
  "Network6"
};

char* ssids_str[nn] = {
  "00:01:02:03:04:05",
  "00:01:02:03:04:06",
  "00:01:02:03:04:07",
  "00:01:02:03:04:08",
  "00:01:02:03:04:09",
  "00:01:02:03:04:10",
};

byte bssids[nn][6] = {
  {0x00, 0x01, 0x02, 0x03, 0x04, 0x05},
  {0x00, 0x01, 0x02, 0x03, 0x04, 0x06},
  {0x00, 0x01, 0x02, 0x03, 0x04, 0x07},
  {0x00, 0x01, 0x02, 0x03, 0x04, 0x08},
  {0x00, 0x01, 0x02, 0x03, 0x04, 0x09},
  {0x00, 0x01, 0x02, 0x03, 0x04, 0x10},
};

uint8_t ssid_len;
byte bssid[6] = {};
byte channels[nn] = {1, 1, 1, 1, 1, 1};
uint8_t channel = channels[0]; // Transmit on this channel

unsigned long last_beacon_us;
unsigned long beacon_interval_us = 102400; // Typical interval of beacon frames is 100.24 milliseconds (0x64)

char* hidden_ssid = "\x00"; // appears as 0-length SSID (Network name unavailable)
char time_packet[8]; // placeholder for timestamp data
char cc[2]; // placeholer for timestamp data


// Beacon frame packet structure
uint8_t packet[128] = {
  /*0*/   0x80, 0x00, // Frame Control
  /*2*/   0x00, 0x00, // Duration
  /*4*/   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // Destination address
  /*10*/  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Source address - overwritten later
  /*16*/  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // BSSID - overwritten to the same as the source address
  /*22*/  0xc0, 0x6c, // Seq-ctl
  /*24*/  0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, // Timestamp - the number of microseconds the AP has been active
  /*32*/  0x64, 0x00, // Beacon interval = 0.102400 seconds
  /*34*/  0x31, 0x14, // Capability info (use 0x01, 0x04 for open network)
  /*36*/  0x00
  /* SSID is added after here */
};

uint8_t packet_tail[13] = {
  0x01, 0x08, 0x82, 0x84, 0x8b, 0x96, 0x24, 0x30, 0x48, 0x6c, // supported rate
  0x03, 0x01, 0x04 // DSSS (Current Channel)
};


// ---------------------------------------------------------------
// Initialize the ESP8266
// Set max power and put into promiscious mode
// ---------------------------------------------------------------
void setup() {
  // Init ESP8266
  WiFi.setOutputPower(20.5); // 0 (min) - 20.5 (max)
  wifi_set_opmode(STATION_MODE);
  wifi_promiscuous_enable(1);
}

// ---------------------------------------------------------------
// Transmit Beacon Frame
// ---------------------------------------------------------------
void loop() {
  // Limit to every 100ms
  if (micros() - last_beacon_us < beacon_interval_us) {
    return;
  }
  last_beacon_us = micros();

  ncounter = (ncounter + 1) % nn;

  // Send the packet
#ifdef USE_HIDDEN_SSID
  char* ssid = hidden_ssid;
#else
  char* ssid = ssids[ncounter];
#endif
  send_beacon_frame(ssid , channels[ncounter]);
}


// ---------------------------------------------------------------
// Send the beacon frame
// ---------------------------------------------------------------
void send_beacon_frame(char* ssid, byte channel) {

  uint8_t ssid_len = strlen(ssid);
  uint8_t packet_length = 51 + ssid_len;

  // Set BSSID
  for (int i = 0; i < 6; i++) {
    bssid[i] = bssids[ncounter][i];
  }
  for (int i = 0; i < 6; i++) {
    packet[10 + i] = packet[16 + i] = bssid[i];
  }

  // Update the timestamp
  get_timestamp(time_packet);
  for (int i = 0; i < 8; i++) {
    packet[24 + i] = time_packet[i];
  }

  // set the SSID length byte
  packet[37] = ssid_len;
  for (int i = 0; i < ssid_len; i++) {
    packet[38 + i] = ssid[i];
  }

  // Add the ending packet bytes
  for (int i = 0; i < 12; i++) {
    packet[38 + ssid_len + i] = packet_tail[i];
  }

  // Set transmit frequency and packet channel
  wifi_set_channel(channel);
  packet[50 + ssid_len] = channel;

  // Send the packet
  wifi_send_pkt_freedom(packet, packet_length, 0);
}

// ---------------------------------------------------------------
// Convert milliseconds to timestamp for beacon frame
// ---------------------------------------------------------------
void get_timestamp(char *times) {

  long t = micros();
  unsigned int tlen = 8;
  String time_hex_forward = String(t, HEX);

  while (time_hex_forward.length () < tlen * 2) time_hex_forward = "0" + time_hex_forward;
  String time_hex_rev = time_hex_forward; // reversed
  for (int i = tlen; i > 0; i--) {
    time_hex_rev[(tlen * 2) - (i * 2) ] = time_hex_forward.charAt((i * 2) - 2); // 1
    time_hex_rev[(tlen * 2) - (i * 2) + 1] = time_hex_forward.charAt((i * 2) - 1); // 2
  }
  // convert to 8-length byte array
  for (int i = 0; i < tlen; i++) {

    cc[0] = time_hex_rev.charAt(i * 2);
    cc[1] = time_hex_rev.charAt((i * 2) + 1);
    long hex_val = strtol(cc, NULL, 16);
    times[i] = hex_val;
  }
}

long strtol (const char *__nptr, char **__endptr, int __base); // additional function for string to long conversion
