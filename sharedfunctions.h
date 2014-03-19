// FACTORS / DIVISORS
std::vector<long long int> factorsOf(long long int in)
{
	std::vector<long long int> out;
	long long int i = 1;
	long double limit = in;
	while (i <= sqrt(limit))
	{
		if ( in % i == 0 )
		{
			out.resize(out.size()+1, i);
			out.resize(out.size()+1, in / i );
		}
		i++;
	}

	return out;
}
std::vector<long long int> divisorsOf(long long int in)
{
	std::vector<long long int> out(1, 1);
	long long int i = 2;
	long double limit = in;
	while (i <= sqrt((double)limit))
	{
		if ( in % i == 0 )
		{
			out.resize(out.size()+1, i);
			out.resize(out.size()+1, in / i);
		}
		i++;
	}

	return out;
}
long long int sumOfDivisorsOf(long long int in)
{
	long long int counter = 0;
	long long int i = 2;
	long double limit = in;
	while (i <= sqrt((double)limit))
	{
		if ( in % i == 0 )
		{
			counter += i;
			counter += in / i;
		}
		i++;
	}

	return counter+1;
}
// END FACTORS / DIVISORS

// CONVERT STRING
std::string convertIntToString(int in)
{
	std::stringstream convert;
	convert << in;
	return convert.str().c_str();
}
std::string convertDoubleToString(double in)
{
	std::stringstream convert;
	convert << in;
	return convert.str().c_str();
}
std::string convertCharToString(char in)
{
	std::stringstream convert;
	convert << in;
	return convert.str().c_str();
}
long long int convertStrToInt(std::string in)
{
	int convert;
	std::istringstream( in ) >> convert;
	return convert;
}
std::string flipString(std::string in)
{
	std::string out;

	for ( int i = in.length() - 1; i >= 0;  i -= 1 )
	{
		out += in[i];
	}
	return out;
}
// END CONVERT STRING

// PRIME NUMBERS
bool isPrime(long long int n)
{
	if ( n <= 1 )
	{
		return false;
	}
	long long int i = 2;
	while ( i*i <= n )
	{
		if ( n % i == 0 )
		{
			return false;
		}
		i++;
	}
	return true;
}

std::vector< bool > sieve(int n)
{
	std::vector<bool> sieve(n, true);
	for ( int i = 2; i <= (int)sqrt((double)n); i++ )
	{
		if ( sieve[i] == true )
		{
			for ( long long int j = i*i; j < n; j += i )
			{
				sieve[j] = false;
			}
		}
	}
	sieve[0] = false; 
	sieve[1] = false;
	return sieve;
}
// END PRIME NUMBERS

// PRINT VECTOR
void print1DIntVector(std::vector<long long int> in)
{
	std::cout << in[0];
	for ( unsigned int i = 1; i < in.size(); i++ )
	{
		std::cout << ", " << in[i];
	}
	std::cout << std::endl;
}
void print2DIntVector(std::vector<std::vector<long long int> > in)
{
	for ( unsigned int i = 0; i < in.size(); i++ )
	{
		//std::cout << i << ": ";
		std::cout << in[i][0];
		for ( unsigned int j = 1; j < in[i].size(); j++ )
		{
			std::cout << ", " << in[i][j];
		}
		std::cout << std::endl;
	}
}
void print1DStrVector(std::vector< std::string > in)
{
	std::cout << in[0];
	for ( unsigned int i = 1; i < in.size(); i++ )
	{
		std::cout  << ", " << in[i];
	}
	std::cout << std::endl;
}
void print2DStrVector(std::vector< std::vector< std::string > > in)
{
	for ( unsigned int i = 0; i < in.size(); i++ )
	{
		//std::cout << i << ": ";
		std::cout << in[i][0];
		for ( unsigned int j = 1; j < in[i].size(); j++ )
		{
			std::cout << ", " << in[i][j];
		}
		std::cout << std::endl;
	}
}
void print1DMpz_classVector(std::vector<mpz_class> in)
{
	gmp_printf( "%Zd", in[0].get_mpz_t() );
	for ( unsigned int i = 1; i < in.size(); i++ )
	{
		gmp_printf( ", %Zd", in[i].get_mpz_t() );
	}
	std::cout << std::endl;
}
void print2DMpz_classVector(std::vector<std::vector<mpz_class> > in)
{
	for ( unsigned int i = 0; i < in.size(); i++ )
	{
		gmp_printf( "%Zd: ", in[i][0].get_mpz_t() );
		for ( unsigned int j = 1; j < in[i].size(); j++ )
		{
			gmp_printf( ", %Zd", in[i][j].get_mpz_t() );
		}
		std::cout << std::endl;
	}
}
void print1DBinaryVector(std::vector< bool > in)
{
	std::cout  << in[0];
	for ( unsigned int i = 1; i < in.size(); i++ )
	{
		std::cout << in[i];
	}
	std::cout << std::endl;
}
void print2DBinaryVector(std::vector< std::vector < bool > > in)
{
	for ( unsigned int i = 0; i < in.size(); i++ )
	{
		std::cout << in[i][0];
		for ( unsigned int j = 1; j < in[i].size(); j++ )
		{
			std::cout << in[i][j];
		}
		std::cout << std::endl;
	}
}
// END PRINT VECTOR

