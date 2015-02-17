long long int problem()
{
	int i = 5777;
	bool found;
	while ( i )
	{
		if ( isPrime( i ) )
		{
			i+=2;
			continue;
		}
		found = false;
		for ( int j = 3; j < i; j+=2 )
		{
			if ( !isPrime( j ) )
			{
				j+=2;
				continue;
			}
			int k = 1;
			while ( j + 2*k*k <= i )
			{
				if ( j + 2*k*k == i )
				{
					std::cout << i << " = " << j << " + 2*" << k << "^2" << std::endl;
					found = true;
					break;
				}
				k++;
			}
			if ( found )
				break;
		}
		if ( !found )
			return i;
			
		i += 2;
	}
	return 0;
}
		
