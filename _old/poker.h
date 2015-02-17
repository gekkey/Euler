bool royalFlush( 	std::vector< std::string > hand, 
					std::unordered_map< char, int > value, 
					int f )
{
	char suit = hand[0+f][1];
	bool found;
	
	for ( int i = 0; i < 5; i++ )
	{
		found = false;
		for ( int j = 0; j < 5; j++ )
		{
			if ( value[hand[j+f][0]] == 10+i )
			{
				found = true;
				break;
			}
		}
		if ( !found )
			return 0;
		if ( hand[i+f][1] != suit )
			return 0;
	}
	return 1;
}
bool straightFlush(	std::vector< std::string > hand, 
					std::unordered_map< char, int > value, 
					int f )
{
	char suit = hand[0+f][1];
	bool found;
	int lowest = 15;
	// find the lowest
	for ( int i = 0; i < 5; i++ )
		if ( value[hand[i+f][0]] < lowest )
			lowest = value[hand[i+f][0]];
	// make sure there are four increments of it
	for ( int i = 0; i < 5; i++ )
	{
		found = false;
		for ( int j = 0; j < 5; j++ )
		{
			if ( value[hand[j+f][0]] == lowest+i )
			{
				found = true;
				break;
			}
		}
		if ( !found )
			return 0;
		if ( hand[i+f][1] != suit )
			return 0;
	}
	return 1;
}
int xOfAKind(	std::vector< std::string > hand, 
				std::unordered_map< char, int > value, 
				int f )
{
	int pairs = 0;
	std::vector< int > count( 15, 0);
	for ( int i = 0; i < 5; i++ )
		count[value[hand[i+f][0]]] ++;
		
	for ( unsigned int i = 0; i < count.size(); i++ )
	{
		if ( count[i] == 4 )
			return 5;
		if ( count[i] == 3 )
			pairs += 3;
		if ( count[i] == 2 )
			pairs += 1;
	}
	return pairs;
}	
bool flush(	std::vector< std::string > hand, 
			std::unordered_map< char, int > value, 
			int f )
{
	char suit = hand[0+f][1];
	for ( int i = 0; i < 5; i++ )
		if ( hand[i+f][1] != suit )
			return 0;
	return 1;
}
bool straight(	std::vector< std::string > hand, 
				std::unordered_map< char, int > value, 
				int f )
{
	bool found;
	int lowest = 15;
	// find the lowest
	for ( int i = 0; i < 5; i++ )
		if ( value[hand[i+f][0]] < lowest )
			lowest = value[hand[i+f][0]];
	// make sure there are four increments of it
	for ( int i = 0; i < 5; i++ )
	{
		found = false;
		for ( int j = 0; j < 5; j++ )
		{
			if ( value[hand[j+f][0]] == lowest+i )
			{
				found = true;
				break;
			}
		}
		if ( !found )
			return 0;
	}
	return 1;
}
int highest(	std::vector< std::string > hand, 
				std::unordered_map< char, int > value, 
				int f )
{
	int x = 0;
	for ( int i = 0; i < 5; i++ )
		if ( value[hand[i+f][0]] > x )
			x = value[hand[i+f][0]];
	return x;
}

bool pokerWinner( std::vector< std::string > hand )
{
	std::unordered_map< char, int > value;
	int pairs;
	int player[2] = { 0, 0 };
	int C = 15*3;
	
	value['2'] = 2; value['3'] = 3; value['4'] = 4; value['5'] = 5; 
	value['6'] = 6; value['7'] = 7; value['8'] = 8; value['9'] = 9;
	value['T'] = 10;value['J'] = 11;value['Q'] = 12;value['K'] = 13;
	value['A'] = 14;
	
	for ( int f = 0; f < 2; f ++ )
	{
		if ( royalFlush( hand, value, f*5 ) )
		{
			player[f] = 10*C;
			continue;
		}
		if ( straightFlush( hand, value, f*5 ) )
		{
			player[f] = 9*C;
			continue;
		}
		pairs = xOfAKind( hand, value, f*5 );
		if ( pairs == 5 )
		{
			player[f] = 8*C;
			continue;
		}
		if ( pairs == 4 )
		{
			player[f] = 7*C;
			continue;
		}
		if ( flush( hand, value, f*5 ) )
		{
			player[f] = 6*C;
			continue;
		}
		if ( straight( hand, value, f*5 ) )
		{
			player[f] = 5*C;
			continue;
		}
		if ( pairs == 3 )
		{
			player[f] = 4*C;
			continue;
		}
		if ( pairs == 2 )
		{
			player[f] = 3*C;
			continue;
		}
		if ( pairs == 1 )
		{
			player[f] = 2*C;
			continue;
		}
		player[f] = highest( hand, value, f*5 );
	}
	if ( player[0] == player[1] )
		;//resolveTie( hand, value, player[0] )
	//std::cout << "player 1: " << player[0] << std::endl;
	//std::cout << "player 2: " << player[1] << std::endl;
	return (player[0] < player[1]);
}
