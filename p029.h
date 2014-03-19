long long int problem()
{
	std::vector<mpz_class> total;
	std::vector<mpz_class> newline;

	for ( mpz_class a = 2; a <= 100; a++ )
	{
		for ( mpz_class b = 2; b <= 100; b++ )
		{
			
			newline.push_back( exponentOfMpz_class( a, b ) );
		}
		total = removeDuplicatesFromMpz_classVectors(total, newline);
		newline.clear();
	}
	return total.size();
}
