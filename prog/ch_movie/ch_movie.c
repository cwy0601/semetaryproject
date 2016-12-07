#include <stdio.h>
#include <stdlib.h>

void ch_movie(char **movie_name, int CNT, int *msel)
{
	int i;

	printf("===> EEEEE  SSS  EEEEE <===\n");
	printf("===> E     SS    E     <===\n");
	printf("===> EEEEE  SSS  EEEEE <===\n");
	printf("===> E        SS E     <===\n");
	printf("===> EEEEE  SSS  EEEEE <===\n");
	printf("Theater Ticket Reservation\n\n");

	for(i = 1; i <= CNT; i++)
		printf("%d. %s\n", i, movie_name[i-1]);

	printf("Which movie do you want to watch?\n");
		
	while(1)
	{
		printf("Press number : ");
		scanf("%d", msel);

		if(*msel < 0 || *msel > CNT)
		{
			printf("Please write in 1 ~ %d\n", CNT);
			continue;
		}
		else
		{
			printf("You've chosen %s!\n", movie_name[(*msel)-1]);
			printf("----------------------------\n\n");
			break;
		}
	}
}
