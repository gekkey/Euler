#include <list>
#include "digits.h"

struct bigint
{
	bigint();
	bigint(char&);
	bigint(const int&);
	bigint(std::list<char>&);
	char *cstr(int=0);
	std::list<char> data;
	bigint& operator=(bigint);
	bigint& operator=(const int&);
	bigint operator+(bigint);
	bigint& operator+=(const bigint&);
	bigint operator*(bigint);
	bigint& operator*=(const bigint&);
};
