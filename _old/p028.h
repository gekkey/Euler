long long int problem()
{
	long long int sum = 1;
	int side = 2;
	int side_length = 1;
	int skip = side_length;
	
	for ( int i = 2; i <= ( 1001*1001 ); i++ )
	{
		if ( skip == 0 )
		{
			sum += i;
			side ++;
			skip = side_length;
		}
		else
		{
			skip -= 1;
		}
		if ( side > 4 )
		{
			side = 1;
			side_length += 2;
		}
	}
	return sum;
}
