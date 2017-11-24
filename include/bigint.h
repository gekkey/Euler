#include <list>
#include "digits.h"

struct bigint
{
	bigint();
	bigint(char&);
	bigint(const int&);
	bigint(std::list<unsigned long>&);

	void to_str(char *, int=0);
	std::list<unsigned long> data;
	bool sign;

	bigint& operator=(bigint);
	bigint& operator=(const int&);
	bigint operator+(bigint);
	bigint& operator+=(const bigint&);
	bigint operator-(bigint);
	bigint& operator-=(const bigint&);
	bigint operator*(bigint);
	bigint& operator*=(const bigint&);
	bigint operator/(bigint);
	bigint& operator/=(const bigint&);
	int len();
};
