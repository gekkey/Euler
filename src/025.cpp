#include <cstdio>
#include "bigint.h"

int main(int argv, char* argc[])
{
	bigint a = 1, b = 1, c;
	int i = 2;
	while (b.len() < 1000)
	{
		c = b;
		b += a;
		a = c;
		i++;
	}
	printf("%d\n", i);
	return 0;
}
