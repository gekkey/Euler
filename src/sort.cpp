#include <iostream>
#include "sort.h"

template <class T>
void print_array(T a, int len)
{
	for (int i = 0; i < len; i++)
		std::cout << a[i] << ", ";
	std::cout << std::endl;
}

bool default_cmp(int a, int b)
{
	return a > b;
}

template <class T>
void quicksort(T *a, int size)
{
	quicksort(a, size, (bool (*)(int, int))(default_cmp));
}
template <class T, class U>
void quicksort(T *a, int size, U cmp)
{
	if (size <= 1)
		return;
	if (size == 2) {
		if (cmp(a[0], a[1]))
			std::swap(a[0], a[1]);
		return;
	}
	// pivot = median(0, size/2, size-1)
	int b[3] = {0, size/2, size-1};
	if (cmp(a[b[0]], a[b[1]]))
		std::swap(b[0], b[1]);
	if (cmp(a[b[1]], a[b[2]]))
		std::swap(b[1], b[2]);
	if (cmp(a[b[0]], a[b[1]]))
		std::swap(b[0], b[1]);
	int &pivot = b[1];

	if (pivot != size-1)
		std::swap(a[size-1], a[pivot]);
	pivot = size - 1;

	int i = 0, j = size - 1 - 1;
	while (i < j)
	{
		while (!cmp(a[i], a[pivot]))
			i++;
		while (cmp(a[j], a[pivot]))
			j--;
		std::swap(a[i], a[j]);
	}
	std::swap(a[i], a[j]);
	std::swap(a[pivot], a[i]);

	/*
	if (size < 20) {
		printf("left: ");
		for (int k = 0; k < i; k++)
			printf("%s ", a[k]);
		printf("\npivot: %s\nright: ", a[i]);
		for (int k = i + 1; k < size; k++)
			printf("%s ", a[k]);
		printf("\n\n");
	}*/

	quicksort(a, i, cmp);
	quicksort(&a[i+1], size - i - 1, cmp);
}

template void quicksort<int>(int*, int);
template void quicksort<int,bool (*)(int,int)>(int*, int, bool (*)(int,int));
template void quicksort<char*,bool (*)(char*,char*)>(char**, int, bool (*)(char*,char*));
