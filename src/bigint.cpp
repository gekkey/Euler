#include <list>
#include <utility>
#include <iostream>
#include <climits>
#include <cstring>
#include <cstdlib>
#include "bigint.h"
#include "digits.h"

#define from_str std::strtoull

/* Pay attention to the arguments; C++ passes by copy by default
*/

// =====================================
// HELPERS
// =====================================
int bigint::len()
{
	return data.size();
}
template <typename T>
list_t cstr_to_fullword_list(T c[], int base = 10)
{
	bigint a = 0;
	for (int i = 0; c[i] != '\0'; i++)
	{
		a *= base;
		a += c[i] - '0';
	}

	return a.data;
}
void bigint::print_words()
{
	for (auto it = this->data.begin(); it != this->data.end(); it++)
		std::cout << std::hex << *it << ' ';
	std::cout << std::endl;
}

// returns first `len` characters (0 = all; possible overflow)
void bigint::to_str(char c[], int len = 0)
{
	bigint temp(*this);
	std::list<char> chars;
	while (temp != 0)
	{
		chars.push_front(temp.remainder_and_set(10) + '0');
	}
	if (len == 0) len = chars.size();

	int i = 0;
	for (auto ai = chars.begin(); ai != chars.end() && i < len; ai++, i++)
	{
		c[i] = *ai;
	}
	c[i] = '\0';
}


