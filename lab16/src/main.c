#include "./lib.h"

int main(int argc, char* argv[]) {
    FILE* in = fopen(PATH, "r");
    if (in == NULL) {
        fprintf(stderr, "Opening file error!\n");
        exit(OPEN_FILE_ERROR);
    }

    char info[LETTERS_COUNT];
    while (fgets(info, LETTERS_COUNT, in) != NULL) {
        fprintf(stdout, "%s\n", info);
    }

    fclose(in);

    mailbox_t mailbox;  // Assuming you have a mailbox variable defined
    uint8_t* index = get_search_letters(&mailbox, "Yan");
    show_letters(index);
    free(index);

    return 0;
}