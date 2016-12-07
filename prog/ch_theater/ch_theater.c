#include <stdio.h>
#include <string.h>

void ch_theater(char **theater)
{
	char num;

	printf("Please Choose a theater.\n");

	for (int i = 0; i < 6; i++)
		printf("%d. %s\n", i + 1, theater[i]);

	printf("write number of theater.\n");

	while (1)
	{
		scanf("%c", &num);

		if ((num >= 65 && num <= 90) || (num >= 97 && num <= 122))
		{
			printf("Please put number.\n");
			continue;
		}
		else if (num >= 48 && num <= 57)
		{
			num -= '0';

			if (num <= 0 || num > 6)
			{
				printf("Please choose number in 1 - 6.\n");
				continue;
			}
			else
				break;
		}
	}

	printf("You've chosen %s!\n", theater[num - 1]);
	printf("----------------------------\n\n");
}
