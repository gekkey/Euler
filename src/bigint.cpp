#include <list>
#include <utility>
#include <iostream>
#include <climits>
#include "bigint.h"
#include "digits.h"

#define halfword unsigned int
#define halfword_bits 32
#define halfword_mask 0xFFFFFFFF
#define fullword unsigned long
#define fullword_bits 64
#define list_t std::list<fullword>

list_t full_mult(fullword x, fullword y)
{
	// separate x and y into 2 32-bit ints
	// the product of two 32-bit ints cannot be more than 64 bits
	fullword x1 = x >> halfword_bits, x2 = x & halfword_mask;
	fullword y1 = y >> halfword_bits, y2 = y & halfword_mask;

	// multiplication
	fullword z0, z1, z2, z3;
	z0 = x1 * y1;
	z1 = x1 * y2;
	z2 = x2 * y1;
	z3 = x2 * y2;

	// create return list
	list_t r = {z3, z0};
	fullword &r0 = r.front();
	fullword &r1 = r.back();

	// addition
	// z0 << 64 + z1 << 32 + z2 << 32 + z3
	char carry;
	r1 += z1 >> halfword_bits;
	z1 &= halfword_mask;
	z1 <<= halfword_bits;
	carry = r0 >> (fullword_bits - 1);
	r0 += z1;
	r1 += carry ^ r0 >> (fullword_bits - 1);

	r1 += z2 >> halfword_bits;
	z2 &= halfword_mask;
	z2 <<= halfword_bits;
	carry = r0 >> (fullword_bits - 1);
	r0 += z2;
	r1 += carry ^ r0 >> (fullword_bits - 1);

	return r;
}

void add_lists(list_t &a, const list_t &b)
{
	// alias the data lists to 'a' and 'b'
	bool carry, n_carry = 0;
	list_t::iterator ai = a.begin();
	list_t::const_iterator bi = b.begin();
	fullword *ap;
	while (ai != a.end() && bi != b.end())
	{
		carry = n_carry;
		ap = &(*ai);
		n_carry = (~*ap < (*bi + carry));
		*ap += *bi;
		*ap += carry;
		ai++;
		bi++;
	}
	while (bi != b.end())
	{
		a.push_back(*bi);
		bi++;
	}
	if (carry)
		a.push_back(carry);
}

bigint::bigint()
{
	data = list_t {0};
}
bigint::bigint(const int &a)
{
	data = list_t {(fullword)a};
}
bigint::bigint(list_t &a)
{
	data = a;
}
void bigint::to_str(char *c, int len)
	/* returns first `len` characters (default 0 = all) */
{
	if (!len)
		len = this->data.size();
	c[len] = '\0';
	//TODO
}

bigint& bigint::operator=(bigint other)
{
	std::swap(this->data, other.data);
	return *this;
}
bigint& bigint::operator=(const int& a)
{
	data = list_t {(unsigned long)a};
	return *this;
}

bigint bigint::operator+(bigint other)
{
	return other += *this;
}

bigint& bigint::operator+=(const bigint& x)
{
	add_lists(this->data, x.data);
	return *this;
}

bigint bigint::operator*(bigint other)
{
	return other *= *this;
}

bigint& bigint::operator*=(const bigint& x)
{
	// alias the data to a and b
	list_t& a = this->data;
	const list_t& b = x.data;

	if (a.

	long sum, carry = 0;
	list_t::iterator ai;
	list_t::const_iterator bi;
	for ()
	{
	}

	this->data.swap(c);
	return *this;
}

int bigint::len()
{
	return data.size();
}
