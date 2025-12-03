#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main() {
    int hour, min;
    char alarmTime[6], currentTime[6];

    printf("=== Simple Alarm Clock ===\n");
    printf("Set alarm time (HH:MM in 24-hour format): ");
    scanf("%s", alarmTime);

    printf("Alarm set for %s\n", alarmTime);

    while(1) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        snprintf(currentTime, sizeof(currentTime), "%02d:%02d", tm.tm_hour, tm.tm_min);
        printf("\rCurrent time: %s", currentTime);
        fflush(stdout);

        if(strcmp(currentTime, alarmTime)==0) {
            printf("\nALARM! Time to wake up!\n");
            break;
        }
        sleep(30); // check every 30 seconds
    }

    return 0;
}
