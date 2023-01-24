i)for building static library
gcc -Wall -c common.c
gcc -Wall -c foo.c
gcc -Wall -c bar.c
ar rcs numprn.a common.o foo.o bar.o

ii)Compile and run
sudo cp numprn.a /usr/local/lib
gcc -Wall -L. app.c -DINTERACTIVE -lnumprn -0 app
./app




iii)for building dynamiclibrary
gcc -Wall -fPIC -c common.c
gcc -Wall -fPIC -c foo.c
gcc -Wall -fPIC -c bar.c
gcc -shared -o numprn.so common.o foo.o bar.o

ii)Compile and run
sudo cp numprn.so /usr/local/lib
gcc -Wall -L. app.c -DINTERACTIVE -lnumprn -0 app
./app
