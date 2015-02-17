long long int problem()
{
	long long int counter = 0;
	int b;
	for ( int a = 1; a < 10000; a+=1 )
	{
		b = sumOf(divisorsOf(a));
		if ( sumOf(divisorsOf(b)) == a && a != b )
		{
			std::cout << a << ", " << b << std::endl;
			counter += a + b;
			a = b + 1;
		}
	}
	return counter;
}