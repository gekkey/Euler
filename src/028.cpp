#include <cstdio>

/* Problem:
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

/* Solution:
 * n = the last corner in each ring
 * d = the distance to the next corner
 *
 * the corners are then: (n + d*1), (n + d*2), (n + d*3), (n + d*4)
 * or: 4n + 10d
 */

#define lim 1001

int main()
{
	int sum = 1;
	for (int n = 1, d = 2; d < lim; n += d * 4, d += 2)
		sum += n * 4 + d * 10;
	printf("%d\n", sum);
	return 0;
}
