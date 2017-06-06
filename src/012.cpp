#include <stdio.h>
#include "factor.h"

int main(int argc, char *arg[])
{
	int t = 0, s = 1;

	while (num_divisors_of(t) < 500)
	{
		t += s++;
	}

	printf("%d\n", t);
	return 0;
}
