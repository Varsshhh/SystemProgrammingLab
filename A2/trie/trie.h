#include <stdbool.h>

typedef struct trienode trienode;
struct trienode {
    char label;
    bool endofword;
    trienode *firstchild;
    trienode *nextsibling;
};

typedef struct {
    trienode *root;
} trie;

trie* trieinit();
bool triesearch(trie *t, const char *s);
void trieinsert(trie *t, const char *s);
void listall(trie *t);
