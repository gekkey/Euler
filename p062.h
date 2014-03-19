long long int problem()
{
	std::vector< long long int > cube = {0};
	std::unordered_map<long long int,int> perm;
	long long int i = 1;
	long long int n;
	std::vector< long long int > t;
	int largest;
	
	while ( true )
	{
		cube.push_back( i*i*i );
		t = splitInt( cube[i] );
		n = 0;
		for ( int j = 0; j < digitsInInt( cube[i] ); j++ )
		{
			largest = 0;
			for ( unsigned int k = 0; k < t.size(); k++ )
				if ( t[k] > largest )
					largest = t[k];
			for ( unsigned int k = 0; k < t.size(); k++ )
				if ( t[k] == largest )
				{
					t.erase(t.begin()+k);
					break;
				}
			n = n*10 + largest;
		}
		
		if ( perm.count( n ) == 0 )
			perm[n] = 0;
		perm[n]++;
		if ( perm[n] == 5 )
			for ( unsigned int j = 0; j < cube.size(); j++ )
				if ( isPermutation(cube[j], n) )
					return cube[j];
		i++;
	}
	return -1;
}
