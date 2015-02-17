bool isLychrel( int n )
{
	mpz_t x; mpz_init(x);
	mpz_t y; mpz_init(y);
	mpz_set_ui(x, n);
	for( int i = 0; i < 50; i++ )
	{
		mpz_set(y, x);
		flipMpz_t(y);
		mpz_add(x, x, y);
		if ( isPalindrome( x ) )
			return false;
	}
	return true;
}

long long int problem()
{
	int n = 1;
	int lychrel = 0;
	while ( n < 10000 )
	{
		if ( isLychrel( n ) )
			lychrel++;
		n++;
	}
	return lychrel;
}
