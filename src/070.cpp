#include <iostream>
#include <unordered_map>
#include "phi.h"
#include "sieve.h"
#include "perm.h"

int main(int argc, char *argv[])
{
	bool *sieve = create_sieve(5000);
	std::unordered_map<int,int> cache;

	double smallest = 10000000.0, c;
	int number, p, o;
	for (int n = 2; n < 5000; n++)
	{
		if (!sieve[n]) continue;
		for (int m = 2; m < 5000; m++)
		{
			if (!sieve[m]) continue;
			o = m * n;
			if (o > 10000000) break;
			//p = phi(m*n, sieve, cache);
			p = (m - 1) * (n - 1);
			if (!is_permutation(o, p)) continue;
			c = (double)(o) / (double)p;
			if (c < smallest)
			{
				smallest = c;
				number = o;
			}
		}
	}
	std::cout << number << std::endl;
	return 0;
}
