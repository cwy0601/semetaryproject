#include <stdio.h>
#include <stdlib.h>

void ch_movie(char **movie_name, int CNT, int msel)
{
	int i;

	for(i = 1; i <= CNT; i++)
		printf("%d. %s\n", i, movie_name[i-1]);

	printf("which movie do you want to watch?\n");
	printf("Press number : ");
	scanf("%d", &msel);

	if(msel < 0 || msel > CNT)
		printf("Please write in 1 ~ %d\n", CNT);
	else
		printf("You've chosen %s!\n", movie_name[msel-1]);
}
