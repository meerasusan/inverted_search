/*
NAME : MEERA SUSAN TOMMY
DATE :
DISCRIPTION :
SAMPLE INPUT :
SAMPLE OUTPUT :
*/
#include"main.h"
int create(lst **head,hash *arr,lst *head2,int *flag)
{
    *flag = 1;//if control enters create function
    if(head2 != NULL && *head != NULL)//head2 contains list
    {
	lst *temp1 = *head;//traverse through original lst
	lst *prev1 = NULL;
	lst *temp2 = head2;//traverse hroyugh
	while(temp2)
	{
	    while(temp1)
	    {
		if(strcmp(temp1->fname,temp2->fname)== 0 && temp1 == *head)//fname are same & head-> 1st node
		{
		    *head = (*head)->link;   //delete node
		    free(temp1);
		    temp1 = *head;
		}
		else if(strcmp(temp1->fname,temp2->fname)==0)// fname same but not first node
		{
		    prev1->link  = temp1->link;         //delete node
		    free(temp1);
		    temp1 = prev1->link;
		}
		else  // fname diffrent
		{
		    prev1 = temp1;      //traverse prev1 & temp1
		    temp1 = temp1->link;
		}
	    }
	    //when temp1 reaches NULL
	    temp2 = temp2->link;  //traverse head2
	    temp1 = *head; // update temp1
	}
    }
    char wrd[20];
//initialisig hash table

/*
	lst *temp = *head;//printing head
	while(temp)
	{
	    printf("%s -> ",temp->fname);
	    temp = temp->link;
	}
	printf("NULL\n");
	*/


     lst *temp = *head;
    while(temp)//traversing through lst
    {    
	FILE *ptr = fopen(temp->fname,"r");
	while(fscanf(ptr,"%s",wrd) != EOF)//scaning each word in a file
	{
		//printf("%s\n",wrd);//cmd this
		int ind = toupper(wrd[0])%65;  //finding index
		if(ind>=48 && ind<=57)
		    ind = 27;//index of numbers
		else if(ind>=33 && ind<=64)
		    ind = 26;//index of special characters
		if(arr[ind].link == NULL)// hash link-null
		{
		    snode *news = malloc(sizeof(snode));//new sub-node
		    news->sl = NULL;
		    news->wcount = 1;
		    strcpy(news->fname,temp->fname);

			mnode *newm = malloc(sizeof(mnode));//new main-node
			arr[ind].link  = newm;
			newm->fcount = 1;
			strcpy(newm->word,wrd);
			newm->ml = NULL;
			newm->sl = news;
		}
		else
		{
		    mnode *temp_mn = arr[ind].link;//temp to main-node = hashlink
		    while(temp_mn)
		    {	  
			    int op_word = strcmp(wrd,temp_mn->word);//o/p of compare word

			    if(!op_word)//when words match
			    {
				snode *temp_sn = temp_mn->sl;//temp subnode = main-node->sublink
				while(temp_sn)
				{
				    int op_flnm = strcmp(temp->fname,temp_sn->fname);
				    if(op_flnm !=0 && temp_sn->sl == NULL)//none of file name matched & reached the end
				    {
					//create node and update main-node fcount
					snode *news = malloc(sizeof(snode));
					temp_sn->sl = news;//linking to the temp sub-node
					news->sl = NULL;//this is current last node
					news->wcount = 1;
					strcpy(news->fname,temp->fname);
					(temp_mn->fcount)++;//inc main-node fcount
					break; //from temp_sn
				    }
				    if(!op_flnm)//filenames match
				    {
					(temp_sn->wcount)++;
					break;// from temp_sn
				    }
				    else if(op_flnm)//filenames does not match
					temp_sn = temp_sn->sl;
				}
				break;//from temp_mn
			    }
			    else if(op_word != 0 && temp_mn->ml == NULL)//still last no matching word is found
			    {	
		    		snode *news = malloc(sizeof(snode));//new sub-node
		    		news->sl = NULL;
		    		news->wcount = 1;
		    		strcpy(news->fname,temp->fname);

				mnode *newm = malloc(sizeof(mnode));//new main-node
				temp_mn->ml  = newm;
				newm->fcount = 1;
				strcpy(newm->word,wrd);
				newm->ml = NULL;
				newm->sl = news;
				break;//from temp_mn
			    }
			    else if(op_word)//words not same - travers
				temp_mn = temp_mn->ml;
		    }
		}
	}
	printf("Database created SUCCESSFULY for %s\n",temp->fname);
	temp = temp->link;
    }
    return 1;
}
