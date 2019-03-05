 #include<stdio.h>
 #include<stdlib.h>
 typedef struct dl_node_tag{
 		 
 		 int data;
 		 struct dl_node_tag *prev;
 		struct dl_node_tag *next;
 } dl_node;
  dl_node *createlist(int n);
  dl_node *reverse(dl_node *lptr);
  void display(dl_node *lptr);
 int main()
 {
 	int n,k;
 	dl_node *lptr;
 	lptr = NULL;
 	printf("enter no. of node");
 	scanf("%d",&n);
 	lptr = createlist(n);
 	display(lptr);
 	printf("\n");
 	lptr = reverse(lptr);
	display(lptr);
	return 0;
 }
 
 dl_node *createlist(int n)
 {
 	dl_node *nptr, *lptr, *temp;
 	int i, data;
 	lptr = NULL;
 	for(i=0;i<n;i++)
 	{
 		nptr = (dl_node*)malloc(sizeof(dl_node));
 		printf("enter data");
 		scanf("%d",&data);
 		nptr->data = data;
 		nptr->prev = NULL;
 		nptr->next = NULL;
 		
 		if(lptr == NULL)
 		{
 			lptr = nptr;
		 }
		else
		{
			 temp = lptr;
			 while(temp->next!=NULL)
			 {
			 	temp = temp->next;
			 }
			temp->next = nptr;
			nptr->prev = temp;
		}
	 }
	 return lptr;
 }
 
 
 void display(dl_node *lptr)
 {
 	dl_node *temp;
 	temp = lptr;
 	while(temp!=NULL)
 	{
	 
 	printf("%d\t",temp->data);
 	temp = temp->next;
   }
 }
dl_node *reverse(dl_node *lptr)
{
	dl_node *nptr, *temp;
	nptr = lptr;
	temp = NULL;
	
	while(nptr->next!=NULL)
	{
		temp = nptr->next;
		nptr->next = nptr->prev;
		nptr->prev = temp;
		nptr = temp;
	}
	nptr->next = nptr->prev;
	lptr = nptr;
	
	if(lptr!=NULL){
	lptr->prev = NULL;
	}
	return lptr;

}
