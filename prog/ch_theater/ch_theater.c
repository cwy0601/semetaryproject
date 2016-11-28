#include <stdio.h>
#include <string.h>

char *theater[6] = {"Ilsan", "Hwajeong", "Guri", "Gimpo", "Bucheon", "Pangyo"};
char *chosen;

int main(void)
{
	int num;

	printf("Please Choose a theater.\n");

	for(int i = 0; i < 6; i++)
		printf("%d. %s\n", i+1, theater[i]);

	printf("write number of theater.\n");

	while(1)
	{
		scanf("%d", &num);

		if(num < 0 || num > 6)
		{
			printf("Please choose number in 1 - 6.\n")
			continue;
		}
		else
			break;
	}

	printf("You've chosen %s!\n", theater[num-1]);
}
