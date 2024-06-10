#include <Arduino.h>


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
    volatile uint8_t tmp;
    for (size_t i = 0; i < test_size; i++) {
        tmp = buffer[i];
    }

    end_time = micros();
    Serial.printf("Memory read time: %lu us\n", end_time - start_time);

    free(buffer);
}
