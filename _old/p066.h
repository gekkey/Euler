long long int problem()
{
	int max_depth = 100;
	long long int sum = 0;
	std::vector< long long int > convergents;
	std::array< mpz_t, 2 > tran;
	mpz_t nume;
	mpz_t deno;
	
	int D = 13;
	for ( int depth = 1; depth < max_depth; depth++ )
	{
		convergents = genContFrac( D, depth );
		
		mpz_init_set_ui(nume, 1);
		mpz_init_set_ui(deno, convergents.back());
		mpz_init(tran[0]); mpz_init(tran[1]);
		for ( int i = convergents.size()-2; i >= 0; i-=1 )
		{
			mpz_mul_ui(tran[0], deno, convergents[i]);
			mpz_add(nume, nume, tran[0]);
			mpz_set(tran[0], nume); mpz_set(tran[1], deno);
			mpz_set(nume, tran[1]); mpz_set(deno, tran[0]);
		}
		mpz_set(tran[0], nume); mpz_set(tran[1], deno);
		mpz_set(nume, tran[1]); mpz_set(deno, tran[0]);
	
	return 0;
}
