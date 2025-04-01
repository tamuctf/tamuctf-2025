#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void submit_registration(int32_t timestamp) {
    time_t raw_time = timestamp;
    struct tm utc_time;
    gmtime_r(&raw_time, &utc_time);

    bool date_match =   (utc_time.tm_year == 125) && // 2025 - 1900
                        (utc_time.tm_mon == 2) &&    // March (0-indexed)
                        (utc_time.tm_mday == 21);
    // printf("%d %d %d", utc_time.tm_year + 1900, utc_time.tm_mon + 1, utc_time.tm_mday); // It'd be too easy with this, only enable for debugging

    printf("\nRegistration submitted\n");
    if (date_match) {
        printf("gigem{7urn_y0ur_c0mpu73r_0ff_83f0r3_m1dn19h7}\n");
    } else {
        printf("...but not for CCDC. Keep trying!\n");
    }
}