// READ VECTOR FROM TEXT FILE
std::vector< std::vector< std::string > > read2DStrVector( std::string filename )
{
	std::ifstream instream;
	instream.open(filename);
	std::string line;
	std::string card;
	std::vector<std::vector < std::string >> hand;
	while ( !( instream.eof() ) )
	{
		hand.resize(hand.size()+1, std::vector< std::string >());
		std::getline( instream, line );
		std::stringstream linestream;
		linestream << line;
		while (linestream.good())
		{
			std::getline(linestream, card, ' ');
			hand[hand.size()-1].push_back(card);
		}
	}
	instream.close();
	hand.assign(hand.begin(), hand.end()-1);
	return hand;
}
std::vector< std::string > getWordList()
{
	std::ifstream instream("words.txt");
	std::vector< std::string > words;
	std::string line;
	while ( std::getline( instream, line ) )
	{
		words.push_back( line );
	}
	instream.close();
	for( int i = 0; i <= 1000; i++ )
		words.push_back( std::to_string(i) );
	return words;
}
std::vector< long long int > read1DIntVector( std::string filename )
{
	std::ifstream instream(filename);
	std::string line;
	std::vector< long long int > list;
	while ( std::getline( instream, line, ',' ) )
	{
		int number;
		std::istringstream linestream(line);
		while (linestream >> number)
		{
			list.push_back(number);
		}
	}
	instream.close();
	return list;
}
// END READ VECTOR FROM TEXT FILE

long long int sumOfIntVector(std::vector<long long int> in)
{
	long long int counter = 0;
	for ( unsigned int i = 0; i < in.size(); i++ )
	{
		counter += in[i];
	}
	return counter;
}

double valueOfStr( std::string in )
{
	std::unordered_map<std::string, int> alphabet;
	std::string letters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
	for ( int i = 0; i < 26; i++ ){ alphabet[letters[i]] = i + 1; }

	double x = 0;
	double ten = 100;
	for ( unsigned int i = 0; i < in.length(); i++ )
	{
		double y = i;
		x += alphabet[convertCharToString(in[i])]/pow(ten, y);
	}
	return x;
}

long long int valueOfLetter( char in )
{
	int NUMBER_OF_LETTERS = 26;
	char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for ( int i = 0; i <= NUMBER_OF_LETTERS; i++)
	{
		if ( letters[i] == in )
				return i + 1;
	}
	return 0;
}

std::vector<std::string> alphabetizedVector( std::vector<std::string> in )
{
	std::vector<std::string> convert(1, "ZZZ");
	std::unordered_map<std::string, double> names;
	names["ZZZ"] = valueOfStr("ZZZ");

	for ( unsigned int i = 0; i < in.size(); i++ )
	{
		names[in[i]] = valueOfStr(in[i]);
	}
	std::cout << "Optimized list" << std::endl;
	
	for ( unsigned int i = 0; i < in.size(); i++ )
	{
		for ( unsigned int j = 0; j < convert.size(); j++ )
		{
			if ( names[in[i]] < names[convert[j]] )
			{
				convert.insert(convert.begin()+j, in[i]);
				break;
			}
		}
	}
	convert.erase(convert.end()-1);
	return convert;
}

std::vector<long long int> appendIntVectors(std::vector<long long int> a, std::vector<long long int> b)
{
	a.insert(a.end(), b.begin(), b.end());
	return a;
}
std::vector< bool > appendBoolVectors(std::vector< bool > a, std::vector< bool > b)
{
	a.insert(a.end(), b.begin(), b.end());
	return a;
}

std::vector<mpz_class> appendMpz_classVectors(std::vector<mpz_class> a, std::vector<mpz_class> b)
{
	a.insert(a.end(), b.begin(), b.end());
	return a;
}

