#include <stdio.h>

void ch_seat(int mrow, int mcol)
{
	int row = 0;
	int col = 0;
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
		printf("Choose seat: Row and Column\n");
		scanf("%d %d", &row, &col);

		if ((row<1 || row>10) && (col<1 || col>10))
		{
			printf("Wrong choice, try again\n");
		}

		if (taken[row][col])
		{
			printf("This seat is taken, try again\n");
		}
		else
		{
			taken[row][col] = 1;
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

		mrow = row;
		mcol = col;
		break;
	}while(1);
}
