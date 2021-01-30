#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 5
int cq[max];
int rear=-1;
int front=-1;
void add();
void delet();
void display();
void main()
{
	int ch;
	do
	{
		printf("\n1.insert\n2.delete\n3.display\n4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				add();
				display();
				break;
			case 2:
				delet();
				display();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
		}
	}while(ch!=4);
getch();
}
void add()
{
	int n;
	if((front==0&&rear==max-1)||(front==rear+1))
	{
		printf("circular q overflow");
		return;
	}
	else if(front==-1)
	{
		front=0;
		rear=0;
	}
	else if(rear==max-1)
	{
		rear=0;
	}
	else
		rear++;
	printf("enter data to insert");
	scanf("%d",&n);
	cq[rear]=n;
}
void delet()
{
	if(front==-1)
	{
		printf("cq underflow");
		return;
	}
	else
	{
		printf("%d deleted",cq[front]);
		cq[front]=0;
	}
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(front==max-1)
	{
		front=0;
	}
	else
		front++;
}

void display()
{
	int i;
	for(i=0;i<max;i++)
	{
		printf("%d",cq[i]);
	}
}