#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "lib.h"

int main() {
    FILE* fp = fopen("./assets/input.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error with FILE* fp opening!..\n");
        return -1;
    }

    char text[LENGTH] = "";
    char line[LENGTH];
    while (fgets(line, LENGTH, fp) != NULL) {
        strcat(text, line);
    }
    int length = (int) strlen(text);

    int min_length = get_Min_Length(text, length);
    int max_length = get_Max_Length(text, length);

    printf("Min length is %d\n", min_length);
    printf("Max length is %d\n", max_length);

    fclose(fp);
    return 0;
}
