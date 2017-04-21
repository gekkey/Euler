#include <iostream>
#include "digits.h"

bool is_permutation(int a, int b)
{
	if (digits_in_int(a) != digits_in_int(b)) return false;

	bool found;
	int n = digits_in_int(a), m = 0;
	int digits[n];

	while (a)
	{
		digits[m] = a % 10;
		a /= 10;
		++m;
	}

	while (b)
	{
		m = b % 10;
		b /= 10;
		found = false;
		for (int i = 0; i < n; ++i)
		{
			if (m == digits[i])
			{
				found = true;
				digits[i] = -1;
				break;
			}
		}
		if (!found) break;
	}

	return found;
}
