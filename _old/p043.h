long long int problem()
{
	std::vector< long long int > divisors { 2, 3, 5, 7, 11, 13, 17 };
	std::vector< long long int > possible { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector< std::vector< long long int > > temp = permutation( possible );
	std::vector< long long int > permutations;
	for ( unsigned int i = 0; i < temp.size(); i++ ) if ( isPandigital( joinIntVector( temp[i] ) ) ) permutations.push_back( joinIntVector( temp[i] ) );
	std::cout << "PERMUTATIONS GENERATED" << std::endl;
	
	long long int sum = 0;
	bool divisible;
	for ( unsigned int i = 0; i < permutations.size(); i++ )
	{
		divisible = true;
		for ( unsigned int j = 1; j < divisors.size()+1; j++ )
		{
			if ( !( joinIntVector( splitInt( permutations[i], j, j+2 ) ) % divisors[j-1] == 0 ) )
			{
				divisible = false;
				break;
			}
		}
		if ( divisible )
			sum += permutations[i];
	}
	
	return sum;
}
