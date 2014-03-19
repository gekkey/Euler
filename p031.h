long long int problem()
{
	int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200 };
	int goal = 200;
	int ways[201] = {0};
	ways[0] = 1;
	std::string s;
	
	for ( unsigned int i = 0; i < 8; i++)
	{
		for ( int j = coins[i]; j <= goal; j++ )
		{
			ways[j] += ways[j - coins[i]];
		}
		
		//
		std::cin.ignore();
		system("CLS");
		for ( int x = 0; x < 201; x++ )
		{
			if ( x < 10 ) s = "00";
			else if ( x < 100 ) s = "0";
			else s = "";
			std::cout << s << x << ": " << ways[x] << std::endl;
		}
		//
	}
	
	return ways[200];
}
