long long int problem()
{
	long long int i = 210;
	int consecutive = 0;
	while( i )
	{
		if ( consecutive == 4 )
			return i - 4;
		
		if ( distinct(primeFactorsOf( i )) == 4 )
			consecutive += 1;
		else
			consecutive = 0;
		
		i++;
	}
			
}
