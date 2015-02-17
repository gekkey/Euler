#include <iostream>
#include <vector>

int line_sum(int *node, int line)
{
	int l[3] = {node[line], node[line - 1], node[line - 2]};
	if (line == 9) l[2] = node[1];
	return l[0] + l[1] + l[2];
}

int *step(int *node, std::vector<int> el, int x)
{
	std::vector<int*> results;
	int restore = node[x];
	int *new_node = new int[10];
	int *next_step;

	for (unsigned int i = 0; i < el.size(); ++i)
	{
		node[x] = el[i];

		// the lowest external number must be at node[0]
		if (((x % 2 == 1 && x != 1) && el[i] < node[0]) ||
		// 10 can only be used once; must be on the outside
		((x % 2 == 0 && x != 1) && el[i] == 10) ||
		// the sum of each line must be equal
		(((x % 2 == 0 && x != 0) || x == 9) && line_sum(node, x) != line_sum(node, 2)))
			continue;
		if (el.size() == 1)
		{ // if this was the last element, the node is a solution
			for (int j = 0; j < 10; ++j) new_node[j] = node[j];
			return new_node;
		}
		else
		{ // otherwise remove the used el and pass the ring on another step
			std::vector<int> new_el = el;
			new_el.erase(new_el.begin()+i);
			next_step = step(node, new_el, x + 1);
			if (next_step) return next_step;
		}
	}
	node[x] = restore;

	return 0;
}

int main(int argc, char *argv[])
{
	int node[10] = {0};
	int* result = step(
		node, std::vector<int> {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 0
	);

	std::cout << result[0];
	std::cout << result[1];
	std::cout << result[2];
	for (int i = 1, n = 2; i < 5; ++i)
	{
		std::cout << result[n + 1];
		std::cout << result[n];
		if (i == 4) std::cout << result[1];
		else std::cout << result[n += 2];
	}
	std::cout << std::endl;

	delete[] result;
	return 0;
}
