#include"inverted.h"

int save_DB(main_node_t **head, char *fname)
{
    int i=0;

    while(head[i]==NULL)
    {
        i++;
        if(i==26){
            return FAILURE;
        }
    }

    i=0;
    FILE *fptr=fopen(fname,"w");

    if(fptr == NULL)
    {
	printf ("ERROR: Problem in file opening ,fix the bug\n");
	return NOT_PRESENT;
    }

    main_node_t *temp;
    while(i<SIZE)
    {
	if(head[i]!=NULL)
	{
	    temp=head[i];
	    while(temp!=NULL)
	    {
	       fprintf(fptr,"#%d;\n",i);
	       fprintf(fptr,"%s;%d;",temp->word,temp->f_count);

	       sub_node_t *temp1=temp->sub_link;
	       for(int j=0;j<temp->f_count;j++)
	       {
	          fprintf(fptr,"%s;%d;",temp1->f_name,temp1->w_count);
	          temp1=temp1->link;
	       }
	       fprintf(fptr,"#\n");
	       temp=temp->link;
	    }
	    i++;
	}
	else
	{
	    i++;
	}
    }
}
