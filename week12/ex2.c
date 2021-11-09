#include <errno.h>
#include <linux/input.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

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
    while (fread(&ev, sizeof (struct input_event), 1, ffile)) {
        if (ev.type == EV_KEY) {
            if (ev.value == 2) {
                printf("%s 0x%04x (%d) \n", event_value[2], ev.code, ev.code); // REPEATED
            }
            else if (ev.value == 1) {
                    printf("%s 0x%04x (%d) \n", event_value[1], ev.code, ev.code); // PRESSED
            }
            else if (ev.value == 0) {
                printf("%s 0x%04x (%d) \n", event_value[0], ev.code, ev.code); // RELEASED
            }
        }
    }
    fclose(ffile);
    fflush(stdout);
    fprintf(stderr, "%s\n", strerror(errno));
    return 1;
}