std::vector<long long int> removeDuplicatesFromIntVectors(std::vector<long long int> a, std::vector<long long int> b)
{
	std::vector<long long int> out;
	std::vector<long long int> both = appendIntVectors(a, b);
	bool found;
	
	for ( unsigned int i = 0; i < both.size(); i++ )
	{
		found = false;
		for ( unsigned int j = 0; j < out.size(); j++ )
		{
			if ( both[i] == out[j] )
			{
				found = true;
				break;
			}
		}
		if ( !found )
		{
			out.push_back(both[i]);
		}
	}
	return out;
}

std::vector<mpz_class> removeDuplicatesFromMpz_classVectors(std::vector<mpz_class> a, std::vector<mpz_class> b)
{
	std::vector<mpz_class> out;
	std::vector<mpz_class> both = appendMpz_classVectors(a, b);
	bool found;
	
	for ( unsigned int i = 0; i < both.size(); i++ )
	{
		found = false;
		for ( unsigned int j = 0; j < out.size(); j++ )
		{
			if ( both[i] == out[j] )
			{
				found = true;
				break;
			}
		}
		if ( !found )
		{
			out.push_back(both[i]);
		}
	}
	return out;
}

int exponentOfInt( int base, int power)
{
	if ( power == 0 )
		return 1;
	int x = base;
	for ( int i = 1; i < power; i++ )
	{
		base = base * x;
	}
	return base;
}

mpz_class exponentOfMpz_class( mpz_class a, mpz_class b )
{
	mpz_class x = a;
	for ( int i = 1; i < b; i++ )
	{
		x = x*a;
	}
	return x;
}

std::vector<std::vector<long long int> > permutation(std::vector<long long int> possible)
{
	std::vector<std::vector<long long int> > out;
	std::vector<std::vector<long long int> > temp;
	std::vector<long long int> new_possible;

	for ( unsigned int i = 0; i < possible.size(); i++ )
	{
		new_possible = possible;
		new_possible.erase(new_possible.begin()+i);
		
		if ( new_possible.size() > 0 )
			temp = permutation(new_possible);
		else
			out.push_back(std::vector<long long int> (1, possible[i]));
			
		new_possible.clear();
		
		for ( unsigned int j = 0; j < temp.size(); j++ )
		{
			if ( temp[j].size() + 1 == possible.size() )
			{
				out.push_back(std::vector<long long int> (1, possible[i]));
				out[out.size()-1] = appendIntVectors(out[out.size()-1], temp[j]);
			}
		}
		temp.clear();
	}
	return out;
}

std::vector< std::vector< bool > > boolPermutation(int n)
{
	n --;
	std::vector<std::vector< bool > > out;
	std::vector<std::vector< bool > > temp;
	if ( n )
		temp = boolPermutation(n);
	else
	{
		out.push_back( std::vector< bool > (1, 0) );
		out.push_back( std::vector< bool > (1, 1) );
		return out;
	}
	
	for ( int b = 0; b <= 1; b++ )
	{
		for ( unsigned int i = 0; i < temp.size(); i++ )
		{
			out.push_back( appendBoolVectors(std::vector< bool > (1, b), temp[i]) );
		}
	}
	return out;
}

std::vector< long long int > flipIntVector( std::vector< long long int > in )
{
	std::vector< long long int > out;
	for ( unsigned int i = 0; i < in.size(); i++ )
		out.insert(out.begin(), in[i]);
		
	return out;
}

long long int joinIntVector( std::vector< long long int > in )
{
	long long int out = 0;
	for ( unsigned int i = 0; i < in.size(); i++ )
	{
		out = ( out * 10 ) + in[i];
	}
	return out;
}

int digitsInInt( long long int x )
{
	int i = 0;
	while ( x )
	{
		x = x/10;
		i++;
	}
	return i;
}
int digitsInMpz( mpz_t n )
{
	mpz_t x; mpz_init_set(x, n);
	int i = 0;
	while ( mpz_get_ui(x) )
	{
		mpz_cdiv_q_ui(x, x, 10 );
		i++;
		if ( mpz_get_ui(x) <= 10 )
		{
			i++;
			break;
		}
	}
	return i;
}
int digit( long long int x, long long int index )
{
	for ( int i = 0; i < (digitsInInt(x)-index-1); i++ )
	{
		x = x / 10;
		index -=1;
	}
	return x % 10;
}
	
long long int joinInts( long long int x, long long int y )
{
	for ( int i = 0; i < digitsInInt(y); i++ )
		x = x * 10;
	x += y;
	return x;
}

