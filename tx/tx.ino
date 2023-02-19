#include <WiFi.h>
#include <esp_now.h>

const uint8_t m_broadcast_address[] = {0xCC, 0xDB, 0xA7, 0x15, 0x2B, 0x9C};

uint8_t m_send_buffer[4];

esp_now_peer_info_t m_peer_info;

void send_callback(void)
{

  return;
}

void setup() {

  /* initialize esp now communications */
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK)
  {
    Serial.println("esp_now_init failed");
    return;  
  }

  esp_now_register_send_cb(send_callback);

  memcpy(m_peer_info.peer_addr, m_broadcast_address, 6);
  m_peer_info.channel = 0;
  m_peer_info.encrypt = false;

  if (esp_now_add_peer(&m_peer_info) != ESP_OK)
  {
    Serial.println("esp_now_add_peer failed");
    return;
  }

  /* initialize buttons for tracking score */
  

}

void loop() {
  
  memset(m_send_buffer, 0, sizeof(m_send_buffer));
  
  esp_err_t err_code = esp_now_send(m_broadcast_address, (uint8_t*)&);

}
