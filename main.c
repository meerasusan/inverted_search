/*
NAME : MEERA SUSAN TOMMY
DATE :
DISCRIPTION :
SAMPLE INPUT :
SAMPLE OUTPUT :
*/
#include"main.h"

int main(int argc,char *argv[])
{
    int flag=0;//update->create & not create->update
    lst *head = NULL;
    lst *head2 = NULL;
    int choice;
    char option;
    if(validate(argc,argv,&head))
	printf("validation completed\n");
    else
    {
	printf("ERROR: VALIDATION failed \n");
	return 0;
    }
    hash arr[28];
    for(int i=0;i<=27;i++)//initialising hash table
    {
	arr[i].index = i;
	arr[i].link = NULL;
    }
    do
    {
	printf("Enter our choice:\n1. Create\n2.Dispay\n3.Search\n4.Save\n5.Update\n");
	scanf("%d",&choice);

    switch(choice)
    {
	case 1://create
	    {
    		if(create(&head,arr,head2,&flag))
    		{
			printf("creation completed\n");
    		}
   		else
   		{
			printf("ERROR: CREATION failed\n");
			return 0;
    		}
		break;
	    }
	case 2://display
	    {
	    	display(arr);
	    	break;
	    }
	case 3://search
	     {
    		if(!search(arr))
			printf("Word not available\n");
		break;
	     }
	case 4://save
	     {
		if( save(arr))
		    printf("SAVED SUCCESSFULLY\n");
		else
		    printf("ERROR: the file is not in .txt format\n");
		 break;
	     }
	case 5://update
	     {
		 if(update(arr,&head2,&flag))
		     printf("UPDATE SUCCESSFUL\n");
		 break;
	     }
    }//switch closing
    printf("Do you want to continue: y/n ");
    getchar();
    scanf("%c",&option);
    }while(option == 'y');//do-while closing
}

