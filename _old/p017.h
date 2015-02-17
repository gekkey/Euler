long long int problem()
{
	bool teens = false;
	std::string str;
	long long int count = 0;
	std::string numbers[3][10] = {
		{"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"},
		{"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"},
		{"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"}};
	
	for ( int i = 1; i <= 1000; i++ )
	{
		std::string j = flip(convertInt(i));
		str = "";
		for (int k = j.length()-1; k >= 0; k-=1)
		{
			int x = convertStr(convertChar(j[k]));
			if ( k == 3 && x != 0 ){str += numbers[1][x] + "thousand";}
			else if ( k == 2 && x != 0 )
			{
				str += numbers[1][x] + "hundred";
				if ( ( convertStr(convertChar(j[1])) != 0 ) || ( convertStr(convertChar(j[0])) != 0 ) )
				{
					str += "and";
				}
			}
			else if ( k == 1 && x == 1 ){teens = true;}
			else if ( k == 1 && x != 1){str += numbers[0][x];}
			else if ( k == 0 && teens == false){str += numbers[1][x];}
			else if ( k == 0 && teens == true){str += numbers[2][x];}
		}
		teens = false;
		count += str.length();
		std::cout << i << ": " << str << " - " << str.length() << std::endl;
	}
	
	return count;
}