#include "poker.h"
long long int problem()
{
	long long int answer = 0;
	//std::vector<std::vector < std::string >> hand = read2DStrVector("p054.txt");
	//for ( unsigned int i = 0; i < hand.size(); i++ )
	//	if ( pokerWinner( hand[i] ) )
	//			answer ++;
	
	std::vector< std::string > hand{ "2D", "2C", "2S", "2C", "3C",/**/ "2C", "2S", "2C", "2S", "4C" };
	return pokerWinner( hand );
	
	return answer;
}
