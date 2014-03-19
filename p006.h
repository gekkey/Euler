long long int problem()
{
	long long int sumofsquares = 0;
	long long int squareofsums = 0;
	for (int i = 1; i <= 100; i++)
	{
		sumofsquares += i*i;
		squareofsums += i;
	}
	squareofsums = squareofsums*squareofsums;
	return squareofsums-sumofsquares;
}