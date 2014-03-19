long long int problem()
{
	int i = 1;
	mpz_t n; mpz_init_set_ui(n, 3);
	mpz_t d; mpz_init_set_ui(d, 2);
	mpz_t add; mpz_init(add);
	
	long long int answer = 0;
	
	while ( i < 1000 )
	{
		if (digitsInMpz(n) > digitsInMpz(d))
			answer++;
		
		mpz_mul_ui(add, d, 2);
		mpz_add(n, n, add);
		mpz_sub(d, n, d);
		i++;
	 }
	 return answer;
 }
