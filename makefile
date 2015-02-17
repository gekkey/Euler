CC=g++ -std=c++11 -Wall -Llib -Iinclude -lstdc++
EXFLAGS=-Wl,-rpath=./lib
SOFLAGS=-shared -fPIC

all: bin/70

clean:
	rm bin/* lib/*.so

bin/68: 068.cpp
	$(CC) 068.cpp -o bin/68

bin/69: lib/libphi.so lib/libsieve.so 069.cpp
	$(CC) $(EXFLAGS) 069.cpp -o bin/69 -lphi -lsieve

bin/70: lib/libphi.so lib/libsieve.so lib/libperm.so 070.cpp
	$(CC) $(EXFLAGS) 070.cpp -o bin/70 -lphi -lsieve -lperm

lib/libphi.so: lib/libsieve.so  lib/libgcd.so phi.cpp
	$(CC) $(SOFLAGS) phi.cpp -o lib/libphi.so -lgcd

lib/libsieve.so: sieve.cpp
	$(CC) $(SOFLAGS) sieve.cpp -o lib/libsieve.so

lib/libgcd.so: gcd.cpp
	$(CC) $(SOFLAGS) gcd.cpp -o lib/libgcd.so

lib/libperm.so: permutation.cpp
	$(CC) $(SOFLAGS) permutation.cpp -o lib/libperm.so
