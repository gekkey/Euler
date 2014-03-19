#define N 1000000

long long int problem()
{
	std::vector< bool > prime = sieve(N);
	std::vector< long long int > current;
	std::vector< long long int > temp;
	std::vector< long long int > sequence;
	std::vector< std::vector< bool > > possible;
	int family_size;
	unsigned int previous_current_size = 0;
	
	for ( unsigned int i = 1000; i < prime.size(); i++ )
	{
		if ( !prime[i] )
			continue;
		
		current = splitInt( i );
		if ( current.size() != previous_current_size )
		{
			previous_current_size = current.size();
			possible = boolPermutation(current.size());
			possible.assign(possible.begin()+1, possible.end());
		}
		
		for ( unsigned int j = 0; j < possible.size(); j++ )
		{
			//printBinaryVector(possible[j]);
			family_size = 0;
			sequence.clear();
			for ( int k = 0; k < 10; k++ )
			{
				temp = current;
				for ( unsigned int l = 0; l < current.size(); l++ )
				{
					if ( possible[j][l] )
						temp[l] = k;
				}
				if ( prime[joinIntVector(temp)] && (current.size() == splitInt(joinIntVector(temp)).size()) )
				{
					family_size ++;
					sequence.push_back(joinIntVector(temp));
				}
			}
			if ( family_size == 8 )
			{
				print1DVector(sequence);
				return i;
			}
		}
	}
	
	return -1;
}
						
 
