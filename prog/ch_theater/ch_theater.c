#include <stdio.h>
#include <string.h>

void ch_theater(char **theater, char *tsel)
{
	printf("Please Choose a theater.\n");

	for (int i = 0; i < 6; i++)
		printf("%d. %s\n", i + 1, theater[i]);

	printf("write number of theater.\n");

	while (1)
	{
		scanf("%c", tsel);

		if ((*tsel >= 65 && *tsel <= 90) || (*tsel >= 97 && *tsel <= 122))
		{
			printf("Please put number.\n");
			continue;
		}
		else if (*tsel >= 48 && *tsel <= 57)
		{
			*tsel -= '0';

			if (*tsel <= 0 || *tsel > 6)
			{
				printf("Please choose number in 1 - 6.\n");
				continue;
			}
			else
				break;
		}
	}

	printf("You've chosen %s!\n", theater[*tsel - 1]);
	printf("----------------------------\n\n");
}
