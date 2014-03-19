long long int problem()
{
	int SIZE = 20;
	long long int test;
	bool passed;
	std::vector< std::vector<long long int> > triangle;
	triangle.resize( triangle.size()+1 );
	triangle[0].resize(triangle[0].size()+1);
	triangle[0][0] = 1;

	long long int i = 1;
	while ( triangle.size() < ( SIZE*2 ) + 1 )
	{
		triangle.resize( triangle.size()+1 );
		for ( long long int j = 0; j < triangle[i-1].size()+1 ; j++ )
		{
			triangle[i].resize(triangle[i].size()+1);
			try
			{
				test = triangle[i-1].at(j);
				test = triangle[i-1].at(j-1);
				passed = true;
			}
			catch (std::out_of_range outOfRange)
			{
				triangle[i][j] = 1;
				passed = false;
			}
			if ( passed == true )
			{
				triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
			}
		}
		i++;
	}
	return triangle[triangle.size()-1][(triangle[triangle.size()-1].size()-1)/2]; //what the hell
}