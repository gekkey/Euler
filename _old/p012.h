long long int problem()
{
	int current = 1;
	int increment = 2;
	while ( Factors(current).size() <= 500 )
	{
		current += increment;
		increment += 1;
	}
	return current;
}