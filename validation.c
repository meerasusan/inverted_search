/*
NAME : MEERA SUSAN TOMMY
DATE :
DISCRIPTION :
SAMPLE INPUT :   1->SUCCESS
SAMPLE OUTPUT :  0->FAILURE
*/    
#include"main.h"

int validate(int argc, char *argv[],lst **head)
{
    if(argc>1)
    {
	for(int i=1;i<argc;i++)
	{
	    if(strstr(argv[i],".txt"))
	    {
		FILE *ptr = fopen(argv[i],"r");
		if(ptr)//if file exists
		{
		    fseek(ptr,0,SEEK_END);
		   if(ftell(ptr)>0)//file not empty
		   {
			if(insert_last(argv[i],head))	    //inserting list
			    printf("file %d inserted succesfully\n",i);
			else
			    printf("file %d is duplicte\n",i);
		   }
		   else //file empty
		       printf("ERROR: file %d is empty\n",i);
		}
		else//file does not exist
		    printf("ERROR: file %d does not exist\n",i);
	    }
	    else//when extention not .txt
	    	printf("ERROR: extention of file %d is not .txt\n",i);
	}
    }
    else//no CLA is passed
    {
	printf("ERROR: pass CLA \n");
	return 0;
    }

    //printin the current lst;
    if((*head)==NULL)
	printf("LIST EMPTY\n");
    else
    {
	lst *temp = *head;
	while(temp)
	{
	    printf("%s -> ",temp->fname);
	    temp = temp->link;
	}
	printf("NULL\n");
    }
    return 1;
}

int insert_last(char *file_name,lst **head)
{
    lst *new = malloc(sizeof(lst));
    strcpy(new->fname,file_name);
    new->link = NULL;

    if(*head == NULL)
    {
	*head = new;
	return 1;
    }

    lst *temp = *head;
    while(temp)
    {
	if(strcmp(temp->fname,file_name) == 0)
	    return 0;//duplicate failure
	if(temp->link == NULL)
	{
	    temp->link = new;
	    return 1;//success
	}
	temp = temp->link;
    }
     	  
}




