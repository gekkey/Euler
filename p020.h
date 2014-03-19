long long int problem()
{
	FILE * file = fopen("p020.txt", "w");
	std::ifstream convert;
	std::string str;
	long long int x = 0;

	mpz_t n;
	mpz_init(n);
	mpz_set_ui(n, 100);

	for ( int i = 100 - 1; i > 0; i -= 1 )
	{
		mpz_mul_ui(n, n, i);
	}

	mpz_out_str(file, 10, n);
	fclose(file);

	convert.open("p020.txt");
	std::getline(convert, str);

	for ( int i = 0; i < str.length(); i++ )
	{
		x += convertStr(convertChar(str[i]));
	}

	return x;
}