std::vector< long long int > splitInt(long long int x)
{
	std::vector< long long int > out;
	
	while ( x )
	{
		out.insert(out.begin(), x % 10);
		x = x / 10;
	}
	return out;
}
std::vector< long long int > splitInt(long long int x, int location)
{
	std::vector< long long int > out;
	
	while ( x )
	{
		out.insert(out.begin(), x % 10);
		x = x / 10;
	}
	out.assign(out.begin()+location, out.begin()+location+1);
	return out;
}
std::vector< long long int > splitInt(long long int x, int begin, int end)
{
	std::vector< long long int > out;
	
	while ( x )
	{
		out.insert(out.begin(), x % 10);
		x = x / 10;
	}
	out.assign(out.begin()+begin, out.begin()+end+1);
	return out;
}
std::vector< long long int > splitMpz_t( mpz_t x )
{
	std::vector< long long int > out;
	mpz_t y; mpz_init(y);
	while ( mpz_get_ui( x ) )
	{
		mpz_mod_ui(y, x, 10);
		out.insert(out.begin(), mpz_get_ui(y));
		mpz_tdiv_q_ui(x, x, 10);
	}
	return out;
}

long long int rotateDigits( long long int x )
{
	std::vector< long long int > temp = splitInt(x);
	std::vector< long long int > out (temp.begin()+1, temp.end());
	out.push_back(temp[0]);
	return joinIntVector(out);
}

long long int flipInt( long long int x )
{
	long long int out = 0;
	while ( x )
	{
		out = out * 10 + ( x % 10 );
		x = x / 10;
	}
	return out;
}

void flipMpz_t( mpz_t n )
{
	mpz_t y; mpz_init_set_ui( y, 0 );
	mpz_t z; mpz_init(z);
	while ( mpz_get_ui( n ) )
	{
		mpz_mul_ui(y, y, 10);
		mpz_mod_ui(z, n, 10);
		mpz_add(y, y, z);
		mpz_tdiv_q_ui(n, n, 10);
	}
	mpz_set(n, y);
}

std::vector< bool > flipBoolVector( std::vector< bool > in )
{
	std::vector< bool > out;
	for ( unsigned int i = 0; i < in.size(); i++ )
		out.insert(out.begin(), in[i]);
		
	return out;
}

std::vector< bool > convertIntToBinaryVector( long long int x )
{
	std::vector< bool > out (false, 8);
	int i = 8;
	if ( x > 255 )
		throw 255;
	while ( i )
	{
		out.insert(out.begin(), x % 2);
		x = x / 2;
		i -= 1;
	}
	return out;
}
long long int convertBinaryVectorToInt( std::vector< bool > n )
{
	long long int out = 0;
	int x = pow((double)2, (double)n.size()-1);
	for ( unsigned int i = 0; i < n.size(); i++ )
	{
		out += n[i]*x;
		x = x / 2;
	}
	return out;
}
std::unordered_map< std::vector< bool >, int > binaryToIntList( int digits )
{
	std::unordered_map< std::vector< bool >, int > int_list;
	for( int i = 1; i < pow((double)2, (double)digits); i++ )
	{
		int_list[convertIntToBinaryVector( i )] = i;
	}
	return int_list;
}
std::vector< std::vector< bool > > intToBinaryList( int digits )
{
	std::vector< std::vector< bool > > int_list;
	for( int i = 1; i < pow((double)2, (double)digits); i++ )
	{
		int_list.push_back(convertIntToBinaryVector( i ));
	}
	return int_list;
}

bool isPandigital( long long int x )
{
	std::vector< long long int > y = splitInt( x );
	unsigned short int found;
	
	for ( unsigned int i = ( y.size() == 10 ) ? 0 : 1; i < y.size() + ( ( y.size() == 10 ) ? 0 : 1 ); i++ )
	{
		found = 0;
		for ( unsigned int j = 0; j < y.size(); j++ )
			if ( y[j] == i )
				found += 1;
		if ( found != 1 )
			return false;
	}
	return true;
}
bool isPermutation( std::vector< long long int > x, std::vector< long long int > y )
{
	if ( x.size() != y.size() )
		return false;
	
	for ( unsigned int i = 0; i < x.size(); i++ )
		for ( unsigned int j = 0; j < y.size(); j++ )
			if ( x[i] == y[j] ) {
				y.erase(y.begin()+j);
				break;
			}
			
	if ( y.size() == 0 )
		return true;
	return false;
}
bool isPermutation( long long int x, long long int y )
{
	if ( digitsInInt(x) != digitsInInt(y) )
		return false;
	
	int z;
	int k = 0;
	for ( int i = 0; i < digitsInInt(x); i++ )
		for ( int j = 0; j < digitsInInt(y); j++ )
			if ( digit( x, i ) == digit( y, j ) )
			{
				z = exponentOfInt(10, digitsInInt(y)-j-1);
				y = (y/(z*10))*z+(y%z);
				k++;
				break;
			}
	
	if ( k == digitsInInt(x) )
		return true;
	return false;
}

