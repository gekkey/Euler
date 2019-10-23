#include <cstring>
#include <cstdio>

/* Problem:
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

    1/2	= 	0.5
    1/3	= 	0.(3)
    1/4	= 	0.25
    1/5	= 	0.2
    1/6	= 	0.1(6)
    1/7	= 	0.(142857)
    1/8	= 	0.125
    1/9	= 	0.(1)
    1/10= 	0.1

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

/* Solution:
 * To get each digit, we do elementary long division:
 * 	for i in range(arbitrary_limit)
 * 		numerator *= 10
 * 		digits.append(numerator / divisor)
 * 		numerator %= divisor
 * 	loop_detection_function(digits)
 *
 * But we don't care about the actual digits. We're just looking for a repeated 
 * section, which will happed whenever the numerator repeats (since the divisor
 * is constant). If we're just looking for a repeated numerator, we can store 
 * where each one was first seen in a map. When we see one for the second time,
 * we know it's repeating. Having stored the index, we can get the distance 
 * to the first occurrence, which isn't always the beginning (see 1/6).
 */

#define lim 1000

int main()
{
	int n, i;
	int max_d = 0, max_i = 0;
	int seen[lim];

	for (int d = 2; d < lim; d++)
	{
		memset(seen, 0, lim * sizeof(int));
		for (n = 1, i = 1; n && ! seen[n]; i++)
		{
			seen[n] = i;
			n = (n * 10) % d;
		}
		i -= seen[n];
		if (seen[n] && i > max_i)
			max_d = d, max_i = i;
	}
	
	printf("%d\n", max_d);
	return 0;
}
