long long int problem()
{
	long long int counter = 0;
	const int n = 28123;
	bool seive[n*2+1]={false};
	std::vector<int> abundants;

	for ( int i = 2; i <= n; i++ )
		if ( sumOf(divisorsOf(i)) > i )
			abundants.push_back(i);

	for (int i = 0; i < abundants.size(); i++ )
		for ( int j = 0; j < i; j++ )
			seive[abundants[i]+abundants[j]] = true;

	for ( int i = 1; i < n; i++ )
		if ( seive[i] == false )
			counter += i;

	return counter;
}