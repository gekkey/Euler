#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include "permutation.h"


permutation_iterator::permutation_iterator(int len, int* values)
{
	this->len = len;
	this->values = values;
	this->order = (int*)malloc(sizeof(int)*len);
	for (int i = 0; i < len; i++) order[i] = i;
}
long permutation_iterator::to_long()
{
	long r = 0;
	for (int i = 0; i < len; i++) {
		r *= 10;
		r += values[order[i]];
	}
	return r;
}
bool permutation_iterator::step()
{
	int i = len - 2;
	int j = len - 1;
	while (order[i] >= order[i+1])
	{
		if (i == 0) {
			valid = false;
			return false;
		}
		--i;
	}
	while (order[i] >= order[j])
	{
		--j;
	}
	std::swap(order[i], order[j]);
	++i;
	j = len - 1;
	while (i < j)
	{
		std::swap(order[i], order[j]);
		++i;
		--j;
	}

	return true;
}
permutation_iterator permutation_iterator::operator=(int* a)
{
	this->values = values;
	return *this;
}
permutation_iterator permutation_iterator::operator++(int)
{
	this->step();
	return *this;
}
permutation_iterator::operator bool() const
{
	return this->valid;
}

bool is_permutation(int a, int b)
{
	if ((a<0) != (b<0))
		return false;

	char n = 0, m = 0;
	signed char digits[10] {};

	while (a)
	{
		digits[a%10]++;
		a /= 10;
		n++;
	}

	while (b)
	{
		digits[b%10]--;
		b /= 10;
		m++;
	}
	
	if ( n != m )
		return false;
	for (int i = 0; i < 10; i++)
		if ( digits[i] )
			return false;
	return true;
}
