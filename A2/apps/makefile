LIBDIR="../trie:../util"

maxchain: maxchain.c
	gcc -Wall maxchain.c -I../trie -I../util -L../util -lwordutils -L../trie -ltrie -o maxchain
	export LD_LIBRARY_PATH=$(LIBDIR)
	./maxchain
	

subwords: subwords.c
	gcc -Wall subwords.c -I../trie -I../util -L../util -lwordutils -L../trie -ltrie -o subwords
	export LD_LIBRARY_PATH=$(LIBDIR)
	./subwords