#include <Arduino.h>
#include "esp_system.h"
#include "esp_spi_flash.h"


void setup() {
    Serial.begin(9600);
    Serial.println(ESP.getSdkVersion());

    // ref - https://github.com/espressif/esp-idf/blob/master/examples/get-started/hello_world/main/hello_world_main.c
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    Serial.printf("This is ESP32 chip with %d CPU cores, WiFi%s%s, ",
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    Serial.printf("silicon revision %d, ", chip_info.revision);

    Serial.printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
}

void loop() {

}