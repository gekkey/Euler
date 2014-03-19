long long int problem()
{
	int day = 0;
	int SUNDAY = 6;
	int year = 1900;
	int end;
	int counter = 0;
	int length_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	while ( year < 2001 )
	{
		if ( year % 4 == 0 && !( year % 100 == 0 || year % 400 != 0)  ){length_of_month[1] = 29;}
		else{length_of_month[1] = 28;}

		for ( int i = 0; i < 12; i++ )
		{
			std::cout << day << std::endl;
			if ( day == SUNDAY && year > 1900 )
			{
				counter += 1;
			}
			day += ( length_of_month[i] % 7 );
			if ( day > 6 ){ day -= 7; }
		}
		year += 1;
	}
	return counter;
}