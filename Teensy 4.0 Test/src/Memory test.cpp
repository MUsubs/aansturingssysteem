#include <Arduino.h>

void test_memory_speed();

void setup() {
    Serial.begin(115200);
    while (!Serial) {
        ; // Wacht tot de seriële monitor is geopend
    }
    test_memory_speed();
}

void loop() {
    // Niets te doen in de loop
}

void test_memory_speed() {
    const size_t test_size = 1024 * 1024;  // 1 MB
    uint8_t *buffer = (uint8_t *)malloc(test_size);

    if (!buffer) {
        Serial.println("Failed to allocate buffer");
        return;
    }

    unsigned long start_time = micros();

    // Memory write test
    for (size_t i = 0; i < test_size; i++) {
        buffer[i] = i % 256;
    }

    unsigned long end_time = micros();
    Serial.printf("Memory write time: %lu us\n", end_time - start_time);

    start_time = micros();

    // Memory read test
    volatile uint8_t temp;
    for (size_t i = 0; i < test_size; i++) {
        temp = buffer[i];
    }

    end_time = micros();
    Serial.printf("Memory read time: %lu us\n", end_time - start_time);

    free(buffer);
}
