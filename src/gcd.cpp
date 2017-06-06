#include <algorithm>

int gcd(int a, int b)
{
	if (a == 0) return b;
	if (b == 0) return a;

	int shift = __builtin_ctz(a | b);
	a >>= __builtin_ctz(a);
	do {
		b >>= __builtin_ctz(b);
		if (a > b) {
			//std::swap(a, b);
			int t = a;
			a = b;
			b = t;
		}
		b -= a;
	} while (b);

	return a << shift;
}
