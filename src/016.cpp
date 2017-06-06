#include <cstdio>
#include "bigint.h"

int main(int argc, char *argv[])
{
	bigint a (1);
	bigint b (2);

	for (int i = 0; i < 1000; i++)
		a *= b;
	int sum = 0;
	for (std::list<char>::iterator i = a.data.begin(); i != a.data.end(); i++)
		sum += *i;

	printf("%d\n", sum);
	return 0;
}
