long long int problem()
{
	std::vector< bool > is_prime = sieve( 100000000 );
	std::vector< int > prime;
	std::vector< std::array< long long int, 6> > combs;
	std::array< long long int, 6> comb;
	std::array< long long int, 6> lowest;
	lowest[5] = 60000;
	
	for ( unsigned int i = 0; i < 9999; i++ )
		if ( is_prime[i] )
			prime.push_back( i );
	
	for ( unsigned int i = 0; i < prime.size(); i++ )
	{
		comb[0] = prime[i];
		for ( unsigned int j = i+1; j < prime.size(); j++ )
		{
			comb[1] = prime[j];
			if ( !is_prime[joinInts( comb[0], comb[1] )] )
				continue;
			if ( !is_prime[joinInts( comb[1], comb[0] )] )
				continue;
			
			for ( unsigned int k = j+1; k < prime.size(); k++ )
			{
				comb[2] = prime[k];
				if ( !is_prime[ joinInts( comb[0], comb[2] )] )
					continue;
				if ( !is_prime[ joinInts( comb[1], comb[2] )] )
					continue;
				if ( !is_prime[ joinInts( comb[2], comb[0] )] )
					continue;
				if ( !is_prime[ joinInts( comb[2], comb[1] )] )
					continue;
				
				for ( unsigned int l = k+1; l < prime.size(); l++ )
				{
					comb[3] = prime[l];
					if ( !is_prime[ joinInts( comb[0], comb[3] )] )
						continue;
					if ( !is_prime[ joinInts( comb[1], comb[3] )] )
						continue;
					if ( !is_prime[ joinInts( comb[2], comb[3] )] )
						continue;
					if ( !is_prime[ joinInts( comb[3], comb[0] )] )
						continue;
					if ( !is_prime[ joinInts( comb[3], comb[1] )] )
						continue;
					if ( !is_prime[ joinInts( comb[3], comb[2] )] )
						continue;
					
					for ( unsigned int m = l+1; m < prime.size(); m++ )
					{
						comb[4] = prime[m];
						if ( !is_prime[ joinInts( comb[0], comb[4] )] )
							continue;
						if ( !is_prime[ joinInts( comb[1], comb[4] )] )
							continue;
						if ( !is_prime[ joinInts( comb[2], comb[4] )] )
							continue;
						if ( !is_prime[ joinInts( comb[3], comb[4] )] )
							continue;
						if ( !is_prime[ joinInts( comb[4], comb[0] )] )
							continue;
						if ( !is_prime[ joinInts( comb[4], comb[1] )] )
							continue;
						if ( !is_prime[ joinInts( comb[4], comb[2] )] )
							continue;
						if ( !is_prime[ joinInts( comb[4], comb[3] )] )
							continue;
						
						comb[5] = comb[0] + comb[1] + comb[2] + comb[3] + comb[4];
						combs.push_back( comb );
					}
				}
			}
		}
	}
	
	for ( unsigned int i = 0; i < combs.size(); i++ )
		if ( combs[i][5] < lowest[5] )
			lowest = combs[i];
	
	return lowest[5];
}
