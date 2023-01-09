#include <stdio.h>
#include <stdlib.h>


// https://stackoverflow.com/a/47333111
void LineByLine() {
    // open file
    FILE *fp = fopen("AccountData.txt", "r");
//     char * token;
//     int i = 0;
//     char line_info[9][255];
    size_t len = 255;
    // need malloc memory for line, if not, segmentation fault error will occurred.
    char *line = malloc(sizeof(char) * len);
    // check if file exist (and you can open it) or not
    if (fp == NULL) {
        printf("can open file AccountData.txt!");
        return;
    }
    while(fgets(line, len, fp) != NULL) {
        printf("%s", line);
    }
    free(line);
}


