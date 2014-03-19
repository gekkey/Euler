long long int problem()
{
	std::ifstream instream;
	instream.open("p011.txt");
	std::string convert;
	std::string instring[20];
	long long int grid[20][20];
	int i = 0;
	while ( !( instream.eof() ) )
	{
		instring[i] = "";
		std::getline( instream, convert );
		instring[i] += convert;
		i++;
	}
	for ( int i = 0; i < 20; i++ )
	{
		for ( int j = 0; j < instring[i].length() - 1; j += 3 )
		{
			convert = "";
			convert += instring[i][j];
			convert += instring[i][j+1];
			grid[i][j/3] = convertStr(convert);
		}
	}
	int current = 0;
	int largest = 0;
	for ( int i = 0; i < 20; i ++ )
	{
		for ( int j = 0; j < 20; j++ )
		{
			try
			{
				current = grid[i+0][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
				if ( current > largest ){ largest = current; std::cout << largest << std::endl; }
				current = grid[i+0][j+0] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
				if ( current > largest ){ largest = current; std::cout << largest << std::endl; }
				current = grid[i+0][j+0] * grid[i+1][j-1] * grid[i+2][j-2] * grid[i+3][j-3];
				if ( current > largest ){ largest = current; std::cout << largest << std::endl; }
				current = grid[i-0][j] * grid[i-1][j] * grid[i-2][j] * grid[i-3][j];
				if ( current > largest ){ largest = current; std::cout << largest << std::endl; }
				current = grid[i-0][j-0] * grid[i-1][j-1] * grid[i-2][j-2] * grid[i-3][j-3];
				if ( current > largest ){ largest = current; std::cout << largest << std::endl; }
				current = grid[i-0][j+0] * grid[i-1][j+1] * grid[i-2][j+2] * grid[i-3][j+3];
				if ( current > largest ){ largest = current; std::cout << largest << std::endl; }
				current = grid[i][j-0] * grid[i][j-1] * grid[i][j-2] * grid[i][j-3];
				if ( current > largest ){ largest = current; std::cout << largest << std::endl; }
				current = grid[i][j+0] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
				if ( current > largest ){ largest = current; std::cout << largest << std::endl; }
			}
			catch ( int e )
			{
				;
			}
		}
	}
	return largest;
}