#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dicttype.h"
#include "dictutils.h"

#define MAX_ANAGRAMS 100

int compare(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

char* addbefore(dict *d, const char *s) {
    char *result = (char*) malloc(26 * sizeof(char));
    int index = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        dictnode *curr = d->root;
        while (curr != NULL && curr->label != s[i]) {
            curr = curr->nextsibling;
        }
        if (curr != NULL) {
            curr = curr->firstchild;
            while (curr != NULL) {
                if (curr->endofword) {
                    result[index++] = curr->label;
                }
                curr = curr->nextsibling;
            }
        }
    }
    result[index] = '\0';
    return result;
}

char* addafter(dict *d, const char *s) {
    char *result = (char*) malloc(26 * sizeof(char));
    int index = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        dictnode *curr = d->root;
        while (curr != NULL && curr->label != s[i]) {
            curr = curr->nextsibling;
        }
        if (curr != NULL) {
            curr = curr->firstchild;
            while (curr != NULL) {
                dictnode *next = curr->nextsibling;
                while (next != NULL && !next->endofword) {
                    next = next->nextsibling;
                }
                if (next != NULL) {
                    result[index++] = next->label;
                }
                curr = curr->nextsibling;
            }
        }
    }
    result[index] = '\0';
    return result;
}

static void permute(dict *d, char *s, int l, char **anagram_list, int *num_anagrams) {
    if (l == strlen(s)) {
        if (dictsearch(d, s)) {
            anagram_list[(*num_anagrams)++] = strdup(s);
        }
    } else {
        for (int i = l; i < strlen(s); i++) {
            char temp = s[l];
            s[l] = s[i];
            s[i] = temp;
            permute(d, s, l + 1, anagram_list, num_anagrams);
            s[i] = s[l];
            s[l] = temp;
        }
    }
}

char** anagrams(dict *d, const char *s) {
    char **anagram_list = (char**) malloc(MAX_ANAGRAMS * sizeof(char*));
    int num_anagrams = 0;
    char *copy = strdup(s);
    permute(d, copy, 0, anagram_list, &num_anagrams);
    free(copy);
    anagram_list[num_anagrams] = NULL;
    qsort(anagram_list, num_anagrams, sizeof(char*), (int (*)(const void *, const void *)) strcmp);
    return anagram_list;
}