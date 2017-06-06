#include <iostream>
#include <unordered_map>
#include "phi.h"
#include "sieve.h"

int main(int argc, char *argv[])
{
	int lim = 1000000;
	bool *sieve = create_sieve(lim);
	std::unordered_map<int,int> cache;

	long count = 0;
	for (int d = 2; d <= lim; ++d)
	{
		count += phi(d, sieve, cache);
	}

	std::cout << count << std::endl;
	delete sieve;
	return 0;
}
