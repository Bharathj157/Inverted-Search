#include"inverted.h"
int search_DB(main_node_t **head, char *word)
{
    int key;

    key=toupper(word[0])-65;

    if(head[key]!=NULL)
    {
	main_node_t *temp=head[key];
	while(temp!=NULL)
	{
	    if(strcmp(temp->word,word)==0)
	    {
		printf("[%d] %s %d files ",key,temp->word,temp->f_count);

	        sub_node_t *temp1=temp->sub_link;
	       for(int j=0;j<temp->f_count;j++)
	       {
	          printf("%s :%d  ",temp1->f_name,temp1->w_count);
	          temp1=temp1->link;
	       }
	       printf("\n");
	       break;
	    }
	    temp=temp->link;
	}

	if(temp==NULL)
	{
	    printf("DATA NOT FOUND\n");
	}

    
    }
    else
    {
	printf("DATA NOT FOUND\n");
    }

}
