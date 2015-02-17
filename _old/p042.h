long long int problem()
{
	std::cout << "test" << std::endl;
	//GENERATE TRIANGLE NUMBERS
	double t [200] = {};
	for ( double i = 1; i <= 200; i++ )
	{
		t[(int)i] = i * 0.5 * ( i + 1 );
	}
	
	//OPEN FILE
	std::ifstream instream;
	instream.open("p042.txt");
	std::string word;
	
	long long int sum = 0;
	while ( !( instream.eof() ) )
	{
		std::getline( instream, word, ',' );
		std::cout << word << std::endl;
		int y = 0;
		bool triangle;
		for ( unsigned int i = 0; i < word.size(); i++ )
			y += valueOfLetter(word[i]);
		
		triangle = false;
		for ( int i = 0; i < 200; i++ )
		{
			if ( y == t[i] )
			{
				triangle = true;
				break;
			}
		}
		if ( triangle == true )
			sum += 1;
	}
	return sum;
}
