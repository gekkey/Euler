long long int problem()
{
	int largest = 0;
	int current;
	mpz_t c; mpz_init(c);
	std::vector< long long int > d;
	
	for ( int a = 0; a < 100; a++ )
	{
		for ( int b = 0; b < 100; b++ )
		{
			current = 0;
			mpz_ui_pow_ui(c, a, b);
			d = splitMpz_t( c );
			for ( unsigned int i = 0; i < d.size(); i++ )
				current += d[i];
			if (current > largest)
				largest = current;
		}
	}
	return largest;
}
