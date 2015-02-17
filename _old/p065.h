long long int problem()
{
	int depth = 100;
	long long int sum = 0;
	std::vector< int > convergents;
	std::vector< long long int > split;
	std::array< mpz_t, 2 > tran;
	mpz_t nume;
	mpz_t deno;
	
	//generate the convergents
	convergents.push_back(2);
	for ( int i = 1; (i*3)+1 <= depth; i++ )
	{
		convergents.push_back(1);
		convergents.push_back(i*2);
		convergents.push_back(1);
	}
	
	//reduce it, starting at the deepest and working upwards
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
	
	split = splitMpz_t( nume );
	for ( unsigned int i = 0; i < split.size(); i++ )
		sum += split[i];
	
	return sum;
}
		
