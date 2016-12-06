#include <stdio.h>
#include <string.h>
#include "../../include/info.h"

void ch_date(void)
{
	printf("Please choose date to watch a movie.\n");

	while (1)
	{
		scanf("%d", &year);

		if (year > 2017 || year < 2016)
		{
			printf("Please choose in 2016 or 2017.\n");
				continue;
		}
		else
			break;
	}

	printf("Please choose a month.\n");

	while (1)
	{
		scanf("%d", &month);

		if (month > 12 || month < 0)
		{
			printf("Please choose in January ~ December.\n");
				continue;
		}
		else
			break;
	}

	printf("Please choose a day.\n");

	while (1)
	{
		scanf("%d", &day);

		if (((month <= 7 && month % 2 == 0) || (month > 7 && month % 2 == 1)) && day > 30)
		{
			if (month == 2)
			{
				if (year % 4 == 0)
				{
					printf("Please choose in 0 - 29.\n");
					continue;
				}
				else
				{
					printf("Please choose in 0 - 28.\n");
					continue;
				}
			}

			printf("Please choose in 0 - 30.\n");
			continue;
		}
		else if (((month <= 7 && month % 2 == 1) || (month > 7 && month % 2 == 0)) && day > 31)
		{
			printf("Please choose in 0 - 31.\n");
			continue;
		}
		else
			break;
	}

	printf("You've chosen %d. %d. %d!\n", year, month, day);
}
