long long int problem()
{
	int longest[3] = {0, 0, 1};
	int current_len;
	
	for ( int a = -1000; a < 1000; a++ )
	{
		for ( int b = -1000; b < 1000; b++ )
		{
			current_len = 0;
			for ( int n = 0; n < 1000; n++ )
			{
				if ( !isPrime( ( n*n ) + ( n * a ) + b ) )
				{
					break;
				}
				else
				{
					current_len ++;
				}
			}
			if ( current_len > longest[2] )
			{
				longest[0] = a;
				longest[1] = b;
				longest[2] = current_len;
				std::cout << current_len << "; " << "n^2 + " << a << "*n + " << b << std::endl;
			}
		}
	}
	return ( longest[0] * longest[1] );
}		
