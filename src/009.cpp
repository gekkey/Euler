#include <stdio.h>

int main(int argc, char *argv[])
{
	// a < b < c
	// a = 1..332
	// b = (a + 1)..(sqrt(a^2 + b^2) > 1000 - a - b)
	
	// build a table for fast sqrt
	const short c_max = 1000;
	short *sqrt = new short[c_max*c_max + 1]();
	for (short i = 1; i <= c_max; i++)
		sqrt[i*i] = i;


	int c;
	for (int a = 1; a < 333; a++) {
		for (int b = a + 1; b < 666; b++) {
			if (!(c = sqrt[a*a + b*b]))
				continue;
			if (a + b + c == 1000) {
				printf("%d\n", a * b * c);
				return 0;
			}
		}
	}

	return 0;
}
