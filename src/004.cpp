#include <stdlib.h>
#include <stdio.h>
#include "digits.h"

int main()
{
	int r = 0; // return value
	int t; // temporary product
	char *digits;

	for (int i = 100; i < 1000; i++) {
		for (int j = 100; j < 1000; j++) {
			t = i * j;
			int n = 6; // two 3-digit numbers multiplied is 6 digits
			digits = digit_array(t);
			for (int k = 0; k < n / 2; k++) {
				if (digits[k] != digits[n-k-1]) {
					t = 0;
					break;
				}
			}
			free(digits);
			if (t > r)
				r = t;
		}
	}


	printf("%d\n", r);
	return 0;
}
