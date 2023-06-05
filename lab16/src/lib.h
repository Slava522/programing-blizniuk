#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH "./assets/input.txt"
#define OPEN_FILE_ERROR -3
#define LETTERS_COUNT 5

typedef struct box {
    char* del;
    char* first;
    struct box* next;
} box_t;

typedef enum {
    UTF8,
    UTF16,
    CP1251
} cod_t;

typedef enum {
    SIGN_EXCLAMATION,
    SIGN_QUESTION,
    SIGN_PERIOD,
    SIGN_COLON,
    SIGN_SEMICOLON,
    SIGN_HYPHEN
} sign_t;

typedef enum {
    NUMBER_1,
    NUMBER_2,
    NUMBER_3,
    NUMBER_4,
    NUMBER_5,
    NUMBER_6,
    NUMBER_7,
    NUMBER_8,
    NUMBER_9,
    NUMBER_0
} number_t;

typedef struct {
    char name[32];
    char text[64];
} sender_t;

typedef struct {
    char name[32];
    char text[64];
} recipient_t;

typedef struct {
    cod_t cod;
    sender_t sender;
    recipient_t recipient;
    char theme[32];
    char text[128];
    bool is_note;
    bool is_secret;
} letters_t;

typedef struct {
    letters_t letters[LETTERS_COUNT];
} mailbox_t;

uint8_t* get_search_letters(mailbox_t* mailbox, char* name);

int delete_letters(box_t* del, box_t** first);

bool get_secret_letters(mailbox_t* mailbox, bool is_secret, sign_t* sign, number_t* number);

void show_letters(uint8_t index[]);

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
    char name[] = "Yan";
    uint8_t* index = get_search_letters(&mailbox, name);
    show_letters(index);
    free(index);

    return 0;
}