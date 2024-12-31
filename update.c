/*
NAME : MEERA SUSAN TOMMY
DATE :
DISCRIPTION :
SAMPLE INPUT :
SAMPLE OUTPUT :
*/
#include"main.h"
int update(hash *arr,lst **head2,int *flag)
{
    if((*flag) == 1)
    {
	printf("ERROR: Database already created...\n");
	return 0;
    }	
    lst *temp_lst = *head2;
    char f1[10];
    char string[200];
    printf("Enter the file name to be updated ");//arlready have saved database eg save.txt
    getchar();
    scanf("%[^\n]",f1);
    FILE *fptr = fopen(f1,"r");//file pointer to eg save.txt
    while(fscanf(fptr,"%s",string) != EOF)//takes on by one line in file save.txt
    {
	//printf("here1\n");
	if(string[0] == '#' && string[strlen(string)-1] == '#')//bignig and end ##
	{
	//printf("here2\n");
	    char *ptr = strtok(&string[1],";");//index value
	    int ind = atoi(ptr);// - 48//char to int
	    //printf("%d\n",ind);
	    mnode *newm = malloc(sizeof(mnode));
		if(newm == NULL)
		    return 0;
		//printf("//newm not null\n");
	    mnode *temp = arr[ind].link;

	    if(arr[ind].link == NULL) 	//main node does not exists  
	    {
		arr[ind].link = newm;//link b/t arr & mmain-node
		//printf("here3\n");
	    }
	    else 
	    {
		//printf("here10\n");
		//when main node already exists for an index-> traverse
		while(temp->ml != NULL)
			temp = temp->ml;//traverse till ml=null
		//printf("here10\n");
		temp->ml =  newm;//linking temp-ml wih newm
	    }

		//printf("here11\n");
	    strcpy(newm->word,strtok(NULL,";"));//copy word - main node
	    newm->fcount = atoi((strtok(NULL,";")));//- 48;//fcount - main node
	    newm->ml = NULL;
	    newm->sl = NULL;
	    snode *prev = NULL;//previous pointer to sub node
	    //printf("hr4\n");
	    for(int i=1;i<=newm->fcount;i++)
	    {
		//printf("here5\n");

		    snode *news = malloc(sizeof(snode));
		    strcpy(news->fname,strtok(NULL,";"));//fname - sib node
		    //printf("news->fnme : %s\n",news->fname);

	    if(*head2 == NULL)
	    {

		//printf("here6\n");
		lst *new_lst = malloc(sizeof(lst));
		if(new_lst == NULL)
		    return 0;
		else
		{
		//printf("`ere9\n");
			*head2 = new_lst;
			//printf("`ere9\n");
			strcpy(new_lst->fname,news->fname);   //segmentation fault
			//printf("new_lst: %s\n",new_lst->fname);
			//printf("`ere9\n");
			temp_lst = new_lst;
			new_lst->link = NULL;
			//printf("`ere9\n");
		}
	    }
	    else if(strcmp(temp_lst->fname,news->fname))
	    {
		//printf("here7\n");
		lst *new_lst = malloc(sizeof(lst));
		temp_lst->link = new_lst;
		temp_lst = new_lst;
		strcpy(new_lst->fname,news->fname);
		new_lst->link = NULL;
	    }
		//printf("here8\n");

		    news->wcount = atoi((strtok(NULL,";")));// - 48; //wcount -  sub node
		    news->sl = NULL;
		    if(newm->sl == NULL)	//if 1st subnode??
			newm->sl = news;//update main node sub link
		    else// not first sub node 
			prev->sl = news;
		    prev = news;
	    }
	}
	else
	{
	    printf("ERROR: file lines doesnot bigin or end with #\n");
	    return 0;//does not begin or end with #
	}
    }
    return 1;//success
}

