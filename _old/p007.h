long long int problem()
{
	int i = 0;
	int j = 1;
	while ( i < 10001 )
	{
		j++;
		if ( isPrime( j ) )
		{
			i++;
		}
	}
	return j;
}