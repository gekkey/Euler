//Fuck this problem; don't even bother trying to read it
//I had to deal with arrays AND the gmp library, so it's
//a confederacy of nonsense.

long long int problem()
{
	int limit = 100;
	long long int answer = 0;
	mpz_t temp; mpz_init(temp);
	mpz_t factorial_table[limit+1];
	char *str;
	
	for ( int i = 0; i <= limit; i++ )
	{
		mpz_init(factorial_table[i]);
		longFactorial( factorial_table[i], i );
	}
	
	longNCR( temp, 23, 10, factorial_table );
	
	for ( int n = 1; n <= limit; n++ )
	{
		for ( int r = 1; r <= n; r++ )
		{
			longNCR( temp, n, r, factorial_table );
			if ( digitsInMpz( temp ) > 6 )
				answer ++;
		}
	}
			
	return answer;
}
