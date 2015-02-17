int problem()
{
	int i = 0; int x = 0;
	while(i < 1000)
	{
		if ( (i % 3 == 0) || (i % 5 == 0) )
		{
			x += i;
		}
		i ++;
	}

	return x;
}