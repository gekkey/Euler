long long int problem()
{
	int UPPER_LIMIT = 2540160; //9!7
	long long int sum = 0;
	long long int temp = 0;
	std::vector< long long int > current;
	
	for ( int i = 3; i < UPPER_LIMIT + 1; i++ )
	{
		current = split(i);
		temp = 0;
		for ( unsigned int j = 0; j < current.size(); j++ )
		{
			temp += factorial(current[j]);
		}
		if ( temp == i )
		{
			std::cout << i << std::endl;
			sum += i;
		}
	}
	return sum;
}
