#include <stdio.h>
#include <stdlib.h>

#define CNT 5

char *movie_name[CNT] = {"Suicide Squad", "Harry Potter", "Gravity", "Inception", "interstellar"};

void ch_movie(void)
{
	int i;
	int sel;

	for(i = 1; i <= CNT; i++)
		printf("%d. %s\n", i, movie_name[i-1]);

	printf("which movie do you want to watch?\n");
	printf("Press number : ");
	scanf("%d", &sel);

	if(sel < 0 || sel > CNT)
		printf("Please write in 1 ~ %d\n", CNT);
	else
		printf("You've chosen %s!\n", movie_name[sel-1]);
}
