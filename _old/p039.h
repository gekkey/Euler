long long int problem()
{
	int p = 1000;
	int solutions[p+1];
	long long int largest[2] = { 0, 0 };
	
	while ( p )
	{
		solutions[p] = 0;
		for ( double a = 1; a < ( p / 3 ); a++ )
		{
			for ( double b = a + 1; b < ( p / 2 ); b++ )
			{
				double c = sqrt( ( a*a + b*b ) );
				if ( a + b + c == p )
				{
					std::cout << "{" << a << ", " << b << ", " << c << "}" << std::endl;
					solutions[p]++;
				}
			}
		}
		
		if ( solutions[p] > largest[0] )
		{
			largest[0] = solutions[p];
			largest[1] = p;
		}
		
		p -= 1;
	}
	return largest[1];
}
