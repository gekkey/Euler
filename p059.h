//uppercase: 	65-90
//lowercase: 	97-122
//numerals:		48-57
//punctuation:	32-34,40-41,45-46,58-59

long long int problem()
{
	std::vector< long long int > key ( 3, 97 );
	std::vector< long long int > best_key;
	std::vector< long long int > code = read1DIntVector("p059.txt");
	std::string sentence;
	int sum;
	int add;
	int prob;
	int largest_prob = 0;
	while ( key[0] < 123 )
	{
		if ( key[2] == 123 )
		{
			key[2] = 97;
			key[1]++;
		}
		if ( key[1] == 123 )
		{
			key[1] = 97;
			key[0]++;
		}
		
		prob = 0; 
		for ( unsigned int i = 0; i < code.size(); i++ )
		{
			add = code[i] ^ key[i%3];
			if ( add > 126 or add < 32 ) break;
			else if ( add == 32 ) prob += 13; //space
			else if ( add == 101 or add == 69 ) prob += 12; // e
			else if ( add == 116 or add == 84 ) prob += 9; // t
			else if ( add == 97 or add == 65 ) prob += 8; // s
			else if ( add == 111 or add == 79 or add == 105 or add == 73 ) prob += 7; // o, i
			
		}
		if ( prob > largest_prob )
		{
			best_key = key;
			largest_prob = prob;
		}
		key[2]++;
	}
	sum = 0; sentence = "";
	for ( unsigned int i = 0; i < code.size(); i++ )
	{
		add = code[i] ^ best_key[i%3];
		sum += add;
		sentence += (char)add;
	}
	std::cout << sentence << std::endl;
	return sum;
}
