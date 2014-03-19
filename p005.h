long long int problem()
{
	long long int testing = 20;
	bool completed = false;
	while ( 1 )
	{
		for ( int i = 2; i <= 20; i++)
		{
			completed = true;
			if ( testing % i != 0 )
			{
				completed = false;
				//std::cout << testing << " failed" << std::endl;
				break;
			}
		}
		if ( completed == true )
		{
			return testing;
		}
		testing += 20;
	}
}