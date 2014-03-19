long long int problem()
{
	bool found = false;
	long long int i = 2;
	long long int n;
	long long int m;
	while ( !found )
	{
		n = i * (3*i - 1) / 2;
		for ( int j = 1; j < i; j++ )
		{
			m = j * (3*j - 1) / 2;
			if ( isPentagonal( n + m ) && isPentagonal( n - m ) )
			{
				return n - m;
			}
		}
		i++;
	}
	return 0;
}
