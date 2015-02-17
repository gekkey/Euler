long long int problem()
{
	int n = 2000000;
	std::vector<bool> seive(n, true);
	for ( int i = 2; i <= sqrt(2000000.0); i++ )
	{
		if ( seive.at(i) == true )
		{
			for ( long long int j = i*i; j <= n-1; j += i )
			{
				seive.at(j) = false;
			}
		}
	}
	std::cout << "list compiled" << std::endl;
	// now `seive` is a list of primes less than n
	long long int j = 0;
	for ( int i = 2; i < seive.size(); i++ )
	{
		if ( seive.at(i) == true )
		{
			j += i;
		}
	}
	return j;
}