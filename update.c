#include"inverted.h"

int update_DB(Slist **shead, main_node_t **mhead, char *f_name)
{

    FILE *fptr=fopen(f_name,"r");

    if(fptr == NULL)
    {
	printf ("ERROR: Problem in file opening ,fix the bug\n");
	return FAILURE;;
    }
    else
    {
	 fseek(fptr,0,SEEK_SET);
            int set=ftell(fptr);
            fseek(fptr,0,SEEK_END);
            int end=ftell(fptr);

            if(set==end)
	    {
		printf("FILE is empty \n");
                return FAILURE;   
	    }
    }

    int i=0,key;
    while(i<26)
    {
	if(mhead[i]!=NULL){
	printf("DATA BASE NOT EMPTY\n");
	return FAILURE;
	}

	i++;
    }
    

    int exitloop=1;
    char buffer[BUFF_SIZE];

    while(exitloop)
    {
	exitloop=fscanf(fptr,"%s",buffer);

	if(exitloop==EOF)
	    break;

	char delim[] = ";#";
	char *token;
	token = strtok(buffer, delim);

	key=atoi(token);

	exitloop=fscanf(fptr,"%s",buffer);

	token=strtok(buffer, delim);

	main_node_t *temp;
	sub_node_t *prev=NULL;
	if(mhead[key]==NULL)
	{

	    main_node_t *new=malloc(sizeof(main_node_t));
	    temp=new;
	    mhead[key]=new;
	    strcpy(new->word,token);
    //	    printf("%s\n",new->word);
	    new->link=NULL;
	    new->sub_link=NULL;
	    
	    token=strtok(NULL,delim);

	    new->f_count=atoi(token);

	    for(int i=0;i<new->f_count;i++)
	    {
		token=strtok(NULL,delim);
	        sub_node_t *snew=malloc(sizeof(sub_node_t));
                
		if(prev!=NULL)
		prev->link=snew;

	        strcpy(snew->f_name,token);
	        snew->link=NULL;

	        token=strtok(NULL,delim);
	//	printf("%s\n",token);
		snew->w_count=atoi(token);

		if(i==0)
                temp->sub_link=snew;

		prev=snew;
	    }
	    
	}
	else
	{
	    temp=mhead[key];

            while(temp->link!=NULL)
	    {
		temp=temp->link;
	    }

	    main_node_t *new=malloc(sizeof(main_node_t));

            temp->link=new;
	    temp=new;
          
	    strcpy(new->word,token);
          //  printf("%s\n",new->word);
	    new->link=NULL;
	    new->sub_link=NULL;
	    
	    token=strtok(NULL,delim);

	    new->f_count=atoi(token);

	    for(int i=0;i < new->f_count;i++)
	    {
		token=strtok(NULL,delim);
	        sub_node_t *snew=malloc(sizeof(sub_node_t));
                
		if(prev!=NULL)
		prev->link=snew;

	        strcpy(snew->f_name,token);
	        snew->link=NULL;

	        token=strtok(NULL,delim);
		
		snew->w_count=atoi(token);
	//	printf("%d\n",snew->w_count);

		if(i==0)
		{
                   temp->sub_link=snew;
		}

		prev=snew;
	    }
	}

    }
    return SUCCESS;
}
