#include <unordered_map>
#include <cmath>
#include "phi.h"
#include "sieve.h"
#include "gcd.h"

// phi(n) = n * product([1-(1/p) for p in prime_divisors(n)])
int phi(int n, bool *sieve, std::unordered_map<int, int> &memo)
{
	std::unordered_map<int, int>::const_iterator l;
	if ( (l = memo.find(n)) != memo.end() )
		return l->second;

	if (n < 0) n *= -1;
	if (n < 2) return n;
	if (sieve[n]) return n - 1;

	int r = n;

	if (~n & 1)
	{
		r /= 2;
		r = (~r & 1) ? phi(r, sieve, memo) * 2 : phi(r, sieve, memo);
		memo[n] = r;
		return r;
	}

	int p;
	int sq = (int)sqrt(n);
	for (p = 2; p <= sq; ++p)
	{
		if (!sieve[p] || n % p) continue;

		int m = n / p;
		int d = gcd(m, p);
		if (d == 1) {
			r = phi(m, sieve, memo)*phi(p, sieve, memo);
			memo[n] = r;
			return r;
		} else {
			r = phi(m, sieve, memo)*phi(p,sieve, memo)*d/phi(d, sieve, memo);
			memo[n] = r;
			return r;
		}
	}

	printf("phi error: %d\n", n);
	return -1;
}

int phi(int n, bool *sieve)
{
	std::unordered_map<int, int> memo;
	return phi(n, sieve, memo);
}

int phi(int n)
{
	bool *sieve = create_sieve(sqrt(n));
	n = phi(n, sieve);
	delete[] sieve;
	return n;
}
