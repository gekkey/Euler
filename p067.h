long long int problem()
{
	std::ifstream instream;
	instream.open("p067.txt");
	std::string line;
	std::string number;
	int i = 0;
	std::vector<std::vector <long long int>> triangle;
	while ( !( instream.eof() ) )
	{
		triangle.resize(triangle.size()+1, std::vector<long long int>());
		std::getline( instream, line );
		std::stringstream linestream;
		linestream << line;
		while (linestream.good())
		{
			std::getline(linestream, number, ' ');
			triangle[i].resize(triangle[i].size()+1, convertStrToInt(number));
		}
		i++;
	}

	print2DVector(triangle);
	for ( unsigned int i = 0; i < triangle.size()-1; i++ )
	{
		triangle[i+1][0] += triangle[i][0];
		for ( unsigned int j = 0; j < triangle[i].size()-1; j++ )
		{
			if ( triangle[i][j] + triangle[i+1][j+1] > triangle[i][j+1] + triangle[i+1][j+1] )
			{
				triangle[i+1][j+1] += triangle[i][j];
			}
			else
			{
				triangle[i+1][j+1] += triangle[i][j+1];
			}
		}
		triangle[i+1][triangle[i+1].size()-1] += triangle[i][triangle[i].size()-1];
	}

	long long int largest = 0;
	for ( unsigned int i = 0; i < triangle[triangle.size()-1].size(); i++ )
	{
		if ( triangle[triangle.size()-1][i] > largest )
		{
			largest = triangle[triangle.size()-1][i];
		}
	}
	return largest;
}
