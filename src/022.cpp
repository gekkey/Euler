#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include "sort.h"

#define NAME_LEN 14
#define INC 256
bool names_cmp(char *a, char *b)
{
	int i = 1;
	while (a[i] == b[i] && a[i] != '"' && b[i] != '"')
		i++;
	if (a[i] == '"') {
		return 0;
	} else if (b[i] == '"') {
		return 1;
	}
	return a[i] > b[i];
}
int value_of_name(char *name)
{
	int val = 0;
	char l;
	name++;
	while ((l=*(name++)) != '"')
		val += l - 'A' + 1;
	return val;
}

int main(int argc, char *argv[])
{
	FILE *fo = fopen("data/022.txt", "r");
	char *name = (char*)malloc(sizeof(char) * NAME_LEN);
	char **names = (char**)malloc(sizeof(char*) * 5000);
	int i = 0, size = INC;

	typedef bool (*fn)(char*,char*);
	fn cmp = &names_cmp;

	while (fscanf(fo, "%[^,],", name) != EOF) {
		if (i == size) {
			names = (char**)realloc(names, sizeof(char*)*(size += INC));
		}
		names[i] = name;
		name = (char*)malloc(sizeof(char) * NAME_LEN);
		i++;
	}
	size = i;
	quicksort(names, size, cmp);
	long sum = 0;
	for (i = 1; i <= size; i++) {
		sum += i*value_of_name(names[i-1]);
	}

	printf("%ld\n", sum);
	return 0;
}