// =====================================
// INITIALIZATION
// =====================================
bigint::bigint()
{
	data = list_t {0};
}
bigint::bigint(char *a, int base)
{
	data = cstr_to_fullword_list(a, base);
}
bigint::bigint(const char *a, int base)
{
	data = cstr_to_fullword_list(a, base);
}
bigint::bigint(const int &a)
{
	data = list_t {(fullword)a};
}
bigint::bigint(const fullword &a)
{
	data = list_t {a};
}
bigint::bigint(fullword &a)
{
	data = list_t {a};
}
bigint::bigint(list_t a)
{
	data = a;
}
bigint::bigint(bigint &a)
{
	data = a.data;
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

// =====================================
// TESTS
// =====================================
bool bigint::operator==(const bigint& other)
{
	if (this->data.size() != other.data.size())
		return false;
	auto ai = this->data.begin();
	auto bi = other.data.begin();
	for (; ai != this->data.end(); ai++, bi++)
		if (*ai != *bi)
			return false;
	return true;
}
bool bigint::operator==(const int& other)
{
	return this->data.size() == 1 &&
	       this->data.front() == (fullword)other;
}
bool bigint::operator!=(const bigint& other)
{
	return ! (*this == other);
}
bool bigint::operator!=(const int& other)
{
	return ! (*this == other);
}

bool bigint::operator<(const bigint& other)
{
	if (this->data.size() < other.data.size())
		return true;
	if (this->data.size() > other.data.size())
		return false;
	auto ai = this->data.begin();
	auto bi = other.data.begin();
	for (; ai != this->data.end(); ai++, bi++)
	{
		if (*ai < *bi)
			return true;
		if (*ai > *bi)
			return false;
	}
	// equal
	return false;
}

// =====================================
// ADDITION
// =====================================
bigint& bigint::operator+=(const bigint& other)
{
	list_t& a = this->data, b = other.data;
	bool carried = 0, to_carry;
	fullword prev;

	auto ai = a.rbegin();
	auto bi = b.rbegin();
	// add overlapping
	while (ai != a.rend() && bi != b.rend())
	{
		prev = *ai;
		*ai += *bi;
		*ai += carried;
		//to_carry = (~*bi < carried) || (~*ai < (*bi + carried));
		carried = (*ai < prev);
		ai++;
		bi++;
	}
	// carry the carry bit
	while (carried && ai != a.rend())
	{
		to_carry = (~*ai < carried);
		*ai += carried;
		ai++;
		carried = to_carry;
	}
	// prepend the non-overlapping
	while (bi != b.rend())
	{
		to_carry = (~*bi < carried);
		a.push_front(*bi + carried);
		bi++;
		carried = to_carry;
	}
	if (carried)
		a.push_front(carried);
	return *this;
}
bigint& bigint::operator+=(bigint& other)
{
	return *this += bigint(other);
}

bigint bigint::operator+(bigint other)
{
	return other += *this;
}

template <typename T>
bigint& bigint::operator+=(T& x)
{
	return *this += bigint((fullword)x);
}

// =====================================
// SUBTRACTION
// =====================================
// assume this > other
// TODO support negative numbers
bigint& bigint::operator-=(const bigint& other)
{
	list_t &a = this->data, b=other.data;
	bool carried = 0, to_carry;
	fullword prev;

	auto ai = a.rbegin();
	auto bi = b.rbegin();
	while (ai != a.rend() && bi != b.rend())
	{
		prev = *ai;
		*ai -= *bi;
		*ai -= carried;
		if (*ai > prev) to_carry = 1;
		std::cout << *ai << std::endl;
		ai++;
		bi++;
		carried = to_carry;
	}
	while (carried && ai != a.rend())
	{
		to_carry = (*ai < carried);
		*ai -= carried;
		ai++;
		carried = to_carry;
	}
	if (a.front() == 0)
		a.pop_front();
	return *this;
}
bigint& bigint::operator-=(bigint& other)
{
	return *this -= bigint(other);
}

bigint bigint::operator-(bigint other)
{
	return other -= *this;
}

template <typename T>
bigint& bigint::operator-=(T& x)
{
	return *this -= bigint((fullword)x);
}


// =====================================
// BIT-SHIFTING
// =====================================
bigint& bigint::operator<<=(unsigned bits)
{
	list_t &a = this->data;
	while (bits >= fullword_bits)
	{
		a.push_back(0);
		bits -= fullword_bits;
	}
	if (!bits) return *this;

	a.push_front(0);
	auto ai = a.begin(), aj = a.begin();
	ai++;
	// ai is the number being shifted; aj is where it is shifted to
	for (; ai != a.end(); ai++)
	{
		*aj += *ai >> (fullword_bits - bits);
		*ai <<= bits;
		aj++;
	}
	if (a.front() == 0) a.pop_front();

	return *this;
}

bigint bigint::operator<<(unsigned bits)
{
	return bigint(list_t(this->data)) <<= bits;
}


// =====================================
// MULTIPLICATION
// =====================================

bigint& bigint::operator*=(const bigint& other)
{
	list_t& a = this->data;
	const list_t& b = other.data;
	int offset_a = 0, offset_b;
	bigint sum(0);

	for (auto ai = a.rbegin(); ai != a.rend(); ai++)
	{
		offset_b = 0;
		fullword x1 = *ai >> halfword_bits, x2 = *ai & halfword_mask;
		for (auto bi = b.rbegin(); bi != b.rend(); bi++)
		{
			fullword y1 = *bi >> halfword_bits, y2 = *bi & halfword_mask;

			bigint temp(0);
			temp += x1 * y1;
			temp <<= 32;
			temp += x1 * y2;
			temp += x2 * y1;
			temp <<= 32;
			temp += x2 * y2;
			temp <<= (offset_a + offset_b);
			sum += temp;
			offset_b += 64;
		}
		offset_a += 64;
	}

	this->data.swap(sum.data);
	return *this;
}

bigint bigint::operator*(bigint other)
{
	return other *= *this;
}

bigint& bigint::operator*=(const int& x)
{
	return *this *= bigint(x);
}

bigint bigint::operator*(const int& x)
{
	return bigint(x) *= *this;
}


// =====================================
// DIVISION
// =====================================

d_r bigint::divide(const int& d)
{
	list_t& a = this->data;
	list_t b(a.size(), 0x0);
	fullword n, q, r = 0;

	for (auto ai = a.begin(), bi = b.begin(); ai != a.end(); ai++, bi++)
	{
		// high half
		n = (r << 32) + (*ai >> 32);
		q = n / d;
		r = n % d;
		*bi += (q << 32);

		// low half
		n = (r << 32) + (*ai & 0xffffffff);
		q = n / d;
		r = n % d;
		*bi += q;
	}
	if (b.front() == 0 && b.size() > 1)
		b.pop_front();
	return (d_r){b, (int)r};
}
fullword bigint::remainder_and_set(const int& d)
{
	d_r result = this->divide(d);
	this->data.swap(result.d);
	return result.r;
}

bigint bigint::operator/(const int& d)
{
	bigint r(this->divide(d).d);
	return r;
}

bigint& bigint::operator/=(const int& d)
{
	this->remainder_and_set(d);
	return *this;
}

/*
bigint& bigint::operator/=(const bigint& other)
bigint bigint::operator/(bigint other)
*/

int bigint::operator%(const int& d)
{
	return this->divide(d).r;
}

// =====================================
// TEMPLATE INSTANCIATION
// =====================================
template list_t cstr_to_fullword_list<>(char[], int);
template list_t cstr_to_fullword_list<>(const char[], int);

template bigint& bigint::operator+=<>(int &);
template bigint& bigint::operator+=<>(long &);
template bigint& bigint::operator+=<>(unsigned int &);
template bigint& bigint::operator+=<>(unsigned long &);
template bigint& bigint::operator+=<>(const int &);
template bigint& bigint::operator+=<>(const long &);
template bigint& bigint::operator+=<>(const unsigned int &);
template bigint& bigint::operator+=<>(const unsigned long &);

template bigint& bigint::operator-=<>(int &);
template bigint& bigint::operator-=<>(long &);
template bigint& bigint::operator-=<>(unsigned int &);
template bigint& bigint::operator-=<>(unsigned long &);
template bigint& bigint::operator-=<>(const int &);
template bigint& bigint::operator-=<>(const long &);
template bigint& bigint::operator-=<>(const unsigned int &);
template bigint& bigint::operator-=<>(const unsigned long &);
