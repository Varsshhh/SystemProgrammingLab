
library: dictload.o dictutils.o
	gcc -shared -I. I../trie -o libwordutils.so dictload.o dictutils.o -L../trie -ltrie
	

dictload.o: dicttype.h dictload.h
	gcc -Wall -fPIC -I. -I../trie -c dictload.c -L../trie -ltrie


dictutils.o: dicttype.h dictutils.h
	gcc -Wall -fPIC -I. -I../trie -c dictutils.c -L../trie -ltrie