long long int problem()
{
	std::vector< bool > primes = sieve(1000000);
	long long int counter = 0;
	bool circular_prime;
	
	for ( int i = 2; i < 1000000; i++ )
	{
		if ( !primes[i] )
			continue;
		long long int original = i;
		long long int current = original;
		circular_prime = true;
		for ( int j = 0; j < numberOfDigits(current); j++ )
		{
			if ( !( primes[current] ) || ( numberOfDigits(current) != numberOfDigits(original) ) )
				circular_prime = false;
			current = rotateDigits(current);
		}
		if ( circular_prime )
		{
			std::cout << i << std::endl;
			counter++;
		}
	}
	
	rotateDigits(10);
	
	return counter;
}
