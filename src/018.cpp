#include <cstdlib>
#include <cstdio>
#include <algorithm>

#define lastline 15
int main(int argc, char *argv[])
{
	FILE *fo = fopen("data/018.txt", "r");
	char num;
	int *line = (int*)malloc(sizeof(int) * lastline + 1);
	int *nextline = (int*)malloc(sizeof(int) * lastline + 1);
	int i = 0,linelen = 1;

	while (fscanf(fo, "%hhd", &num) != EOF)
	{
		line[i] += num;
		if (i == 0) // first ...
			nextline[i] = line[i];
		else
			nextline[i] = (line[i-1] > line[i] ? line[i-1] : line[i]);
		if (i == linelen - 1) // and last have only one option
			nextline[linelen] = line[linelen-1];
		if (++i == linelen) {
			i = 0;
			linelen++;
			std::swap(line, nextline);
		}
	}

	int largest = 0;
	for (i = 0; i < lastline; i++) {
		if (line[i] > largest)
			largest = line[i];
	}

	printf("%d\n", largest);
	return 0;
}
