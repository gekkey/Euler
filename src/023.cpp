#include <cstdio>
#include "factor.h"

#define LOW_LIM 12
#define UPP_LIM 20161
bool is_sum_of_abundants(int n, bool* abundant)
{
	if (n < LOW_LIM * 2)
		return false;
	if (n > UPP_LIM)
		return true;
	for (int i = LOW_LIM; i < n; i++)
		if (abundant[i] && abundant[n-i])
			return true;
	return false;
}

int main(int argc, char* argv[])
{
	bool abundant[UPP_LIM+1] = {false};
	for (int i = LOW_LIM / 2; i <= UPP_LIM; i++)
	{
		if (abundant[i])
			continue;
		int a = sum_divisors_of(i);
		if (a >= i)
			for (int j = i + (a == i ? i : 0); j <= UPP_LIM; j+= i)
				abundant[j] = true;
	}

	int sum = 0;
	for (int i = 1; i <= UPP_LIM; i++)
		if (!is_sum_of_abundants(i, abundant))
			sum += i;
	printf("%d\n", sum);
	return 0;
}
