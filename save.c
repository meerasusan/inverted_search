/*
NAME : MEERA SUSAN TOMMY
DATE :
DISCRIPTION :
SAMPLE INPUT :
SAMPLE OUTPUT :
*/
#include"main.h"
int save(hash *arr)
{
    char newf[10];
    printf("Enter the file name ");//taking new filename to save data
    getchar();
    scanf("%[^\n]",newf);
    if(strstr(newf,".txt"))//checking if it is .txt
    {
    	FILE *ptr = fopen(newf,"w");//opening in write mode
	for(int i=0;i<=27;i++)
	{
	    if(arr[i].link != NULL)//if main node present
	    {
		mnode *temp_mn = arr[i].link;
		while(temp_mn)
		{
		    fprintf(ptr,"#%d;%s;%d;",i,temp_mn->word,temp_mn->fcount);//writing to new file
		    snode *temp_sn = temp_mn->sl;
		    while(temp_sn)
		    {
			fprintf(ptr,"%s;%d;",temp_sn->fname,temp_sn->wcount);
			temp_sn = temp_sn->sl;// traversing to the next sub node
		    }
		    fprintf(ptr,"#\n");
		    temp_mn = temp_mn->ml;
		}
	    }
	}
	return 1;
    }
    else
    	return 0;//if newf is not .txt file

}

