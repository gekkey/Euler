#include <cmath>
#include <cstdio>

/* Problem:
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 1^4 + 6^4 + 3^4 + 4^4
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4

As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

/* Solution:
 * set the upper bound to when the largest number becomes smaller than the sum of its powers,
 * after which all numbers will be smaller
 * 9 < 59049; 99999 < 295245; 999999 > 354294; 9999999 > 413343; 99999999 > 472392
 * 
 */

#define exp 5

int main()
{
	int total = 0;
	int n, lim = 9;
	for (n = pow(9, exp); n > lim; n += pow(9, exp), lim = lim * 10 + 9);

	for (n = 2; n <= lim; n++)
	{
		int sum = 0;
		for (int i = n; i && sum <= n; i /= 10)
			sum += pow(i % 10, exp);
		if (sum == n)
			total += n;
	}

	printf("%d\n", total);
	return 0;
}
