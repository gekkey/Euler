#include <cstdio>
#include "digits.h"

bool is_permutation(int a, int b)
{
	if ((a<0) != (b<0))
		return false;

	char n = 0, m = 0;
	signed char digits[10] {};

	while (a)
	{
		digits[a%10]++;
		a /= 10;
		n++;
	}

	while (b)
	{
		digits[b%10]--;
		b /= 10;
		m++;
	}
	
	if ( n != m )
		return false;
	for (int i = 0; i < 10; i++)
		if ( digits[i] )
			return false;
	return true;
}
