int gcd(int n, int m)
{
	if (n == m) return n;
	if (m == 0) return n;
	if (n == 0) return m;

	if (~n & 1) // n is even
	{
		if (m & 1) // m is odd
			return gcd(n >> 1, m);
		else // m is even
			return gcd(n >> 1, m >> 1) << 1;
	}
	if (~m & 1) // n is odd; m is even
		return gcd(n, m >> 1);

	// both are odd
	if (n > m)
		return gcd((n - m) >> 1, m);
	return gcd((m - n) >> 1, n);
}
