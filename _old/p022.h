long long int problem()
{	
	std::ifstream instream;
	instream.open("p022.txt");
	std::string line;
	std::string name;
	std::vector<std::string> unsorted;
	while ( !( instream.eof() ) )
	{
		std::getline( instream, line );
		std::stringstream linestream;
		linestream << line;
		while (linestream.good())
		{
			std::getline(linestream, name, '"');
			if ( name != "," && name != "" )
			{
				unsorted.resize(unsorted.size()+1, name);
			}
		}
	}

	std::cout << "Sorting " << unsorted.size() << " names..." << std::endl;
	std::vector<std::string> names;
	names = alphabetizedVector(unsorted);

	long long int counter = 0;
	for ( int i = 0; i < names.size(); i++ )
	{
		for ( int j = 0; j < names[i].length(); j++ )
		{
			counter += valueOfStr(convertChar(names[i][j]))*(i+1);
		}
	}
	return counter;
}