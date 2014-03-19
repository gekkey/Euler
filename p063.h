long long int problem()
{
	long long int n;
	long long int j;
	int sum = 0;
	//upper bound is when digitsIn(9^n) is less than n
	for ( long long int i = 1; i < 10; i++ )
	{
		for ( j = 1; j < 25; j++ )
		{
			// n = i^j
			n = 1; 
			for ( int k =  0; k < j; k++ ) n = n * i;
			
			if ( n < 0 || digitsInInt( n ) > 18 ) // if the numbers get too big for ints, try again with gmp
			{
				mpz_t t;
				mpz_init_set_ui( t, 1 );
				for ( int k =  0; k < j; k++ ) mpz_mul_ui( t, t, i );
				if ( digitsInMpz( t ) < j )
					break;
			}
			else if ( digitsInInt( n ) < j )
				break;
		}
		sum += j-1;
	}
	return sum;
}
