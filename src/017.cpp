#include <cstdio>

int main(int argc, char *argv[])
{
	//            0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
	int ones[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
	int tens[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
	int hundred = 7;
	int thousand = 8;

	int word, sum = 0;
	for (int j = 1; j <= 1000; j++) {
		int i = j;
		word = 0;
		if (i % 100 < 20) {
			word += ones[i % 100];
			i /= 10;
		} else {
			word += ones[i % 10];
			i /= 10;
			word += tens[i % 10];
		}
		i /= 10;
		if (i) {
			if (word) {
				word += 3; // 'and'
			}
			word += ones[i % 10] + ((bool)(i % 10) * hundred);
		}
		i /= 10;
		if (i) {
			word += ones[i % 10] + thousand;
		}
		sum += word;
	}
	printf("%d\n", sum);
	return 0;
}
