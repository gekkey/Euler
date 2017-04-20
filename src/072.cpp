#include <iostream>
#include "phi.h"
#include "sieve.h"

int main(int argc, char *argv[])
{
	int lim = 1000000;
	long count = 0;
	bool *sieve = create_sieve(lim);
	for (int d = 2; d <= lim; ++d)
	{
		count += phi(d, sieve);
	}

	std::cout << count << std::endl;
	delete sieve;
	return 0;
}
