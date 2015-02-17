long long int problem()
{
	std::ifstream instream;
	instream.open("p013.txt");
	std::string instring = "";
	std::string line;
	std::string convert;
	std::vector<long long int> numbers[100];
	int i = 0;
	while ( !( instream.eof() ) )
	{
		line = "";
		std::getline( instream, line );
		numbers[i].resize(50, 0);
		for ( int j = 0; j < line.length(); j++ )
		{
			convert = line.at(j);
			numbers[i].at(j) = convertStr(convert);
		}
		i++;
	}
	std::vector<long long int> add = numbers[0];
	for ( int i = 1; i < 100; i++ )
	{
		add = AddLong(add, numbers[i]);
	}
	for ( int i = 0; i < add.size(); i++ )
	{
		std::cout << add.at(i);
	}
	std::cout << std::endl;
	return 1;
}