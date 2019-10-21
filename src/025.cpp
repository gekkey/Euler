#include <cstdio>
#include "bigint.h"

int main()
{
	bigint a = 1, b = 1, c;
	bigint target = 1;
	for (int i = 1; i < 1000; i++)
		target *= 10;

	int i = 2;
	while (b < target)
	{
		c = b;
		b += a;
		a.data.swap(c.data);
		i++;
	}
	printf("%d\n", i);
	return 0;
}
