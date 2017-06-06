#include <iostream>
#include <unordered_map>
#include "phi.h"
#include "sieve.h"

int main(int argc, char *argv[])
{
	bool *sieve = create_sieve(1000000);
	std::unordered_map<int,int> cache;

	double largest = 0, m;
	int number;
	for (int n = 2; n <= 1000000; ++n)
	{
		m = n/(double)phi(n, sieve, cache);
		if (m > largest)
		{
			largest = m;
			number = n;
		}
	}

	std::cout << number << std::endl;
	return 0;
}
