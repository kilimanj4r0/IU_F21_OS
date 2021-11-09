#include <errno.h>
#include <linux/input.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define NUM_OF_KEYS 7777
static const char *const event_value[3] = {
    "RELEASED",
    "PRESSED",
    "REPEATED"
};

int main() {
    const char *file = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event ev;
    FILE *ffile = fopen(file, "r");
    if (ffile == NULL) {
        fprintf(stderr, "Error to open the file\n");
        return 1;
    }
    int key_status[NUM_OF_KEYS];
    for (int i = 0; i < NUM_OF_KEYS; i++) {
        key_status[i] = 0;
    }

    printf("Implemented shortcuts:\n");
    printf("P + E: \"I passed the Exam!\"\n");
    printf("C + A + P: \"Get some cappuccino!\"\n");
    printf("L + O + V + E: \"Do love!\"\n");

    while (fread(&ev, sizeof (struct input_event), 1, ffile)) {
        if (ev.type == EV_KEY) {
            if (ev.value == 0) {
                key_status[ev.code] = 0;
            }
            else if (ev.value == 1) {
                key_status[ev.code] = 1;
                // P + E
                if(key_status[25] && key_status[18]) {
                    printf("I passed the Exam!\n");
                }
                // C + A + P
                else if(key_status[46] && key_status[30] && key_status[25]) {
                    printf("Get some cappuccino!\n");
                }
                // L + O + V + E
                else if(key_status[38] && key_status[24] && key_status[47] && key_status[18]) {
                    printf("Do love!\n");
                }
            }
        }
    }
    fclose(ffile);
    fflush(stdout);
    fprintf(stderr, "%s\n", strerror(errno));
    return 1;
}
