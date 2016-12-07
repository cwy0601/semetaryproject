#include <stdio.h>
#include <string.h>

void ch_date(int year, int month, int day, char *date)
{
	printf("Please choose date to watch a movie.\n");
	printf("Type a year (2016 or 2017): ");	

	while (1)
	{	
		scanf("%d", &year);

		if (year > 2017 || year < 2016)
		{
			printf("Please choose in 2016 or 2017.\n");
			printf("Type a year: ");	
			continue;
		}
		else
			break;
	}

	while (1)
	{
		printf("Please choose a month (1 - 12): \n");		
		scanf("%d", &month);

		if (month > 12 || month <= 0)
		{
			printf("Please choose in January ~ December.\n");
				continue;
		}
		else
			break;
	}

	printf("Please choose a day: ");

	while (1)
	{
		scanf("%d", &day);

		if (day == 0)
		{
			printf("Please type a correct day: ");
			continue;
		}

		if (((month <= 7 && month % 2 == 0) || (month > 7 && month % 2 == 1)) && day > 30)
		{
			if (month == 2)
			{
				if (year % 4 == 0)
				{
					printf("Please choose in 1 - 29: ");
					continue;
				}
				else
				{
					printf("Please choose in 1 - 28: ");
					continue;
				}
			}

			printf("Please choose in 1 - 30: ");
			continue;
		}
		else if (((month <= 7 && month % 2 == 1) || (month > 7 && month % 2 == 0)) && day > 31)
		{
			printf("Please choose in 1 - 31: ");
			continue;
		}
		else
			break;
	}

	printf("\nYou've chosen %d. %d. %d!\n\n", year, month, day);
}
