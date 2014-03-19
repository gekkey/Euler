long long int problem()
{
	bool found = false;
	long long int i = 286;
	long long int h;
	while ( !found )
	{
		h = i * (2 * i - 1);
		if ( isPentagonal( h ) )
			return h;
		i++;
	}
	return 0;
}
