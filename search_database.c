/*
NAME : MEERA SUSAN TOMMY
DATE :
DISCRIPTION :
SAMPLE INPUT :
SAMPLE OUTPUT :
*/
#include"main.h"
int search(hash *arr)
{
    char wd[20];
    printf("Enter the word to be searched: ");
    getchar();
    scanf("%19[^\n]",wd);
    int ind = toupper(wd[0])%65;//findig index
    if(ind>=48 && ind<=57)//for numbers
	ind = 27;
    else if(ind>= 33 && ind<=64)//for special charactors
	ind = 26;
    if(!arr[ind].link)//link null
    	return 0;
    mnode *temp_mn = arr[ind].link;
    while(temp_mn)
    {
	if(!strcmp(wd,temp_mn->word))//word found
	{
	    printf("The word %s is present in %d files\n",wd,temp_mn->fcount);
	    snode *temp_sn = temp_mn->sl;
	    while(temp_sn)//travesing sub node
	    {
		printf("In %s for %d times\n",temp_sn->fname,temp_sn->wcount);//printing curent sub node info
		temp_sn = temp_sn->sl;//moving to next
	    }
	    return 1;
	}
	else
	    temp_mn = temp_mn->ml;//else when words dont match travese
    }
    return 0;
}
