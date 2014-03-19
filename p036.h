long long int problem()
{
	std::vector< bool > binary;
	long long int decimal = 1000000;
	long long int sum = 0;
	
	while ( decimal )
	{
		binary = convertIntToBoolVector( decimal );
		if ( ( decimal == flipInt( decimal ) ) && ( binary == flipBoolVector( binary ) ) )
		{
			sum += decimal;
			std::cout << decimal << ", ";
			print1DBoolVector( binary );
		}
		decimal -= 1;
	}
		
	return sum;
}
