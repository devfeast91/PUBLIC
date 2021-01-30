#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int data;
	struct node *right;
	struct node *left;
};
struct node *first;
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
		printf("\n1.addbegin\n2.addlast\n3.addspeci\n4.delete\n5.display\n6.exit");
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
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nenter data");
	scanf("%d",&newnode->data);
	newnode->left=NULL;
	newnode->right=first;
	first->left=newnode;
	first=newnode;
}
void addlast()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nenter data");
	scanf("%d",&newnode->data);
	newnode->right=NULL;
	if(first==NULL)
		first=newnode;
	else
	{
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp=first;
		while(temp->right!=NULL)
		{
			temp=temp->right;
		}
		temp->right=newnode;
		newnode->left=temp;
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
	if(newnode->data<=first->data)
	{
		newnode->right=first;
		first->left=newnode;
		first=newnode;
	}
	else
	{
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp=first;
		while(temp->right!=NULL&&(temp->right)->data<=newnode->data)
		{
			temp=temp->right;
		}
		newnode->right=temp->right;
		newnode->left=temp;
	      //	(temp->right)->left=newnode;
		temp->right=newnode;
	}
}
void delet()
{
	int input;
	printf("\nenter data to delete");
	scanf("%d",&input);
	if(first==NULL)
		printf("linklist is empty");
	if(first->data==input)
	{
		struct node *temp;
		temp=first;
		first=first->right;
		free(temp);
	}
	else
	{
		struct node *prev;
		struct node *temp;
		prev=first;
		temp=first->right;
		while(temp->data!=input&&temp->right!=NULL)
		{
			temp=temp->right;
			prev=temp;
		}
		if(temp->data!=input)
		{
			printf("no data found");
		}
		else
		{
		prev->right=temp->right;
		(temp->right)->left=prev;
		free(temp);
		}
	}
}
void display()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp=first;
	while(temp!=NULL)
	{
		printf("%d|%d|%d|<==>",temp->left,temp->data,temp->right);
		temp=temp->right;
	}
}