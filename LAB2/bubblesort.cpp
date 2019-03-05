#include<stdio.h>
#include<stdlib.h>
typedef struct node_tag{
	int data;
	struct node_tag *next;
	}node_type;

node_type *createlist(int n);
node_type *bubblesort(node_type *lptr);
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
	

	lptr = bubblesort(lptr);
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
node_type *bubblesort(node_type *lptr)
{
	node_type *nptr, *sptr, *end;
	int temp;
	sptr = lptr;
	nptr = lptr;
	temp = NULL;
	end = NULL;
	
	while(end!=sptr)
	{
		
		
			nptr = lptr;
			while(nptr->next!= end)
			{		
					if(nptr->data > (nptr->next)->data)
					{
						temp = nptr->next->data;
						 nptr->next->data = nptr->data;
						nptr->data = temp;
					}
					
					
					nptr = nptr->next;
					
				
			}
			end = nptr;
			
	}
	return lptr;
}
void display(node_type *lptr)
{
	node_type *temp;
	temp = lptr;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}

}
