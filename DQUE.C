#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int q[5];
int n=5;
int right=-1;
int left=-1;
int lr;
void add();
void delet();
void display();
void main()
{
	int ch;
	do
	{
		printf("\n1.add\n2.delet\n3.display\n4.exit\n");
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
	int item;
	if(left==1&&right==n-1||left==right+1)
	{
		printf("q overflow");
	}

	printf("\nenter where to enter left or right");
	flushall();
	scanf("%c",&lr);
	printf("\nenter element to insert");
	scanf("%d",&item);

	if(right==-1)
	{
		left=0;
		right=0;
		q[left]=item;
		return;
	}
	if(lr=='l')
	{
		if(left==0)
			left=n-1;
		else
			left=left-1;
		q[left]=item;
	}
	if(lr=='r')
	{
		if(right==n-1)
			right=0;
		else
			right=right+1;
		q[right]=item;
	}
}
void display()
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",q[i]);
	}
}
void delet()
{
	if(right==-1)
		printf("q is empty");
	printf("enter choice left or right");
	flushall();
	scanf("%c",&lr);
	if(lr=='r')
	{
		q[right]=0;
		if(right==0)
			right=n-1;
		else
			right=right-1;
	}
	if(lr=='l')
	{
		q[left]=0;
		if(left==n-1)
			left=0;
		else
			left=left+1;
	}
}