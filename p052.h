long long int problem()
{
	std::vector< long long int > current;
	bool retry;
	
	int i = 1;
	while ( i )
	{
		current = splitInt( i );
		retry = false;
		for ( int j = 2; j <= 6; j++ )
		{
			if ( isPermutation( current, splitInt(i*j) ) )
				continue;
			retry = true;
			break;
		}
		if ( retry == false )
			return i;
		i ++;
	}
	return -1;
}
