#include <stdlib.h>
#include <list>
#include <cstdio>
#include "digits.h"

struct digit_iterator
{
	int value;
	digit_iterator(int a = 0) : value(a) {};
	char operator*() { return value % 10; }
	digit_iterator operator=(int a) { value = a; return *this; }
	digit_iterator operator++(int) { value /= 10; return *this; }
	explicit operator bool() const { return value; }
};


int num_digits_in(int a)
{
	int i = 0;
	digit_iterator it(a);
	while (it++)
		i++;
	return i;
}

char *digit_array(int a)
{
	int n = num_digits_in(a);
	char *arr = (char *)malloc(n * sizeof(char));

	for (digit_iterator it(a); it; it++)
		arr[n--] = *it;
	return arr;
}

std::list<char> digit_list(int a)
{
	std::list<char> l;
	digit_iterator it(a);
	for (it = a; it; it++)
		l.push_front(*it);
	return l;
}
std::list<char> reverse_digit_list(int a)
{
	std::list<char> l;
	digit_iterator it(a);
	for (it = a; (bool)it; it++)
		l.push_back(*it);
	return l;
}

std::list<char> reverse_digit_list(const char *a)
{
	std::list<char> l;
	char c;
	int i = 0;

	while ( (c = a[i]) != '\0' )
	{
		l.push_front(c - '0');
		i++;
	}

	return l;
}
