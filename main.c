#include "inverted.h"
/*Name:Bharath J
Date:
Description:
Input:
Output:*/

int main(int argc,char*argv[])
{

    Slist *Shead=NULL,*temp;
    main_node_t *mhead[SIZE]={NULL};
    int exitloop=1,createcount=0;
    char sword[NAMELENGTH];

    if(validate_n_store_filenames(&Shead,argv,argc)==FAILURE)
    {
	printf("Pass Proper Arguments\n");
	return 0;
    }
   
    while(exitloop)
    {
	int op;
	printf("Select your choice among following options:\n");
	printf("1.CREATE DATABASE\n");
	printf("2.DISPLAY DATABASE\n");
	printf("3.UPDATE DATABASE\n");
	printf("4.SEARCH\n");
	printf("5.SAVE DATABASE\n");
	printf("Enter your choice\n");
	scanf("%d",&op);

	switch(op)
	{
	    case 1:
		if(createcount==0)
		{
		    if(create_DB(Shead, mhead)==SUCCESS)
		    {
			printf("Creation of data base for files ");
			temp=Shead;
			while(temp!=NULL)
			{
			    printf("%s ",temp->f_name);
			    temp=temp->link;
			}
			printf("is successful...\n");
			printf("\n");
			createcount=1;
		    }
		    else
		    {
			printf("FILES list is empty ,,pass some valid files to create DB\n");
		    }
		}
		else
		{
		    printf("ALREADY DATA BASE IS CREATED DO ANY OTHER OPERATION\n");
		}
		break;
	    case 2:
		if(display_DB(mhead)==SUCCESS)
		{
		    printf("Display DB is Successful\n");
		    printf("\n");
		}
		else
		{
		    printf("DATA BASE is empty \n");
		    printf("\n");
		}
		break;

	    case 3:
		printf("Enter the file to update into the database\n");
		scanf("%s",sword);
		if(update_DB(&Shead,mhead,sword)==FAILURE)
		    printf("update is unsuccessful\n");
		else
		    printf("Update Data Base is Successful\n");
		break;
	    case 4:
		printf("ENTER A WORD NEED TO SEARCH \n");
		scanf("%s",sword);
		search_DB(mhead,sword);
		printf("\n");
		break;

	    case 5:
		printf("ENTER A FILE NAME TO SAVE DATABASE\n");
		scanf("%s",sword);
		if(save_DB(mhead, sword)==SUCCESS)
		    printf("DATABASE IS SAVED\n");
		else
		    printf("UNABLE TO SAVE THE DATABASE ,,CHECK DATABASE IS CREATED ");
		printf("\n");
		break;
	    default :
		printf("INVALID INPUT\n");	  

	}
	printf("Do you want to CONTINUE Enter any integer else Enter interger 0 for EXIT\n");
	scanf("%d",&exitloop);
    }    
}
