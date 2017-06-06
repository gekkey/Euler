#include <cstdio>
#include "bigint.h"

int main(int argc, char *argv[])
{
	bigint n = 1;

	for (int i = 1; i <= 100; i++) {
		n *= i;
	}

	int i = 0;
	for (std::list<char>::iterator it = n.data.begin(); it != n.data.end(); it++)
		i += *it;

	printf("%d\n", i);
	return 0;
}
