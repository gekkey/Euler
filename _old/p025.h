long long int problem()
{
	mpz_t a; 
	mpz_t b;
	mpz_init_set_ui(a, 1);
	mpz_init_set_ui(b, 1);

	FILE * file = fopen("p025.txt", "w");
	std::ifstream convert;
	std::string str;

	mpz_out_str(file, 10, a);
	convert.open("p025.txt");
	std::getline(convert, str);

	while ( str.length() < 4 )
	{
		mpz_out_str(file, 10, a);
		convert.open("p025.txt");
		std::getline(convert, str);
		std::cout << str << std::endl;
		mpz_add(b, a, b); mpz_sub(a, b, a);

	}

	return 0;
}