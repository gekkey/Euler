long long int problem()
{
	std::vector< bool > prime = sieve( 987654322 );
	std::cout << "sieve generated" << std::endl;
	
	for ( long long int i = 987654321; i > 0; i -= 2 )
		if ( ( prime[i] ) && ( isPandigital( i ) ) )
				return i;
	return 0;
}
