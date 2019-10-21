#include <cstdio>
#include "bigint.h"

int main()
{
	bigint n = 1;
	int sum = 0;

	for (int i = 1; i <= 100; i++)
		n *= i;

	while (n != 0)
		sum += n.remainder_and_set(10);


	printf("%d\n", sum);
	return 0;
}
