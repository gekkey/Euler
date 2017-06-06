#include <cstdio>

int main(int argc, char *argv[])
{
	// 40! / (20!*20!)
	// product(21..40) / 20!
	
	long a = 1;
	for (int i = 21; i <= 40; i++)
		a = a * i / (i - 20);

	printf("%ld\n", a);
	return 0;
}
