#include "sieve.h"

bool *create_sieve(int n)
{
	// create a block of true values
	bool *sieve = new bool[n+1];
	for (int i = 0; i <= n; ++i)
		sieve[i] = true;

	// set all multiples of indexes with true to false
	sieve[0] = sieve[1] = false;
	for (int i = 2; i < n; ++i)
	{
		if (sieve[i] == false) continue;
		for (int j = i + i; j <= n; j += i)
			sieve[j] = false;
	}

	return sieve;
}
