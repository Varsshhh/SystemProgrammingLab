#include <stdbool.h>

typedef struct dictnode dictnode;
struct dictnode {
char label;
bool endofword;
dictnode *firstchild;
dictnode *nextsibling;
};

typedef struct {
dictnode *root;
} dict;

dict* dictinit();
bool dictsearch(dict *d, const char *s);
void dictinsert(dict *d, const char *s);
void dictlistall(dict *d);
