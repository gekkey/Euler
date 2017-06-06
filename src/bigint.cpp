#include <list>
#include <utility>
#include <iostream>
#include "bigint.h"
#include "digits.h"

bigint::bigint()
{
	data = std::list<char> {0};
}
bigint::bigint(const int& a)
{
	data = reverse_digit_list(a);
}
bigint::bigint(std::list<char>& a)
{
	data = a;
}
bigint::bigint(char& a)
{
	data = reverse_digit_list(&a);
}
char *bigint::cstr(int len) // FIXME memory leak
	/* returns first `len` characters (default 0 = all) */
{
	if (!len)
		len = this->data.size();
	char *c = new char[len+1];
	c[len] = '\0';
	int i = 0;

	for (
	std::list<char>::reverse_iterator di = data.rbegin();
	di != data.rend() && i < len;
	di++,i++)
		c[i] = *di + '0';

	return c;
}

bigint& bigint::operator=(bigint other)
{
	std::swap(this->data, other.data);
	return *this;
}
bigint& bigint::operator=(const int& a)
{
	data = reverse_digit_list(a);
	return *this;
}

bigint bigint::operator+(bigint other)
{
	return other += *this;
}

bigint& bigint::operator+=(const bigint& x)
{
	std::list<char>& a = this->data;
	const std::list<char>& b = x.data;

	char sum, carry = 0;
	std::list<char>::iterator ai = a.begin();
	std::list<char>::const_iterator bi = b.begin();
	while (ai != a.end() || bi != b.end())
	{
		sum = carry;

		if (ai != a.end())
			sum += *ai;
		if (bi != b.end())
			sum += *bi;

		if (ai == a.end() && bi != b.end())
			a.push_back(sum % 10);
		else
			*ai = sum % 10;
		carry = sum / 10;

		if (ai != a.end())
			ai++;
		if (bi != b.end())
			bi++;
	}
	if (carry)
		a.push_back(carry);

	return *this;
}

bigint bigint::operator*(bigint other)
{
	return other *= *this;
}

bigint& bigint::operator*=(const bigint& x)
{
	std::list<char>& a = this->data;
	const std::list<char>& b = x.data;
	std::list<char> c = {0};

	char sum, carry = 0;
	std::list<char>::iterator ai;
	std::list<char>::const_iterator bi;
	std::list<char>::iterator ci, cr;
	for (bi = b.begin(),cr = c.begin(); bi != b.end(); bi++,cr++)
	{
		for (ai = a.begin(),ci = cr; ai != a.end(); ai++)
		{
			sum = *ai * *bi + carry;
			if (ci != c.end()) {
				sum += *ci;
				*ci = sum % 10;
				ci++;
			} else {
				c.push_back(sum % 10);
			}
			carry = sum / 10;
		}
		while (carry) {
			if (ci != c.end())
				*ci = carry % 10;
			else
				c.push_back(carry % 10);
			carry /= 10;
		}
	}

	this->data.swap(c);
	return *this;
}
