#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>

// External database submission API
extern void submit_registration(int32_t timestamp);

bool validate_future_date(const struct tm *input_date);
void print_banner(void);
void print_help(void);

int main() {
    struct tm date_input = {0};
    time_t current_time;
    time(&current_time);

    print_banner();

    while (1) {
        printf("\nOptions:\n");
        printf("1. Submit travel registration\n");
        printf("2. View help\n");
        printf("3. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                printf("\nEnter travel date (YYYY-MM-DD): ");
                if (scanf("%d-%d-%d", &date_input.tm_year, &date_input.tm_mon, &date_input.tm_mday) != 3) {
                    printf("Invalid date format\n");
                    while (getchar() != '\n');
                    continue;
                }

                // Normalize input
                date_input.tm_year -= 1900;
                date_input.tm_mon -= 1;
                date_input.tm_hour = 12;
                date_input.tm_min = date_input.tm_sec = 0;
                date_input.tm_isdst = -1;

                if (!validate_future_date(&date_input)) {
                    printf("\nDate must be in the future!\n");
                    continue;
                }

                // Submit to database (file not provided)
                int32_t time = mktime(&date_input);
                submit_registration(time);

                break;
            }

            case 2:
                print_help();
                break;

            case 3:
                printf("\nExiting system\n");
                return 0;

            default:
                printf("\nInvalid option\n");
        }
    }
}

bool validate_future_date(const struct tm *input_date) {
    time_t input_time = mktime((struct tm *)input_date);
    time_t current_time;
    time(&current_time);
    return input_time > current_time;
}

void print_banner(void) {
    printf("\n=== University Travel Registration System ===\n");
    printf("NOTICE: All student travel must be registered\n");
    printf("        at least 72 hours in advance\n");
}

void print_help(void) {
    printf("\nSystem accepts dates in YYYY-MM-DD format\n");
    printf("Travel must be registered before departure\n");
}
