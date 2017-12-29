#include <iostream>

int main()
{
	long n = 600851475143;
	int d = 2;
	while (n > 1)
	{
		if (n % d == 0)
			n /= d;
		else
			d++;
	}

	std::cout << d << std::endl;
	return 0;
}
