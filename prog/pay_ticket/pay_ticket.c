#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_card()
{
	FILE *fp;

	char ch;

	fp = fopen("data.txt", "r");
	if (fp == NULL)
	{
		printf("FILE DOES NOT FOUND!");
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
	struct book {
		char card[20];
		char name[20];
		int cost;
	};

	struct book b;

	FILE *fpp;
	FILE *ufp;

	char phnum[20];
	char cardnum[20];
	char name[20];

	printf("\nEnter your card number: ");
	scanf("%s", cardnum);
	//system("clear");
	fpp = fopen("data.txt", "r");
	if (fpp == NULL)
	{
		printf("FILE DOES NOT FOUND!");
		exit(1);
	}
	else
	{
		while (getc(fpp) != EOF)
		{
			fscanf(fpp, "%s %s %d", b.card, b.name, &b.cost);

			if (strcmp(b.card, cardnum) == 0)
			{
				printf("\nRecord Found.");
				printf("\n\tCard number: %s", b.card);
				printf("\n\tName: %s", b.name);
				printf("\n\tBalance of accounts: %d", b.cost);

				ccost = b.cost;
				break;
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
	printf("\n\t\tName: %s", name);
	printf("\n\t\tPhone number: %s", phnum);
	printf("\n\t\tMovie name: %s", movie_name[msel - 1]);
	printf("\n\t\tYour seat: %d-%d", mrow, mcol);
	printf("\n\t\tTicket price: %d", ticket);

	ufp = fopen("reserved.txt", "a");
	if (ufp == NULL)
	{
		printf("FILE DOES NOT FOUND!");
		exit(1);
	}
	else
	{
		fprintf(ufp, "%s %s %s %d-%d %d \n", name, phnum, movie_name[msel - 1], mrow, mcol, ticket);
		printf("\nSuccessful. ");
		printf("\n");
		fclose(ufp);
		fclose(fpp);

		return 1;
	}

	printf("\n");
	fclose(ufp);
	fclose(fpp);

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
