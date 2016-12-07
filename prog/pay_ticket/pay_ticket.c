#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_DATA	3

void display_card()
{
	FILE *fp;

	char ch;

	fp = fopen("data.txt", "r");
	if (fp == NULL)
	{
		printf("FILE DOES NOT FOUND!\n");
		exit(1);
	}
	else
	{
		system("clear");
		while ((ch = fgetc(fp)) != EOF)
			printf("%c", ch);
	}

	fclose(fp);
}

int pay_ticket(char **movie_name, int msel, int mcol, int mrow, int ticket, int ccost)
{
	int idx = 0;

	struct book {
		char card[20];
		char name[20];
		int cost;
	};

	struct book b[NUM_OF_DATA];

	FILE *fpp;
	FILE *ufp;

	char phnum[20];
	char cardnum[20];
	char name[20];

	//system("clear");
	fpp = fopen("data.txt", "r");
	if (fpp == NULL)
	{
		printf("FILE DOES NOT FOUND!\n");
		exit(1);
	}
	else
	{
		while (getc(fpp) != EOF)
		{
			fscanf(fpp, "%s %s %d", b[idx].card, b[idx].name, &b[idx].cost);
			idx++;
		}
		
		idx = 0;

		printf("\nEnter your card number: ");

		while(1)
		{
			scanf("%s", cardnum);
			
			if (strcmp(b[idx].card, cardnum) == 0)
			{
				printf("\nRecord Found.");
				printf("\n\tCard number: %s", b[idx].card);
				printf("\n\tName: %s", b[idx].name);
				printf("\n\tBalance of accounts: %d", b[idx].cost);

				ccost = b[idx].cost;
				break;
			}
			
			idx++;

			if(idx == NUM_OF_DATA)
			{
				printf("You enter a wrong number. Please try again.\n");
				idx = 0;
				continue;
			}
		}	
	}

	printf("\n\nPlease enter your details.");
	printf("\nName: ");
	scanf("%s", name);
	printf("Phone number: ");
	scanf("%s", phnum);

	if (ccost < ticket) {
		printf("You don't have enough money to pay ticket. \n");
		exit(0);
	}
	
	printf("\n ***** TRANSACTIONS ****\n");
	printf("\n\tName: %s", name);
	printf("\n\tPhone number: %s", phnum);
	printf("\n\tMovie name: %s", movie_name[msel - 1]);
	printf("\n\tYour seat: %d-%d", mrow, mcol);
	printf("\n\tTicket price: %d\n", ticket);

	ufp = fopen("reserved.txt", "a");
	if (ufp == NULL)
	{
		printf("FILE DOES NOT FOUND!\n");
		exit(1);
	}
	else
	{
		fprintf(ufp, "%s  %s  %s  %d-%d  %d \n", name, phnum, movie_name[msel - 1], mrow, mcol, ticket);
		printf("\nSuccessfully reserved!\n\n");
		printf("-----------------------------");
		fclose(ufp);
		fclose(fpp);

		return 1;
	}

	printf("\n");
	fclose(ufp);
	fclose(fpp);
	
	return 0;
}

void payment(char **movie_name, int msel, int mcol, int mrow, int ticket, int ccost)
{
	int select;
	int retval;

	do
	{
		printf("\n");
		printf("\t PAYMENT OPTIONS");
		printf("\n");

		printf("\nPress <1>: Display Card Informations");
		printf("\nPress <2>: Pay Ticket");
		printf("\nPress <0>: Exit");

		printf("\nEnter your Choice: ");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			display_card();
			break;

		case 2:
			retval = pay_ticket(movie_name, msel, mcol, mrow, ticket, ccost);
			if (retval)
				return;
			break;

		case 0:
			exit(0);
			break;

		default:
			printf("YOU TYPED A WRONG NUMBER!");
			break;
		}
	} while (select != 0);
}
