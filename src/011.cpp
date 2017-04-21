#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	// read 1000 digit array from text file
	char **number = new char*[20];
	for (int i = 0; i < 20; i++)
		number[i] = new char[20];
	FILE *fo = fopen("data/011.txt", "r");
	char direction[4][2] = {{1, 0}, {0, 1}, {1, 1}, {-1, 1}};

	int i = 0;
	while (fscanf(fo, "%hhd", &(number[i/20][i%20])) != EOF)
		i++;

	int t, r = 0;
	for (int y = 0; y < 20 - 4; y++) {
		for (int x = 0; x < 20 - 4; x++) {
			for (int i = 0; i < 4; i++) {
				t = 1;
				for (int j = 0; j < 4; j++) {
					t *= number[x][y];
					x += direction[i][0];
					y += direction[i][1];
				}
				x -= direction[i][0] * 4;
				y -= direction[i][1] * 4;

				if (i == 2 && x < 3)
					i++;
				if (t > r)
					r = t;
			}
		}
	}

	printf("%d\n", r);
	return 0;
}
