long long int problem()
{
	std::array<  std::array< int, 10000	>, 9 > P;
	std::vector< std::array< int, 6		> > cycs;
	std::array<  int, 9 > n;
	long long int sum = 0;
	
	// Get all the heavy math out of the way
	for ( int i = 19; i < 141; i++ )
	{
		n[3] = i*(i+1)/2;
		n[4] = i*i;
		n[5] = i*(3*i-1)/2;
		n[6] = i*(2*i-1);
		n[7] = i*(5*i-3)/2;
		n[8] = i*(3*i-2);
		for ( int j = 3; j <= 8; j++ )
		{
			if ( n[j] > 1000 && n[j] < 10000 )
			{
				P[j][n[j]] = true;
				P[0][n[j]] = true;
			}
		}
	}
	// A recursive solution would be much more efficient here, but
	// recursion hurts my brain. I will not be using recursion here.
	
	// Make a list of all possible cycles
	int i[6];
	for ( i[0] = 1000; i[0] < 10000; i[0]++ ) if ( P[0][i[0]] )
	{
		n[0] = ((i[0]/10)%10)*10 + i[0]%10;
		if ( n[0] < 10 ) continue;
		for ( i[1] = n[0]*100; i[1] < (n[0]+1)*100; i[1]++ ) if ( P[0][i[1]] )
		{
			n[1] = ((i[1]/10)%10)*10 + i[1]%10;
			if ( n[1] < 10 ) continue;
			for ( i[2] = n[1]*100; i[2] < (n[1]+1)*100; i[2]++ ) if ( P[0][i[2]] )
			{
				n[2] = ((i[2]/10)%10)*10 + i[2]%10;
				if ( n[2] < 10 ) continue;
				for ( i[3] = n[2]*100; i[3] < (n[2]+1)*100; i[3]++ ) if ( P[0][i[3]] )
				{
					n[3] = ((i[3]/10)%10)*10 + i[3]%10;
					if ( n[3] < 10 ) continue;
					for ( i[4] = n[3]*100; i[4] < (n[3]+1)*100; i[4]++ ) if ( P[0][i[4]] )
					{
						n[4] = ((i[4]/10)%10)*10 + i[4]%10;
						if ( n[4] < 10 ) continue;
						for ( i[5] = n[4]*100; i[5] < (n[4]+1)*100; i[5]++ ) if ( P[0][i[5]] )
						{
							n[5] = ((i[5]/10)%10)*10 + i[5]%10;
							if ( n[5] < 10 ) continue;
							n[6] = ((i[0]/1000)%10)*10 + (i[0]/100)%10;
							if ( n[5] == n[6] )
							{
								cycs.resize(cycs.size()+1);
								cycs.back() = {i[0], i[1], i[2], i[3], i[4], i[5]};
							}
						}
					}
				}
			}
		}
	}
	
	// For each cycle
	// find the formulas solved by only one number
	// remove that number
	// repeat
	// when every number is removed, you have the right cycle
	// when there are no formulas with any solution, try the next one
	std::vector< std::array< std::vector< int >, 9 > > sols; // sols[cycle][formula][solutions]
	sols.resize(cycs.size() );
	std::array< int, 6 > prev;
	bool broke;
	bool escape = true;
	
	for ( unsigned int j = 0; j < cycs.size(); j++ )
	{
		prev = cycs[j];
		while ( true )
		{
			sols[j].fill(std::vector< int >());
			for ( int k = 3; k <= 8; k++ )
				for ( int m = 0; m < 6; m++ )
					if ( P[k][cycs[j][m]] )
						sols[j][k].push_back(m);
			
			broke = false;
			for ( int k = 3; k <= 8; k++ ) if ( sols[j][k].size() == 1 )
			{
				cycs[j][sols[j][k][0]] = 0;
				broke = true;
				break;
			}
			
			if ( !cycs[j][0] && !cycs[j][1] && !cycs[j][2] && !cycs[j][3] && !cycs[j][4] && !cycs[j][5] )
				escape = broke = false;
				
			if ( !broke )
				break;
		}
		if ( !escape )
			break;
	}
	for ( int j = 0; j < 6; j++ )
		sum += prev[j];
	return sum;
}
