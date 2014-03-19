long long int problem()
{
	std::vector<long long int> factors = Factors(600851475143);
	long long int x = 0;
	for (long long int i = 0; i < factors.size(); i++)
	{
		if ( isPrime( factors.at(i) ) == true )
		{ 
			if ( factors.at(i) > x)
			{
				x = factors.at(i);
			}
		}
	}

	return x;

}