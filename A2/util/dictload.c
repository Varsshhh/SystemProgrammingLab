#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictload.h"

#define DFLT_DICT "dict/words.txt"

static dictnode* trienewnode(char label, bool endofword) {
    dictnode *node = (dictnode*) malloc(sizeof(dictnode));
    node->label = label;
    node->endofword = endofword;
    node->firstchild = NULL;
    node->nextsibling = NULL;
    return node;
}

dict* dictinit() {
    dict *t = (dict*) malloc(sizeof(dict));
    t->root = dictnewnode('-', false);
    return t;
}

bool dictsearch(dict *t, const char *s) {
    dictnode *p = t->root;
    int i = 0;
    while (s[i] != '\0' && p != NULL) {
        dictnode *child = p->firstchild;
        while (child != NULL && child->label < s[i]) {
            child = child->nextsibling;
        }
        if (child == NULL || child->label > s[i]) {
            return false;
        }
        p = child;
        i++;
    }
    return (p != NULL && p->endofword);
}

void dictinsert(dict *t, const char *s) {
    dictnode *p = t->root;
    int i = 0;
    while (s[i] != '\0') {
        dictnode *child = p->firstchild;
        dictnode *prev = NULL;
        while (child != NULL && child->label < s[i]) {
            prev = child;
            child = child->nextsibling;
        }
        if (child == NULL || child->label > s[i]) {
            dictnode *newnode = dictnewnode(s[i], false);
            if (prev == NULL) {
                newnode->nextsibling = p->firstchild;
                p->firstchild = newnode;
            } else {
                newnode->nextsibling = prev->nextsibling;
                prev->nextsibling = newnode;
            }
            child = newnode;
        }
        p = child;
        i++;
    }
    p->endofword = true;
}

static void listallrec(dictnode *p, char *buffer, int depth) {
    if (p == NULL) {
        return;
    }
    if (p->endofword) {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }
    dictnode *child = p->firstchild;
    while (child != NULL) {
        buffer[depth] = child->label;
        listallrec(child, buffer, depth + 1);
        child = child->nextsibling;
    }
}

void listall(dict *t) {
    char *buffer = (char*) malloc(256 * sizeof(char));
    listallrec(t->root, buffer, 0);
    free(buffer);
}

void loaddfltdict()
{
    loaddict(DFLT_DICT);
}

void loaddict(const char *fname)
{
    dict *d=dictinit();
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        perror("Error opening dictionary");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1)
    {
        if (line[read - 1] == '\n')
        {
            line[read - 1] = '\0';
        }
        dictinsert(d, line);
    }

    fclose(fp);
    if (line)
    {
        free(line);
    }
}