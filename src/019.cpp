#include <cstdio>

int main(int argc, char *argv[])
{
	short year = 1900 + 1;
	char weekday = 0 + (365 % 7);
	char month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	
	int month = 0;
	int i = 0;
	while (year <= 2000)
	{
		if ((weekday %= 7) == 6)
			i++;

		weekday += month_days[month];
		if (month == 1 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			weekday += 1;

		if (++month == 12) {
			month = 0;
			year++;
		}
	}

	printf("%d\n", i);
}
