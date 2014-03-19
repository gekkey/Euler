long long int problem()
{
	int n;
	int S = 1; // number
	int total = 0;
	int upperbound = 10000; // max value of S to test
	unsigned int pattern_length = 1;
	int pattern_accuracy = 500; // the sample size to test the pattern cadidates against
	std::vector< long long int > a, pattern;
	bool broke;

	while ( S < upperbound )
	{
		// Skip perfect squares
		S++;
		if ( sqrt( S ) == (int)sqrt( S ) )
			continue;
		
		// Generate the continued fraction "a"
		a = genContFrac( S, pattern_accuracy );
		
		// Figure out a pattern
		pattern_length = 1;
		while ( pattern_length < a.size()/2 )
		{
			broke = false;
			pattern = std::vector< int >( a.begin()+1, a.begin()+1+pattern_length );
			for ( unsigned int i = 1+pattern_length; i < a.size()-pattern_length; i+=pattern_length )
				if ( pattern != std::vector< int >( a.begin()+i, a.begin()+i+pattern_length ) )
				{
					broke = true;
					break;
				}
			if ( !broke )
				break;
			
			pattern_length++;
		}
		if ( pattern_length%2 )
			total++;
	}
	
	return total;
}