bool isPentagonal( long long int x )
{
	double result = ( sqrt( (double)( 24*x + 1 ) ) +1 ) / 6;
	return ( result == (int)result );
}

bool isIn( std::vector< long long int > list, long long int target )
{
	for ( unsigned int i = 0; i < list.size(); i++ )
		if ( list[i] == target )
			return true;
	return false;
}
bool isIn( std::vector< std::string > list, std::string target )
{
	for ( unsigned int i = 0; i < list.size(); i++ )
		if ( list[i] == target )
			return true;
	return false;
}

long long int distinct( std::vector< long long int > list )
{
	std::vector< long long int > seen;
	for ( unsigned int i = 0; i < list.size(); i++ )
	{
		if ( !isIn( seen, list[i] ) )
		{
			seen.push_back(list[i]);
		}
	}
	return seen.size();
}

bool isPalindrome( mpz_t x )
{
	mpz_t y; mpz_init_set( y, x );
	flipMpz_t(y);
	//std::cout << mpz_get_ui(y) << std::endl;
	//std::cout << mpz_get_ui(x) << std::endl;
	return mpz_get_ui(y) == mpz_get_ui(x);
}

std::vector< long long int > primeFactorsOf( long long int x )
{
	std::vector< long long int > out { x, 0 };
	unsigned int i = 0;
	bool repeat;
	while ( out[i] )
	{
		repeat = false;
		i = 0;
		while ( i < out.size() )
		{
			for ( int j = 2; j < sqrt( (double)out[i] ); j++ )
			{
				if ( out[i] % j == 0 && isPrime( j ) )
				{
					repeat = true;
					long long int insert[] = { j, out[i] / j };
					out.erase(out.begin()+i);
					out.insert(out.begin()+i, insert, insert+2);
					break;
				}
			}
			i++;
		}
		if ( !repeat )
			break;
	}
	out.assign(out.begin(), out.end()-1);
	return out;
}

// FACTORIALS
long long int factorial( long long int x )
{
	int facts [] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
	if ( x < 10 && x >= 0 )
		return facts[x];
	else
	{
		long long int out = 1;
		while ( x )
		{
			out *= x;
			x --;
		}
		return out;
	}
}
std::vector< long long int > factorialTable( int n )
{
	std::vector< long long int > out;
	for ( int i = 0; i <= n; i++ )
		out.push_back(factorial(i));
	return out;
}
long long int ncr(long long int n, long long int r)
{
	return factorial(n) / ( factorial(r) * factorial(n - r) );
}
long long int ncr(long long int n, long long int r, std::vector< long long int > factorial_table)
{
	return factorial_table[n] / ( factorial_table[r] * factorial_table[n - r] );
}
// END FACTORIALS
	
// BIG FACTORIALS
void longFactorial( mpz_t out, int n )
{
	mpz_set_ui( out, 1 );
	while ( n )
	{
		mpz_mul_ui( out, out, n );
		n --;
	}
}
void longNCR( mpz_t out, int n, int r, mpz_t *factorial_table )
{
	mpz_t a, b, c; mpz_init(a); mpz_init(b); mpz_init(c);
	
	longFactorial( a, n );
	longFactorial( b, r );
	longFactorial( c, n-r );
	
	mpz_mul( out, b, c );
	mpz_cdiv_q( out, a, out );
	
	mpz_clear(a); mpz_clear(b); mpz_clear(c); 
}
// END BIG FACTORIALS

std::vector< bool > binaryXOR( std::vector< bool > a, std::vector< bool > b )
{
	std::vector< bool > c (8, false);
	for ( int i = 0; i < 8; i++ )
		if ( a[i] != b[i] )
			c[i] = true;
	return c;
}

std::vector< long long int > genContFrac( int S, int depth )
{
	std::vector< int > m (1, 0);
	std::vector< int > d (1, 1);
	std::vector< long long int > a (1, (int)floor( sqrt( S ) ));
	for ( int n = 0; n < depth ; n++ )
	{
		m.push_back( d[n]*a[n] - m[n] );
		d.push_back( ( S - ( m[n+1]*m[n+1] ) ) / d[n] );
		a.push_back( (int)floor( ( a[0] + m[n+1] ) / d[n+1] ) );
	}
	return a;
}

