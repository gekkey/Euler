long long int problem()
{
	long long int a, b, c;
	std::vector< pyth > potentials(1);
	for ( a = 3; a < 1000; a++ )
	{
		for ( b = 3; b < 1000; b++ )
		{
			if ( a + b < 1000 )
			{
				c =  1000 - a - b;
				if ( a*a + b*b == c*c )
				{
					return a*b*c;
				}
			}
		}
		
	}
}