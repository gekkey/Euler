long long int problem()
{
	std::vector< long long int > current_vector;
	long long int product = 1;
	
	long long int current_number = 1;
	long long int current_digit = 0;
	long long int target_digit = 1;
	while ( current_digit <= 1000000 )
	{
		current_vector = splitInt( current_number );
		for ( unsigned int i = 0; i < current_vector.size(); i++ )
		{
			current_digit++;
			if ( current_digit == target_digit )
			{
				product *= current_vector[i];
				std::cout << current_vector[i] << std::endl;
				target_digit *= 10;
			}
		}
		
		current_number++;
	}
	return product;
}
