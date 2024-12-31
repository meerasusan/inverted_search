#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct list   //validation part
{
    char fname[20];
    struct list *link;
}lst;

typedef struct hashtable //data base - hash table
{
    int index;
    struct mainnode *link;
}hash;

typedef struct mainnode
{
    int fcount;
    char word[20];
    struct mainnode *ml;
    struct subnode *sl;
}mnode;

typedef struct subnode 
{
    int wcount;
    char fname[20];
    struct subnode *sl;
}snode;

int validate(int,char**,lst **);
int insert_last(char *,lst **);
int create(lst **,hash *,lst *,int *);//head, head2
void display(hash *);
int search(hash *);
int save(hash *);
int update(hash *,lst **,int *);//head2

