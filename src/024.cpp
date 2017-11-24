#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include "permutation.h"

int main(int argc, char* argv[])
{
	int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	permutation_iterator p(10, (int*)values);

	int i = 1;
	while (++i <= 1000000)
		p++;
	printf("%ld\n", p.to_long());
	return 0;
}
