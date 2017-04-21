#include <stdio.h>
#include "sieve.h"

int main(int argc, char *argv[])
{
	int sieve_len = 1000000;
	bool *sieve = create_sieve(sieve_len);
	int n = 10001;
	int nth_prime;

	for (int i = 2; i < sieve_len; i++)
	{
		if (sieve[i]) {
			nth_prime = i;
			if (! --n) break;
		}
	}

	printf("%d\n", nth_prime);
	return 0;
}
