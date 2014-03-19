long long int problem()
{
	long long int sum = 0;
	std::vector< long long int > convert;
	std::vector< long long int > current;
	std::vector< bool > primes = sieve( 1000000 );
	short int primes_found = 0;
	bool truncatable;
	long long int i = 8;
	
	while ( primes_found < 11 )
	{
		current = splitInt(i);
		truncatable = true;
		
		for ( unsigned int j = 0; j < current.size(); j++ )
		{
			convert.assign( current.begin() + j, current.end() );
			if ( !primes[joinIntVector( convert )] )
			{
				truncatable = false;
				break;
			}
			convert.assign( current.begin(), current.end() - j );
			if ( !primes[joinIntVector( convert )] )
			{
				truncatable = false;
				break;
			}
		}
		if ( truncatable )
		{
			sum += joinIntVector( current );
			primes_found++;
			std::cout << joinIntVector( current ) << std::endl;
		}
		i += 1;
	}
	return sum;
}
