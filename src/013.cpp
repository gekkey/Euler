#include <cstdio>
#include "bigint.h"

int main()
{
	FILE *fo = fopen("data/013.txt", "r");
	char line[51];
	char buf[11];
       	line[50] = '\0';
	bigint sum = 0;

	while (fscanf(fo, "%s", line) != EOF)
	{
		sum += bigint(line);
	}
	sum.to_str(buf, 10);
	printf("%s\n", buf);

	return 0;
}
