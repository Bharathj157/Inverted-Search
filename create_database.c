#include "inverted.h"

int create_DB(Slist *file_head, main_node_t **head)
{
    if(file_head==NULL)
	return FAILURE;

    while (file_head != NULL)		
    {
	read_datafile (file_head, head,file_head->f_name);	

	file_head = file_head->link;
    }

}

void read_datafile(Slist *Shead, main_node_t **mhead, char *f_name)
{
    int exitloop=1,key,flag=0;
    char buffer[BUFF_SIZE];

    FILE* fptr = fopen (f_name, "r");

    fseek (fptr, 0, SEEK_SET);

    while(exitloop)
    {
	//printf("first while\n");
	exitloop=fscanf(fptr,"%s",buffer);
//	printf("%s\n",buffer);
	if(exitloop>0)
	{
	    key=toupper(buffer[0])-65;

	  //  printf("%d\n",key);

	    if(mhead[key]==NULL)
	    {
	//	printf("when nukk\n");
		main_node_t *new=malloc(sizeof(main_node_t));
		strcpy(new->word,buffer);
		new->link=NULL;
		new->sub_link=NULL;
		new->f_count=1;

		sub_node_t *snew=malloc(sizeof(sub_node_t));
		strcpy(snew->f_name,f_name);
		snew->w_count=1;
		snew->link=NULL;

		new->sub_link=snew;
		mhead[key]=new;
	    }
	    else
	    {
	//	printf("when not null\n");
		main_node_t *temp=mhead[key],*prev;
		while(temp!=NULL)
		{
	//	    printf("inside while\n");
		    if(strcmp(temp->word,buffer)==0)
		    {
			sub_node_t *temp1=temp->sub_link,*prev1;
			while(temp1!=NULL)
			{
			    prev1=temp1;
			    if(strcmp(temp1->f_name,f_name)==0)
			    {
				temp1->w_count++;
				flag=1;
				break;
			    }
			    temp1=temp1->link;
			}

	//		printf("outside 2nd while\n");
			if(flag==0)
			{
			    sub_node_t *snew=malloc(sizeof(sub_node_t));
			    strcpy(snew->f_name,f_name);
			    snew->w_count=1;
			    snew->link=NULL;

			    temp->f_count++;
			    prev1->link=snew;
			    break;
			}
			else
			{
			    break;
			
			}

		    }
		    prev=temp;
		    temp=temp->link;
		}
	//	printf("outside while\n");
		if(temp==NULL)
		{
		    main_node_t *new=malloc(sizeof(main_node_t));
		    strcpy(new->word,buffer);
		    new->link=NULL;
		    new->sub_link=NULL;
		    new->f_count=1;

		    sub_node_t *snew=malloc(sizeof(sub_node_t));
		    strcpy(snew->f_name,f_name);
		    snew->w_count=1;
		    snew->link=NULL;

		    new->sub_link=snew;
		    prev->link=new;
		}
		
	//	printf("at the end\n");
	    }

	}
	else
	{
	    break;
	}
    }
//    printf("one file complte\n");
}
