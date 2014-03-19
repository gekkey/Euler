int problem()
{
	int limit = 4000000;
	int out = 0;
	
	int a = 0; int b = 1; int c;
	while ( b <= limit )
	{
		if ( b % 2 == 0 )
		{
			out += b;
		}
		c = b; b = b+a; a = c;
	}
	return out;
}