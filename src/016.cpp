#include <cstdio>
#include "bigint.h"

int main()
{
	bigint a = 1;
	a <<= 1000;
	int sum = 0;

	while (a != 0)
		sum += a.remainder_and_set(10);

	printf("%d\n", sum);
	return 0;
}
