long long int problem()
{
	//std::vector< bool > isprime = sieve(1000000000);
	double primes = 0.0;
	double total = 1.0;
	long long int current = 1;
	int increment = 2;
	int corner = 0;
	
	do
	{
		//std::cout << primes << " / " << total << " = " << primes / total << std::endl;
		if ( corner == 4 )
		{
			corner = 0;
			increment += 2;
		}
		current += increment;
		corner++;
		total++;
		if ( isPrime(current) )
			primes ++;
	}
	while ( primes / total >= 0.1 );
	return increment + 1;
}
