#include <unistd.h>
#include <libgen.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include "sys/types.h"

#define SIZE 777

int main() {
    struct dirent *dp;
    char path[SIZE];

    DIR *dirp = opendir("./tmp/");
    if (dirp == NULL) {
        return -1;
    }

    struct stat st;
    while ((dp = readdir(dirp)) != NULL) {
        // Excluding files . and .. that exist in every directory (Linux)
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }
        memset(path, 0, sizeof(path));
        strcat(path, "./tmp/");
        strcat(path, dp->d_name);
        // We can get stat from file and hard link count >= 2
        if (stat(path, &st) == 0 && st.st_nlink >= 2) {
            printf("%lu i-node\n", dp->d_ino);
            char s[SIZE];
            sprintf(s, "find ~ -inum %lu", dp->d_ino);
            FILE *fp = popen(s, "r");
            if (fp == NULL) {
                printf("Command execution error\n");
            }
            char buffer[SIZE];
            while (fgets(buffer, sizeof(buffer) - 1, fp) != NULL) {
                printf("%s", buffer);
            }
            printf("\n");
            fclose(fp);
        }
    }

    (void)closedir(dirp);
    return 0;
}
