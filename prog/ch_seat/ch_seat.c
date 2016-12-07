#include <stdio.h>

void ch_seat(int *mrow, int *mcol)
{
	int i, j;

	// seat selection prototype

	int seat[11][11] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
	};

	int taken[11][11] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};

	printf("============= Theater ==============\n");
	for (i = 1; i <= 10; i++)
	{
		for (j = 1; j <= 10; j++)
		{
			printf(" %d  ", seat[i][j]);
		}

		printf("\n");
	}

	do
	{
		printf("Choose seat.\n");

		while(1)
		{		
			printf("Type row: ");
			scanf("%d", mrow);

			if (*mrow<1 || *mrow>10)
			{
				printf("Wrong choice, try again.\n");
				continue;
			}

			break;
		}

		while(1)
		{		
			printf("Type column: ");
			scanf("%d", mcol);

			if (*mcol<1 || *mcol>10)
			{
				printf("Wrong choice, try again.\n");
				continue;
			}

			break;
		}

		if (taken[*mrow][*mcol])
		{
			printf("This seat is taken, try again\n");
		}
		else
		{
			taken[*mrow][*mcol] = 1;
          		printf("============= Theater =============\n");

			for (i = 1; i <= 10; i++)
			{
				for (j = 1; j <= 10; j++)
				{
					if (taken[i][j] == 0)
					{
						printf(" %d  ", seat[i][j]);
					}
					else
					{
						printf("[%d] ", seat[i][j]);
					}
				}

				printf("\n");
			}
		}
		break;
	}while(1);
}
