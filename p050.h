#define N 1000000

long long int problem()
{
	clock_t timer = clock();
	std::vector< bool > prime = sieve(N-1);
	std::vector< long long int > sequence;
	long long int largest = 0;
	unsigned int a = 0;
	unsigned int b = 0;
	std::cout << ((float)(clock() - timer)/CLOCKS_PER_SEC) << " seconds to generate sieve" << std::endl;
	timer = clock();
	
	for ( unsigned int i = 0; i < prime.size(); i++ )
	{
		if ( !prime[i] )
			continue;
		a++;
		
		sequence.push_back(0);
		for ( unsigned int j = 0; j < sequence.size(); j++ )
		{
			sequence[j] += i;
			if ( sequence[j] < N && prime[sequence[j]] && ( a - j > b ) )
			{
				b = a - j;
				largest = sequence[j];
			}
		}
	}
	std::cout << ((float)(clock() - timer)/CLOCKS_PER_SEC) << " seconds to find answer" << std::endl;
	
	return largest;
}
