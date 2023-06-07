#include"inverted.h"
/*Name:Bharath J
Date:
Description:
Input:
Output:*/
int insert_at_first(Slist **head, char * data)
{
	/* Creating the new node */
	Slist *new = malloc(sizeof(Slist));

	/* Check whether new node created or not */
	if (new == NULL)
	{
		return FAILURE;
	}

	/* Fill the parts of the node */
	strcpy(new->f_name,data);
	new->link = NULL;

	/* If list is empty */
	if (*head == NULL)
	{
		/*If *head is empty then create the first node */
		*head = new;
		return SUCCESS;
	}
	else
	{
		/* *head is not empty then store value i.e link in the temp variable */
		Slist *temp = *head;

		/* Stroring that new link in the head inserting the element at first */
		*head = new;

		/* Creating the link to next data */
		new -> link = temp;
	}
		
	return SUCCESS;
}

int validate_n_store_filenames(Slist **head, char *filenames[],int argc)
{
    int check;

    if(argc < 2)
	return FAILURE;

     for(int i=1;i<argc;i++)
     {
         check=IsFileValid(filenames[i]);

	 if(check==NOT_PRESENT)
	     return FAILURE;
         else if(check==FAILURE)
	 {
	 
	 }
	 else
	     store_filenames_to_list(filenames[i],head);
         	     
     }
     return SUCCESS;	

}


int IsFileValid (char* filename)
{
	FILE* fptr = fopen(filename, "r");
	if (fptr == NULL)	
	{
		printf ("ERROR: The File %s is not present plz check the File ",filename);
		return NOT_PRESENT;
	}
	else 
	{
	    fseek(fptr,0,SEEK_SET);
	    int set=ftell(fptr);
	    fseek(fptr,0,SEEK_END);
	    int end=ftell(fptr);
            
	    if(set==end)
	    {
		return FAILURE;
	    }
	    else
	        return SUCCESS;
	}
}


int store_filenames_to_list(char *f_name, Slist **head)
{
    int flag=0;
    Slist *temp;
	if(head==NULL)
	{
	    insert_at_first(head,f_name);
	}
	else
	{
	    temp=*head;
	    while(temp!=NULL)
	    {
               if(!strcmp(temp->f_name,f_name))
	       {

                 flag=1;
		 break;
	       }

	       temp=temp->link;
	    }
	    if(flag==0)
		insert_at_first(head,f_name);
	}
}

