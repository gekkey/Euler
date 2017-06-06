#include <cstdio>

int main(int argc, char *argv[])
{
	int MAX = 1000000;

	int *known_distance = new int[MAX]();
	int longest_start, longest_len = 0;

	int len;
	long step;
	for (int i = 1; i < MAX; i++)
	{
		len = 1;
		step = i;
		while (step > 1)
		{
			if (step < MAX && known_distance[step]){
				len += known_distance[step];
				break;
			}
			if (step % 2)
				step = step * 3 + 1;
			else
				step /= 2;
			len++;
		}

		known_distance[i] = len - 1;

		if (len > longest_len) {
			longest_len = len;
			longest_start = i;
		}
	}

	printf("%d\n", longest_start);
	return 0;
}
