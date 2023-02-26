#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictutils.h"
#define MAX_WORD_LEN 50
#define MAX_CHAIN_LENGTH 100

int main() {
    dict *d = dictinit();
    int max_length = 0;
    char *max_word = NULL;

    for (char c = 'a'; c <= 'z'; c++) {
        char *s = (char*) malloc(MAX_WORD_LEN * sizeof(char));
        sprintf(s, "%c", c);

        char *new_word = addafter(d, s);
        while (new_word != NULL) {
            printf("==> %s\n", new_word);
            strcat(s, new_word);
            free(new_word);
            new_word = addafter(d, s);
        }

        if (strlen(s) > max_length) {
            max_length = strlen(s);
            if (max_word != NULL) {
                free(max_word);
            }
            max_word = strdup(s);
        }
        free(s);
    }

    printf("Longest chain:\n");
    char *token = strtok(max_word, " ");
    while (token != NULL) {
        printf("==> %s\n", token);
        token = strtok(NULL, " ");
    }

    dictfree(d);
    free(max_word);
    return 0;
}
