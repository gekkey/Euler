#include <cstdio>
#include "factor.h"

int main(int argc, char *argv[])
{
	int a, b;
	int r = 0;
	for (int i = 1; i < 10000; i++)
	{
		a = sum_divisors_of(i);
		b = sum_divisors_of(a);
		if (i == b && a != b)
			r += a;
	}
	printf("%d\n", r);
	return 0;
}
