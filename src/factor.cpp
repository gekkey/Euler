#include <cstdio>
#include <cmath>

struct divisor_iterator
{
	int a, d = 1;
	divisor_iterator(int a = 0) : a(a) {};
	int operator*() { return d; }
	divisor_iterator operator=(int a) { this->a = a; return *this; }
	divisor_iterator operator++(int) { while(d*d < a && a % ++d); return *this; }
	explicit operator bool() const { return (d*d < a); }
};

int num_divisors_of(int a)
{
	int r = 2;

	divisor_iterator it = a;
	while (it++)
		r += 2;
	if ((*it+1)*(*it+1) == a)
		r++;

	return r;
}

void print_divisors(int a)
{
	printf("%d: ", a);
	for (divisor_iterator it = a; it; it++)
		printf("%d %d ", *it, (a / *it));
	printf("\n");
}

int sum_divisors_of(int a)
{
	int sum = 1;
	divisor_iterator it = a;
	while (it++)
		sum += *it + (a / *it);
	return sum;
}
