long long int problem()
{
	int total = 0;
	int sum;
	
	for ( int i = 2; i < 295245; i++ )
	{
		std::string current_string = convertInt(i);
		sum = 0;
		
		for ( unsigned int j = 0; j < current_string.size(); j++ )
		{
			sum += exponentOfInt(convertStr(convertChar(current_string[j])), 5);
		}
		if ( sum == i && sum != 1 )
		{
			std::cout << i << std::endl;
			total += i;
		}
	}
	return total;
}
