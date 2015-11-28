#include <iostream>

int main(int argc, char *argv[])
{
	int a = 3, b = 7;   // target
	long c, d = 1000000; // temporary
	long e = 2, f = 5;   // closest

	for (; d > 2; d--)
	{
		c = (a * d - 1) / b;
		if (c * b < a * d && c * f > e * d)
		{
			e = c;
			f = d;
		}
	}
	std::cout << e << std::endl;
	return 0;
}
