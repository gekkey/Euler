#include <stdlib.h>

int digits_in_int(int a)
{
	int i = 0;
	while (a)
	{
		a /= 10;
		++i;
	}
	return i;
}

char *digit_array(int a)
{
	int n = digits_in_int(a);
	char *arr = (char *)malloc(n * sizeof(char));
	while (a)
	{
		n--;
		arr[n] = a % 10;
		a /= 10;
	}
	return arr;
}
