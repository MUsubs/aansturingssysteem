#include "memory.hpp"

void threadMemory() {
    const size_t test_size = 1024 * 1024;  // 1 MB
    uint8_t *buffer = (uint8_t *)malloc(test_size);

    if (!buffer) {
        Serial.println("Failed to allocate buffer");
        return;
    }

    int64_t start_time = esp_timer_get_time();

    // Memory write test
    for (size_t i = 0; i < test_size; i++) {
        buffer[i] = i % 256;
    }

    int64_t end_time = esp_timer_get_time();
    Serial.printf("Memory write time: %lld us\n", end_time - start_time);

    start_time = esp_timer_get_time();

    // Memory read test
    volatile uint8_t temp;
    for (size_t i = 0; i < test_size; i++) {
        temp = buffer[i];
    }

    end_time = esp_timer_get_time();
    Serial.printf("Memory read time: %lld us\n", end_time - start_time);

    free(buffer);
}