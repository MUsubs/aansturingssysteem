#include <stdlib.h>
#include <stdio.h>

void test_memory_speed();

int main() {
    stdio_init_all();
    test_memory_speed();
    while (1);
}

void test_memory_speed() {
    const size_t test_size = 1024 * 1024;  // 1 MB
    uint8_t *buffer = (uint8_t *)malloc(test_size);

    if (!buffer) {
        printf("Failed to allocate buffer\n");
        return;
    }

    absolute_time_t start_time = get_absolute_time();

    // Memory write test
    for (size_t i = 0; i < test_size; i++) {
        buffer[i] = i % 256;
    }

    absolute_time_t end_time = get_absolute_time();
    printf("Memory write time: %llu us\n", absolute_time_diff_us(start_time, end_time));

    start_time = get_absolute_time();

    // Memory read test
    volatile uint8_t temp;
    for (size_t i = 0; i < test_size; i++) {
        temp = buffer[i];
    }

    end_time = get_absolute_time();
    printf("Memory read time: %llu us\n", absolute_time_diff_us(start_time, end_time));

    free(buffer);
}
