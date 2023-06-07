#include "inverted.h"

int display_DB(main_node_t **head)
{
    int i=0;
    main_node_t *temp;

    while(head[i]==NULL)
    {
	i++;
	if(i==26){
	    return FAILURE;
	}
    }
    i=0;
    while(i<SIZE)
    {
	
	if(head[i]!=NULL)
	{
	    temp=head[i];
	    while(temp!=NULL)
	    {
        
	       printf("[%d]  %s  %d  ",i,temp->word,temp->f_count);
              
	       sub_node_t *temp1=temp->sub_link;
               

	       if(temp1==NULL)
		   printf("nulll\n");

	       for(int j=0;j<temp->f_count;j++)
	       {
	          printf("%s :%d  ",temp1->f_name,temp1->w_count);
	          temp1=temp1->link;
	       }
	       printf("\n");
	       temp=temp->link;
	       
	    }
	    i++;
	}
	else
	i++;
    }

    return SUCCESS;
}



