#include<stdio.h>
#include<stdlib.h>
typedef struct node_tag{
	int data;
	struct node_tag *next;
	}node_type;

node_type *createlist(int n);
node_type *merge(node_type *lptr, node_type *nptr);
void display(node_type *lptr);
int main()
{
	int n,m;
	node_type *lptr,  *nptr;
	lptr = NULL;
	nptr = NULL;
	printf("enter 1st no. of node");
	scanf("%d",&n);
	lptr = createlist(n);
	display(lptr);
	printf("\n");

	printf("enter 2st no. of node");
	scanf("%d",&m);
	nptr = createlist(m);
	display(nptr);
	printf("\n");
	

	lptr = merge(lptr, nptr);
		display(lptr);
	
	return 0;
}
node_type *createlist(int n)
{

	int i,data;
	node_type *lptr, *nptr, *p;
	lptr = NULL;
	p = NULL;
	for(i=0;i<n;i++)
	{
		nptr=(node_type*)malloc(sizeof(node_type));
		printf("enter data");
		scanf("%d",&data);
		nptr->data = data;
		nptr->next = NULL;
		if(lptr==NULL)
		{
			lptr=nptr;
		
		}
		else
		{
			p=lptr;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=nptr;
		}
	}
	return lptr;
}


void display(node_type *lptr)	
{
	node_type *p;
	p = lptr;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
}
	
node_type *merge(node_type *lptr, node_type *nptr)
{
	node_type *temp1, *temp,*sptr;
	sptr=(node_type *)malloc(sizeof(node_type));
	sptr->data=0;
	sptr->next=NULL;
	temp=sptr;
	
	while(lptr!=NULL &&  nptr!=NULL)
	{
		sptr->next=lptr;
		lptr=lptr->next;
		sptr=sptr->next;
		sptr->next=nptr;
		nptr=nptr->next;
		sptr=sptr->next;
		
	}
	if(lptr==NULL)
	{
		sptr->next=nptr;
	}
	else
	{
		sptr->next=lptr;
	}
	temp1=temp;
	temp=temp->next;
	 free(temp1);
	return temp;
}
