long long int problem()
{
	std::vector<long long int> possible {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<std::vector<long long int> > current = permutation(possible);
	
	/*std::vector<long long int> erase;
	for ( int j = 0; j < current.size(); j++ )
		if ( current[j].size() < possible.size() )
			erase.push_back(j);
	for ( int i = 0; i < erase.size(); i++ )
	{
		current.erase(current.begin()+erase[i]-i);
	}*/

	print1DVector(current[999999]);
	
	return 0;
}
