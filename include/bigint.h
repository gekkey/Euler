#include <list>
#include "digits.h"

#define halfword unsigned int
#define halfword_bits 32
#define halfword_mask 0xFFFFFFFF
#define fullword unsigned long
#define fullword_bits 64
#define list_t std::list<fullword>

struct d_r {
	list_t d;
	int r;
};

struct bigint
{
	bigint();
	bigint(char*, int=10);
	bigint(const char*, int=10);
	bigint(const int&);
	bigint(const fullword&);
	bigint(fullword&);
	bigint(bigint&);
	bigint(list_t);

	bool sign;
	list_t data;
	void to_str(char *, int);
	void print_words();
	int len();

	bigint& operator=(bigint);
	bigint& operator=(const int&);

	bigint operator+(bigint);
	bigint& operator+=(bigint&);
	bigint& operator+=(const bigint&);
	template <typename T> bigint& operator+=(T&);

	bigint operator-(bigint);
	bigint& operator-=(bigint&);
	bigint& operator-=(const bigint&);
	template <typename T> bigint& operator-=(T&);

	bigint operator<<(unsigned);
	bigint& operator<<=(unsigned);

	bigint operator*(bigint);
	bigint& operator*=(const bigint&);
	bigint operator*(const int&);
	bigint& operator*=(const int&);

	d_r divide(const int&);
	fullword remainder_and_set(const int&);
	bigint operator/(bigint);
	bigint& operator/=(const bigint&);
	bigint operator/(const int&);
	bigint& operator/=(const int&);
	int operator%(const int&);

	bool operator==(const int&);
	bool operator==(const bigint&);
	bool operator!=(const int&);
	bool operator!=(const bigint&);
	bool operator<(const int&);
	bool operator<(const bigint&);
	bool operator<=(const int&);
	bool operator<=(const bigint&);
	bool operator>(const int&);
	bool operator>(const bigint&);
	bool operator>=(const int&);
	bool operator>=(const bigint&);
};
