#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
struct node{
	int data;//holds the actual data
	struct node *next; //self referential structure
};
struct node*header;
struct node* getNode(int data)
{
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\nMemory Allocation Failed.");
		exit(0);
	}
	ptr->data=data;
	ptr->next=NULL;
	return ptr;
}
void InsertAtFront()
{
	int data;
	struct node *ptrnew;
	printf("\nEnter a number:");
	scanf("%d",&data);
	ptrnew=getNode(data);
	if(header==NULL)
	{
		header=ptrnew;
	}
	else
	{
		ptrnew->next=header;
		header=ptrnew;
	}
	printf("\nNode inserted at front.");
}
void InsertAtEnd()
{
	int data;
	struct node *ptrnew, *ptr;
	printf("\nEnter a number:");
	scanf("%d",&data);
	ptrnew=getNode(data);
	if(header==NULL)
	{
		header=ptrnew;
	}
	else
	{
		for(ptr=header;ptr->next!=NULL;ptr=ptr->next);
		ptr->next=ptrnew;
	}
	printf("\nNode inserted at end.");
}
void InsertBefore()
{
		int data,key;
	struct node *ptrnew, *ptr,*ptrback;
	printf("\nEnter a number before which you wanna insert a node:");
	scanf("%d",&key);
	for(ptr=ptrback=header;ptr!=NULL;ptrback=ptr,ptr=ptr->next)
	{
		if(ptr->data==key)
		{
			printf("\nEnter a number:");
		    scanf("%d",&data);
		    ptrnew=getNode(data);
		    ptrnew->next=ptr;
		    if(ptr==ptrback)
		    {
		    	header=ptrnew;
			}
			else
			{
				ptrback->next=ptrnew;
			}
		    printf("\n%d is inserted before %d.",data,key);
		    return;
		}
		printf("\nNo node exists with key %d",key);
	}
}
void InsertAfter()
{
	int data,key;
	struct node *ptrnew, *ptr;
	printf("\nEnter a number after which you wanna insert a node:");
	scanf("%d",&key);
	for(ptr=header;ptr!=NULL;ptr=ptr->next)
	{
		if(ptr->data==key)
		{
			printf("\nEnter a number:");
		    scanf("%d",&data);
		    ptrnew=getNode(data);
		    ptrnew->next=ptr->next;
		    ptr->next=ptrnew;
		    printf("\n%d is inserted after %d.",data,key);
		    return;
		}
	}
	printf("\nNo node exists with key %d",key);
}
void RemoveFromFront()
{
	struct node *ptr;
	if(header==NULL)
	{
		printf("List is empty.");
	}
	else
	{
		ptr=header;
		header=header->next;
		free(ptr);
		printf("\nNode removed from front.");
	}
}
void RemoveFromEnd()
{
	struct node *ptr, *ptrback;
	if(header==NULL)
	{
		printf("List is empty.");
	}
	else
	{
		for(ptr=ptrback=header;ptr->next!=NULL;ptrback=ptr,ptr=ptr->next);
		if(ptrback==ptr)
		header=NULL;
		else
		ptrback->next=NULL;
		free(ptr);
		printf("\nLast Node removed from the list.");
	}	
}
void RemoveAny()
{
	int key;
	struct node *ptr, *ptrback;
	if(header==NULL)
	{
		printf("List is empty.");
	}
	else
	{
		printf("Enter a number you wanna remove:");
		scanf("%d",&key);
		for(ptr=ptrback=header;ptr!=NULL;ptrback=ptr,ptr=ptr->next)
		{
			if(ptr->data=key)
			{
				header=header->next;
			}
			else
			{
				ptrback->next=ptr->next;
			}
			free(ptr);
			return;
		}
	}
	printf("\nNode with key %d does not exist in the list.",key);
}
void Display()
{
	struct node*ptr;
	if(header==NULL)
	{
		printf("\nList is empty.");
	}
	else
	{
		printf("\nList contains:");
		for(ptr=header;ptr!=NULL;ptr=ptr->next)
		{
			printf("%d\t",ptr->data);
		}
	}
}
void main()
{
	header=NULL; //initialize empty list
	char choice;
	do{
		system("CLS");
		printf("\nSelect an option:\n1.Insert at front.\n2.Insert at end.\n3.Insert Before.\n4.Insert After.\n5.Remove from front.\n6.Remove from end.\n7.Remove any.\n8.Display all.\n9.Exit.\n\nEnter your choice:");
		choice=getchar();
		switch(choice)
		{
			case'1':InsertAtFront();break;
			case'2':InsertAtEnd();break;
			case'3':InsertBefore();break;
			case'4':InsertAfter();break;
			case'5':RemoveFromFront();break;
			case'6':RemoveFromEnd();break;
			case'7':RemoveAny();break;
			case'8':Display();break;
			case'9':return;
		}
		getch();
	}while(TRUE);
	
}
