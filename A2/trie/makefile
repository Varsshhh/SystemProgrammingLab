INCLUDEDIR=/usr/include
LIBDIR=/usr/local/lib


library: trie.o
	gcc -shared -o libtrie.so trie.o
	
trie.o: trie.h
	gcc -Wall -fPIC -c -I. trie.c