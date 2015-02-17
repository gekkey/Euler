long long int problem()
{
	std::vector< long long int > digits { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector< std::vector< long long int > > possible = permutation( digits );
	
	std::vector< long long int > products;
	std::vector< long long int > v_x;
	std::vector< long long int > v_y;
	std::vector< long long int > v_z;
	long long int x;
	long long int y;
	long long int z;
	
	for ( unsigned int i = 0; i < possible.size(); i++ )
	{
		for ( unsigned int j = 2; j < possible[i].size(); j++ )
		{
			for ( unsigned int k = 1; k < j; k++ )
			{
				v_z.assign(possible[i].begin()+j, possible[i].end());
				v_x.assign(possible[i].begin(), possible[i].begin()+j);
				v_y.assign(v_x.begin()+k, v_x.end());
				v_x.assign(v_x.begin(), v_x.begin()+k);
				
				x = joinIntVector(v_x);
				y = joinIntVector(v_y);
				z = joinIntVector(v_z);
				
				if ( x * y == z )
					products.push_back(z);
			}
		}
	}
	
	long long int sum = 0;
	std::vector< long long int > unique;
	bool found;
	
	for ( unsigned int i = 0; i < products.size(); i++ )
	{
		found = false;
		for ( unsigned int j = 0; j < unique.size(); j++ )
		{
			if ( products[i] == unique[j] )
			{
				found = true;
				break;
			}
		}
		if ( found == false )
		{
			unique.push_back(products[i]);
			sum += products[i];
		}
	}
	
	
	return sum;
}
