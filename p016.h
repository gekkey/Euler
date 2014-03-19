long long int problem()
{
	//define variables
	FILE * file = fopen("p016.txt", "w");
	std::ifstream convert;
	std::string str;
	mpz_t n;
	long long int x = 0;

	//get 2^1000 and write it to file
	mpz_init(n);
	mpz_set_ui(n, 2);
	mpz_pow_ui(n, n, 1000);
	mpz_out_str(file, 10, n);
	fclose(file);

	//read that file into a string
	convert.open("p016.txt");
	std::getline(convert, str);

	//iterate through that string and add them up
	for ( int i = 0; i < str.length(); i++ )
	{
		std::cout << x << " + " << str.at(i) << " = ";
		std::string convert(1, str[i]);
		x += atoi(convert.c_str());
		std::cout << x << std::endl;
	}
	return x;
}