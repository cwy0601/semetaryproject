#include <stdio.h>
#include <stdlib.h>

void display_card()
{
	FILE *fp;

	char ch;

	fp = fopen("data.txt", "r");
	if(fp == NULL)
	{
		printf("FILE DOES NOT FOUND!");
		exit(1);

	}
	else
	{
		system("clear");
		while( (ch = fgetc(fp)) != EOF )
      		printf("%c", ch);
	}

	fclose(fp);
}

void pay_ticket()
{
	struct book{
        char card[20];
        char name[20];
        int cost;
	}b;

	FILE *fpp;
	FILE *ufp;

	int ticket = 6000;
	char phnum[20];
	char cardnum[20];
	char name[20];

	printf("\nEnter your card number: ");
	scanf("%s", cardnum);
	//system("clear");
	fpp = fopen("data.txt", "r");
	if(fpp == NULL)
	{
		printf("FILE DOES NOT FOUND!");
		exit(1);

	}
	else
	{	
		while(getc(fpp) != EOF)
		{
			fscanf(fpp, "%s %s %d", b.name, b.card, &b.cost);
			if(strcmp(b.card, cardnum) == 0)
			{	
				printf("\n Record Found.");
				printf("\n\t\tCard number: %s", b.card);
				printf("\n\t\tName: %s", b.name);
				printf("\n\t\tBalance of accounts: %d", b.cost);
			}
		}
		
	}

	printf("\nPlease enter your details.");
	printf("\nName: ");
	scanf("%s", name);
	printf("\nPhone number: ");
	scanf("%s", phnum);

/*	b.cost = b.cost - ticket;
	if(b.cost < 6000){
		printf("You don't have enough money to pay ticket. \n");
		exit(0);
	} */
	
	printf("\n ***** TRANSACTIONS ****\n");
	printf("\n\t\tName: %s", name);
	printf("\n\t\tPhone number: %s", phnum);
//	printf("\n\t\tMovie name: %s", b.name);
//	printf("\n\t\tTotal seats : %d",total_seat);
	printf("\n\t\tTicket price: %d", ticket);
//	printf("\n\t\tTotal Amount: %d", total_amount);

	ufp = fopen("reserved.txt", "a");
	if(ufp == NULL)
	{
		printf("FILE DOES NOT FOUND!");
		exit(1);
	}
	else
	{
		fprintf(ufp, "%s %s %d \n", name, phnum, ticket);
		printf("\nSuccessful. ");
	}
	
	printf("\n");
	fclose(ufp);	
	fclose(fpp);
}

void payment()
{
	int select;

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
	    		pay_ticket();
	   		break;
	
	    		case 0:
	    		exit(0);
	    		break;
	
	    		default:
	    		printf("YOU TYPED A WRONG NUMBER!");
	    		break;
	   	}
	 }while(select != 0);
}
