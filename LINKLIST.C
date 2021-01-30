#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int data;
	struct node *link;
};
struct node  *first,*second;
void addbegin();
void addlast();
void addspeci();
void delet();
void display();
void main()
{
	int ch;
	do
	{
		printf("\n1.addbegin\n2.addlast\n3.addspeci\n4.delete\n5.display\n6.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				addbegin();
				display();
				break;
			case 2:
				addlast();
				display();
				break;
			case 3:
				addspeci();
				display();
				break;
			case 4:
				delet();
				display();
				break;
			case 5:
				display();
				break;
			case 6:
				break;
		}
	}while(ch!=6);
	getch();
}
void addbegin()
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter data to insert");
	scanf("%d",&newnode->data);
	newnode->link=NULL;
	newnode->link=first;
	first=newnode;
}
void addlast()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data");
	scanf("%d",&newnode->data);
	newnode->link=NULL;
	if(first==NULL)
		first=newnode;
	else
	{
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp=first;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=newnode;
	}
}
void addspeci()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nenter data");
	scanf("%d",&newnode->data);
	if(first==NULL)
	{
		first=newnode;
	}
	else
		if(newnode->data<=first->data)
		{
			newnode->link=first;
			first=newnode;
		}
		else
		{
			struct node *temp;
			temp=(struct node*)malloc(sizeof(struct node));
			temp=first;
			while(temp->link!=NULL&&(temp->link)->data<=newnode->data)
			{
				temp=temp->link;
			}
			newnode->link=temp->link;
			temp->link=newnode;
		}
}
void display()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp=first;
	while(temp!=NULL)
	{
		printf("%d|%d ==>",temp->data,temp->link);
		temp=temp->link;
	}
}
void delet()
{
	int input;
	printf("enter data to delete");
	scanf("%d",&input);
	if(first==NULL)
		printf("list is empty");
	if(first->data==input)
	{
		struct node *temp;
		temp=first;
		first=first->link;
		free(temp);
	}
	else
	{
		struct node *prev;
		struct node *temp;
		prev=first;
		temp=first->link;
		while(temp->data!=input &&temp->link!=NULL)
		{
			temp=temp->link;
			prev=temp;
		}
		if(temp->data!=input)
			printf("data not found");
		else
		{
			prev->link=temp->link;
			free(temp);
		}
	}
}