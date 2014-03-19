long long int problem()
{
	std::string teststring;
	long long int largest = 0;
	for ( int i = 999; i >= 100; i -= 1)
	{
		for ( int j = 999; j >= 100; j -= 1)
		{
			std::stringstream convert;
			convert << i*j;
			teststring = convert.str();
			if ( teststring == flip( teststring ) )
			{
				long long int current;
				std::istringstream( teststring ) >> current;
				if ( current >= largest )
				{
					std::cout << teststring << std::endl; 
					largest = current;
				}
			}
		}
	}
		return largest;
}