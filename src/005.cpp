#include <stdio.h>
#include <limits.h>
#include "sieve.h"

int main(int argc, char *argv[])
{
	int dividend = 0;

	bool *sieve = create_sieve(20);
	int ppf = 1; //product of prime factors
	for (int i = 2; i < 20; i++) {
		if (sieve[i]) {
			ppf *= i;
		}
	}

	while (dividend >= 0) {
	restart:
		dividend += ppf;
		for (int i = 2; i < 20; i++) {
			if (!sieve[i] && (dividend % i)) {
				goto restart; // break and continue
			}
		}
		printf("%d\n", dividend);
		return 0;

	}

	printf("> %d\n", INT_MAX);
	return 1;
}
