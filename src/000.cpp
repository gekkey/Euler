#include "bigint.h"
#include <iostream>

// testing file
int main()
{
	char str[100];
	bigint a("340282366920938463463374607431768211455", 10);
	a.to_str(str, 0);
	std::cout << str << std::endl;
	a.print_words();
	return 0;
}
