#include <stdio.h>
#include "sieve.h"

int main(int argc, char *argv[])
{
	const int lim = 2000000;
	bool *sieve = create_sieve(lim);
	long sum = 0;

	for (int i = 2; i < lim; i++)
		if (sieve[i])
			sum += i;

	printf("%ld\n", sum);
	return 0;
}
