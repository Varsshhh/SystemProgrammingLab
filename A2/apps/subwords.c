#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictutils.h"
#define MAX_WORD_LEN 50
#define MAX_ANAGRAMS 100
#define MAX_SUBWORDS (MAX_ANAGRAMS * (MAX_WORD_LEN - 1))

int cmpfunc(const void *a, const void *b) {
    return strcmp(*(char**) a, *(char**) b);
}

int main() {
    char input_str[MAX_WORD_LEN];
    printf("Enter a lower-case string: ");
    scanf("%s", input_str);
    int len = strlen(input_str);
    char **anagrams_list = anagrams(dictinit(), input_str);
    char **subwords_list = (char**) malloc(MAX_SUBWORDS * sizeof(char*));
    int num_subwords = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (i == j) {
                continue;
            }
            char temp_str[MAX_WORD_LEN];
            strncpy(temp_str, input_str, MAX_WORD_LEN);
            char temp_char = temp_str[i];
            temp_str[i] = temp_str[j];
            temp_str[j] = temp_char;
            if (dictsearch(dictinit(), temp_str)) {
                subwords_list[num_subwords] = strdup(temp_str);
                num_subwords++;
            }
        }
    }
    qsort(subwords_list, num_subwords, sizeof(char*), cmpfunc);
    for (int i = 0; i < num_subwords; i++) {
        if (i == 0 || strcmp(subwords_list[i], subwords_list[i-1]) != 0) {
            printf("%s\n", subwords_list[i]);
        }
    }
    printf("%d subwords found\n", num_subwords);
    for (int i = 0; i < MAX_ANAGRAMS; i++) {
        free(anagrams_list[i]);
    }
    free(anagrams_list);
    for (int i = 0; i < MAX_SUBWORDS; i++) {
        free(subwords_list[i]);
    }
    free(subwords_list);
    return 0;
}
