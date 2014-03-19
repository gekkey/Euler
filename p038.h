long long int problem()
{
	long long int largest = 0;
	std::vector< long long int > current;
	
	long long int i = 1;
	long long int j;
	long long int current_int;
	while ( i < 10000 )
	{
		j = 1;
		while ( current.size() < 9 )
		{
			current = appendIntVectors( current, splitInt( i * j ) );
			j++;
			//print1DVector(current);
		}
		current_int = joinIntVector( current );
		//std::cout << i << ": " << current_int << std::endl;
		if ( isPandigital( current_int ) )
		{
			std::cout << i << ": " << current_int << std::endl;
			if ( current_int > largest )
				largest = current_int;
		}
		current.clear();
		i++;
	}
	return largest;
}
