#include "phi.h"
#include "sieve.h"
#include "gcd.h"

// phi(n) = n * product([1-(1/p) for p in prime_divisors(n)])
int phi(int n, bool *sieve)
{
	if (n < 2) return 0;
	if (sieve[n]) return n - 1;

	if (~n & 1)
	{
		int m = n >> 1;
		return (~m & 1) ? phi(m, sieve) << 1 : phi(m, sieve);
	}

	for (int m = 2; m < n; ++m)
	{
		if (!sieve[m] || n % m) continue;

		int o = n/m;
		int d = gcd(m, o);
		if (d == 1)
			return phi(m, sieve)*phi(o, sieve);
		else
			return phi(m, sieve)*phi(o,sieve)*d/phi(d, sieve);
	}

	return -1;
}

int phi(int n)
{
	bool *sieve = create_sieve(n);
	n = phi(n, sieve);
	delete[] sieve;
	return n;
}
