#include <iostream>
#include "phi.h"
#include "sieve.h"
#include "perm.h"

int main(int argc, char *argv[])
{
	bool *sieve = create_sieve(10000000);
	double smallest = 10000000, m;
	int number, p;
	for (int n = 2; n <= 10000000; ++n)
	{
		p = phi(n, sieve);
		if (!is_permutation(n, p)) continue;
		m = n/(double)p;
//		std::cout << n << " / " << p << " = " << m << std::endl;
		if (m < smallest)
		{
			smallest = m;
			number = n;
		}
	}
	std::cout << number << std::endl;
	return 0;
}
