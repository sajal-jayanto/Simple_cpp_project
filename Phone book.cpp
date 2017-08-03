#include<stdio.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<setjmp.h>
void initialization();
void view();
void search();
void delet();
void dispaly();
typedef struct list               /* made a struct for link list*/
{
    char name[50];
	char phone_number[20];
    struct list* next;
}list;
struct list *dummy;
void initialization()             /* initialize the frist node*/
{
    dummy = (list*)malloc(sizeof(list));
    dummy->next = NULL;
}
void insert(list *x)             /*insert function*/
{
    struct list *temp = dummy;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    x->next = temp->next;
    temp->next = x;
}
int main()
{
    struct list *x, *dummy;
    char ch;
	char name_insert[50];
	char phone_insert[20];
	system("color A");         /*use as view color*/
    initialization();          /* call the initialization for the first time*/
    while(1)
    {
        dispaly();             /* call the dispaly board function */
        ch = getch();          /* get the kye */
        if(ch == 'c' || ch == 'C')
        {
        	system("cls");     /*clear the scan*/
        	printf("\n            ENTER NAME: "); /*give the memessag for viewr*/
        	gets(name_insert); /*get the name*/
        	printf("            ENTER THE PHONE NUMBER: ");       /*give the memessag for viewr*/
        	gets(phone_insert); /*get the phone number*/
        	if(strlen(phone_insert) == 5)
			{
				printf("\n            THE NUMBER HAS BEEN SUCCESS FULLY STORED.."); /*give the memessag for viewr*/
				x = (list*)malloc(sizeof(list)); /*get space for new name and phone number*/
        		strcpy(x->phone_number,phone_insert); /*copy the phone number*/
        		strcpy(x->name,name_insert);    /*copy the name*/
        		insert(x);   /*insert the name and phone number*/
				printf("\n            PRESS \"ENTER\" TO CONTINUE....");  /*give the memessag for viewr*/
				getchar();  /*system puss*/
        		system("cls");  /*clear the secan*/

			}
			else
			{
				if(strlen(phone_insert) > 11)
				printf("                THE NUMBER IS TOO BIG..\n");   /*give the memessag for viewr*/
				else printf("            THE NUMBER IS TOO SMALL..\n"); /*give the memessag for viewr*/
				printf("            PRESS 'ENTER' TO CONTINUE...."); /*give the memessag for viewr*/
				getchar(); /*system puss*/
				system("cls"); /*clear the secan*/
			}
        }
        if(ch == 'V' || ch == 'v')
        {
        	system("cls");  /*clear the secan*/
        	view(); /*view all the contact */
        	getch(); /*system puss*/
        	system("cls"); /*clear the secan*/
        }
        if(ch == 'D' || ch =='d')
        {
        	system("cls"); /*clear the scan*/
        	delet(); /* delete contact */
        	getch(); /*system puss*/
            system("cls"); /*clear the scan*/
        }
        if(ch == 'S' || ch == 's')
        {
        	system("cls"); /*clear the secan*/
            search(); /*scarch contact*/
            getch();  /*system puss*/
            system("cls"); /*clear the secan*/
        }
        if(ch == 'E' || ch == 'e')
        {
        	printf("%c",ch);
        	break ; /* end the system*/
        }
    }
    return 0;
}
void view()   /* all data view the function*/
{
	printf("                    WELCOME TO PHONE BOOK PROJECT\n");
	printf("              ----------------------------------------\n\n");
    list *temp = dummy;
    temp = temp->next;
    while(temp!=NULL)
    {
        printf("\n            NAME:%s\n            PHONE NUMBER: %s",temp->name,temp->phone_number);
        printf("\n\n");
        temp=temp->next;
    }
}
void search()  /* search function*/
{
	printf("                    WELCOME TO PHONE BOOK PROJECT\n");
	printf("              ----------------------------------------\n\n");
	int num;
	char nam[100];
	struct list *car;
	car = dummy;
	printf("                 PRESS-->[1] FOR SEARCH BY NAME.\n");
	printf("                 PRESS-->[2] FOR SEARCH BY PHONE NUMBER.\n");
	printf("\n                 HOW YOU WANT TO SEARCH:");
	scanf("%d",&num);
	getchar();
	if(num == 1) printf("\n                 ENTER THE NAME:");
	else printf("\n                 ENTER THE PHONE NUMBER:");
	gets(nam);
	if(num == 1)
	{
		while(car->next!=NULL)
		{
			if(strcmp((car->next)->name,nam) == 0)  /*comper tne names*/
			{
				printf("\n\n");
				printf("              NAME : %s\n",(car->next)->name);
				printf("              PHONE NUMBER : %s\n",(car->next)->phone_number);
				break;
			}
			else car = car->next;
		}
	}
	else if(num == 2)
	{
		while(car->next!=NULL) /* a loop untile NULL*/
		{
			if(strcmp((car->next)->phone_number,nam) == 0) /*comper tne names*/
			{ 
				printf("\n\n");
				printf("                    NAME : %s\n",(car->next)->name);   /*veiw the search name */
				printf("                    PHONE NUMBER : %s\n",(car->next)->phone_number); /*veiw the search phone number */
				break;
			}
			else car = car->next; 
		}
	}
	printf("\n            PRESS \"ENTER\" TO CONTINUE....");  /*give the memessag for viewr*/
	getchar();
	
}
void delet()   /* delet function*/
{
	char nam[100];
    int num;
    struct list *cur, *temp;
    cur = dummy;
	printf("                    WELCOME TO PHONE BOOK PROJECT\n");
	printf("              ----------------------------------------\n\n");
    printf("                 PRESS-->[1] FOR DELET BY NAME.\n");
	printf("                 PRESS-->[2] FOR DELET BY PHONE NUMBER.\n");
	printf("\n                 HOW YOU WANT TO DELET:");
	scanf("%d",&num);
	getchar();
	if(num == 1)
	{
		printf("\n                 ENTER THE NAME:");	
	} 
	else
	{
		printf("\n                 ENTER THE PHONE NUMBER:");	
	} 
	gets(nam);
	if(num == 1)
	{
		while(cur->next!=NULL)  /*a loop untile NULL found*/
    	{
    		if(strcmp((cur->next)->name,nam) == 0) /*comper tne names*/
    		{
    			temp = cur->next;  
    			cur->next = cur->next->next;   
    			free(temp);   /*free the space*/
    		}
    		else cur = cur->next;
   		}
	}
    if(num == 2)
    {
    	while(cur->next!=NULL)  /*a loop untile NULL found*/
    	{
    		if(strcmp((cur->next)->phone_number,nam) == 0) /*comper tne names*/
    		{
    			temp = cur->next;  
    			cur->next = cur->next->next;   
    			free(temp);   /*free the space*/
    		}
    		else cur = cur->next;
   		}
    }
    system("cls");
    printf("                            CONTACT DELETTED!!");
}
void dispaly()  /* dispaly function*/
{
	system("cls");
	printf("                    WELCOME TO PHONE BOOK PROJECT\n");
	printf("              ----------------------------------------\n\n");
	printf("                 PRESS-->[C] FOR CREATE CONTACT.\n");
	printf("                 PRESS-->[S] FOR SEARCH CONTACT.\n");
	printf("                 PRESS-->[D] FOR DELETE CONTACT.\n");
	printf("                 PRESS-->[V] FOR VIEW ALL CONTACT.\n");
	printf("                 PRESS-->[E] FOR EXIT.\n\n");
	printf("                 ENTER YOUR CHOICE : ");
}
