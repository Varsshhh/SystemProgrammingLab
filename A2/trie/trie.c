#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "trie.h"

static trienode* trienewnode(char label, bool endofword) {
    trienode *node = (trienode*) malloc(sizeof(trienode));
    node->label = label;
    node->endofword = endofword;
    node->firstchild = NULL;
    node->nextsibling = NULL;
    return node;
}

trie* trieinit() {
    trie *t = (trie*) malloc(sizeof(trie));
    t->root = trienewnode('-', false);
    return t;
}

bool triesearch(trie *t, const char *s) {
    trienode *p = t->root;
    int i = 0;
    while (s[i] != '\0' && p != NULL) {
        trienode *child = p->firstchild;
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

void trieinsert(trie *t, const char *s) {
    trienode *p = t->root;
    int i = 0;
    while (s[i] != '\0') {
        trienode *child = p->firstchild;
        trienode *prev = NULL;
        while (child != NULL && child->label < s[i]) {
            prev = child;
            child = child->nextsibling;
        }
        if (child == NULL || child->label > s[i]) {
            trienode *newnode = trienewnode(s[i], false);
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

static void listallrec(trienode *p, char *buffer, int depth) {
    if (p == NULL) {
        return;
    }
    if (p->endofword) {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }
    trienode *child = p->firstchild;
    while (child != NULL) {
        buffer[depth] = child->label;
        listallrec(child, buffer, depth + 1);
        child = child->nextsibling;
    }
}

void listall(trie *t) {
    char *buffer = (char*) malloc(256 * sizeof(char));
    listallrec(t->root, buffer, 0);
    free(buffer);
}


