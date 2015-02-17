#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>
#include <string>
#include <unordered_map>
#include <ctime>
#include <gmp.h>
#include <gmpxx.h>
#include <time.h>
//#include <windows.h>
#include "sharedfunctions.h"
//#include "testing.h"
#include "p067.h"

long long int x;

int main()
{
	x = problem();
	std::cout.precision(32);
	std::cout << x << std::endl;
	return x;
}
