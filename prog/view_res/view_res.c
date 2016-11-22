#include <stdio.h>
#include <stdlib.h>

void view_res() // for view reservation
{
        char ch;
        FILE *fp;

//	system("clear");

        fp = fopen("reserved.txt","r");

	if(fp == NULL)
        {
		printf("CANNOT READ RESERVATION DATA!");
                exit(1);
        }
        else
        {
                system("clear");
		printf("Your reservation lists: \n"); 
                while(( ch = fgetc(fp) ) != EOF)
                printf("%c", ch);
        }

        fclose(fp);
}

int main(void)
{
	view_res();
	return 0;
}
