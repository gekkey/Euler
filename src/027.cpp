#include <cstdio>
#include "sieve.h"

/* Problem:
Euler discovered the remarkable quadratic formula:

	n^2+n+41

It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39.
However, when n=40, 40^2+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41, 41^2+41+41 is clearly divisible by 41.

The incredible formula n^2−79n+1601 was discovered, which produces 80 primes for the consecutive values 0≤n≤79.
The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

    n^2+an+b

, where |a|<1000 and |b|≤1000
where |n| is the modulus/absolute value of n. e.g. |11|=11 and |−4|=4

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes 
for consecutive values of n, starting with n=0.
*/

/* Solution:
 * Assume we're not going to outdo the bigger example, so n < 80; 
 * 80^2 + 1000*80 + 1000 = 87400, so that's the limit for the prime sieve.
 *
 * Now just brute-force it. Try each a and b, and count the primes.
 */

#define lim 1000

int main()
{
	int n, m;
	int max_num = 0, max_product = 0;
	bool* sieve = create_sieve(87400);
	for (int a = -lim; a < lim; a++)
	{
		for (int b = -lim; b < lim; b++)
		{
			for (n = 0, m = 2; m > 0 && sieve[m]; n++) 
				m = n*n + a*n + b;
			if (n > max_num) 
				max_num = n, max_product = a * b;
		}
	}
	printf("%d\n", max_product);
	return 0;
}
