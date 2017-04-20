#include <iostream>

int main(int argc, char *argv[])
{
	int sum = 0;
	int a = 1, b = 1, c;

	while (b < 4000000)
	{
		sum += a + b;
		c = a;
		a = a + 2 * b;
		b = 2 * c + 3 * b;
	}

	std::cout << sum << std::endl;

	return 0;
}
