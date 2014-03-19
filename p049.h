long long int problem()
{
	int set = 1;
	
	for ( int i = 1234; i < 10000 - 3; i++ )
	{
		if ( !isPrime( i ) )
			continue;
			
		for ( int j = 1; i + j + j < 10000; j++ )
		{
			if ( !isPrime( i+j ) )
				continue;
			if ( !isPrime( i+j+j ) )
				continue;
			if( isPermutation( splitInt(i), splitInt(i+j) ) && 
				isPermutation( splitInt(i+j), splitInt(i+j+j) ) )
			{
				std::cout << "set " << set << ": " << i << ", " << i+j << ", " << i+j+j << std::endl;
				set++;
			}
		}
	}
	return 0;
}
