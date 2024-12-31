/*
NAME : MEERA SUSAN TOMMY
DATE :
DISCRIPTION :
SAMPLE INPUT :
SAMPLE OUTPUT :
*/
#include"main.h"
void display(hash *arr)
{
    printf("Index\tword\tfilecount\tfilename\twordcount\n");
    for(int i=0;i<=27;i++)
    {
	if(arr[i].link!= NULL)//when index->link is not null
	{
	    mnode *temp_mn = arr[i].link;//temp mainnode to traverce
	    while(temp_mn)
	    {
		printf("[%d]\t%s\t%d\t",i,temp_mn->word,temp_mn->fcount);//index, word,fcount
		snode *temp_sn = temp_mn->sl;//temp to sub node to traverse
		while(temp_sn)
		{
		    printf("\t%s\t%d\t",temp_sn->fname,temp_sn->wcount);//filename wordcount
		    temp_sn = temp_sn->sl;//to next sub node
		}
		printf("\n");
		temp_mn = temp_mn->ml;//to next main node
	    }
	}
    }
}

