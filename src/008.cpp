#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	// read 1000 digit array from text file
	char *number = (char *)malloc(1000 * sizeof(char));
	FILE *fo = fopen("data/008.txt", "r");
	int i = 0, n;

	while (fscanf(fo, "%s\n%n", &(number[i]), &n) != EOF)
		i += n - 1;
	

	// find 13 digit run with largest product
	long t, r = 0;
	for (i = 0; i < 1000 - 13; i++)
	{
		t = 1;
		for (int j = 0; j < 13; j++)
			t *= number[i+j] - '0';
		if (t > r)
			r = t;
	}

	printf("%ld\n", r);
	return 0;
}
