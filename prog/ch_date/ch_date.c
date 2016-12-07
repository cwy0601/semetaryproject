#include <stdio.h>
#include <string.h>
#include <time.h>

void ch_date(int *year, int *month, int *day)
{
	int y_flag = 0;
	int m_flag = 0;

	time_t timer;
	struct tm *t;

	timer = time(NULL);
	t = localtime(&timer);

	printf("Please choose date to watch a movie.\n");
	printf("Please choose a year (2016 or 2017): ");

	while (1)
	{
		scanf("%d", year);

		if (*year > 2017 || *year < 2016)
		{
			printf("Please choose in 2016 or 2017.\n");
			printf("Please choose a year again: ");
			continue;
		}
		else if(*year < (t->tm_year+1900))
		{
			printf("Already passed!\n");
			printf("Please choose a year again: ");
			continue;
		}
		else if(*year > (t->tm_year+1900))
		{
			y_flag = 1;
			break;
		}
		else		
			break;
	}	

	printf("Please choose a month : ");

	while (1)
	{
		scanf("%d", month);

		if (*month > 12 || *month <= 0)
		{
			printf("Please choose in January ~ December.\n");
			printf("Please choose a month again: ");
			continue;
		}
		else if(y_flag == 0)
		{
			if(*month < (t->tm_mon+1))
			{
				printf("Already passed!\n");
				printf("Please choose a month again: ");
				continue;
			}
			else if(*month > (t->tm_mon+1))
			{
				m_flag = 1;
				break;
			}
			else
				break;
		}
		else
			break;
	}

	printf("Please choose a day: ");

	while (1)
	{
		scanf("%d", day);

		if (*day == 0)
		{
			printf("Please type a correct day: ");
			continue;
		}
		else if(m_flag == 0)
		{
			if(*day < t->tm_mday)
			{
				printf("Already passed!\n");
				printf("Please choose a day again: ");
				continue;
			}
		}

		if (((*month <= 7 && *month % 2 == 0) || (*month > 7 && *month % 2 == 1)) && *day > 30)
		{
			if (*month == 2)
			{
				if (*year % 4 == 0)
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
		else if (((*month <= 7 && *month % 2 == 1) || (*month > 7 && *month % 2 == 0)) && *day > 31)
		{
			printf("Please choose in 1 - 31: ");
			continue;
		}
		else
			break;
	}

	printf("\nYou've chosen %d. %d. %d!\n\n", *year, *month, *day);
}
