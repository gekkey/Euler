class permutation_iterator
{
	int* values;
	int* order;
	int len;
	bool valid = true;

	public:
	permutation_iterator(int, int*);
	permutation_iterator(int a) : permutation_iterator(a, NULL) {};
	bool step();
	long to_long();
	permutation_iterator operator=(int*);
	permutation_iterator operator++(int);
	explicit operator bool() const;
};

bool is_permutation(int a, int b);
