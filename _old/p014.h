long long int problem()
{
	long long int i;
	long long int working;
	std::vector<long long int> longest(1, 0);
	for ( i = 1; i < 1000000; i++ )
	{
		std::vector<long long int> process(0, 0);
		working = i;
		while ( working != 1 )
		{
			process.resize(process.size()+1, working);
			if ( working % 2 == 0 )
			{
				working = working / 2;
			}
			else
			{
				working = working * 3 + 1;
			}
		}
		if ( process.size() > longest.size() )
		{
			longest = process;
			std::cout << longest.at(0) << std::endl;
		}
		process.clear();
	}
	return longest.at(0);
}