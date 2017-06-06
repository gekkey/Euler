#include <cstdio>
#include "bigint.h"


int main(int argc, char *argv[])
{
	FILE *fo = fopen("data/013.txt", "r");
	char line[51];
       	line[50] = '\0';
	bigint sum;

	while (fscanf(fo, "%s", line) != EOF)
	{
		sum += bigint(*line);
	}
	printf("%s\n", sum.cstr(10));

	return 0;
}
