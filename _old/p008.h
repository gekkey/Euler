long long int problem()
{
	std::ifstream instream;
	instream.open("p008.txt");
	std::string line;
	std::string instring = "";
	while ( !( instream.eof() ) )
	{
		std::getline( instream, line );
		instring += line;
	}
	long long int largest = 0;
	long long int current = 1;
	long long int add;
	std::string convert;
	for ( int i = 0; i < instring.length() - 5; i++ )
	{
		for ( int j = 0; j < 5; j++ )
		{
			convert = instring.substr(i + j, 1);
			add = convertStr(convert);
			current = current * add;
		}
		if ( current > largest )
		{
			largest = current;
		}
		current = 1;
	}
	return largest;
}