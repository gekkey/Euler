CC=g++ -std=c++11 -Wall -Llib -Iinclude -lstdc++
EXFLAGS=-Wl,-rpath=./lib
SOFLAGS=-shared -fPIC

all: bin/71 bin/1 bin/2 bin/68 bin/3 bin/69 bin/70

clean:
	rm bin/* lib/*.so

bin/71: 071.cpp lib/libgcd.so
	$(CC) $(EXFLAGS) 071.cpp -o bin/71 -lgcd

bin/1: 001.cpp 
	$(CC) $(EXFLAGS) 001.cpp -o bin/1 

bin/2: 002.cpp 
	$(CC) $(EXFLAGS) 002.cpp -o bin/2 

bin/68: 068.cpp 
	$(CC) $(EXFLAGS) 068.cpp -o bin/68 

bin/3: 003.cpp 
	$(CC) $(EXFLAGS) 003.cpp -o bin/3 

bin/69: 069.cpp lib/libphi.so lib/libsieve.so
	$(CC) $(EXFLAGS) 069.cpp -o bin/69 -lphi -lsieve

bin/70: 070.cpp lib/libphi.so lib/libsieve.so lib/libperm.so
	$(CC) $(EXFLAGS) 070.cpp -o bin/70 -lphi -lsieve -lperm

lib/libphi.so: phi.cpp lib/libsieve.so lib/libgcd.so
	$(CC) $(SOFLAGS) phi.cpp -o lib/libphi.so -lsieve -lgcd

lib/libgcd.so: gcd.cpp 
	$(CC) $(SOFLAGS) gcd.cpp -o lib/libgcd.so 

lib/libbtree.so: btree.cpp 
	$(CC) $(SOFLAGS) btree.cpp -o lib/libbtree.so 

lib/libsieve.so: sieve.cpp 
	$(CC) $(SOFLAGS) sieve.cpp -o lib/libsieve.so 

lib/libperm.so: perm.cpp 
	$(CC) $(SOFLAGS) perm.cpp -o lib/libperm.so 

