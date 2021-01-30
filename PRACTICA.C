#include<stdio.h>
#include<conio.h>
int top=-1;
#define max 5
int stack[max];
void push(int x);
void pop();
void peep();
void display();
void main()
{

	int ch,data;
	clrscr();
	do
	{
		printf("\n1.push\n2.pop\n3.peep\n4.display");
		printf("\nenter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		     {
			case 1:

				printf("\nenter data for push: ");
				scanf("%d",&data);

				push(data);
				display();
				break;

			case 2:

				pop();
				display();
				break;

			case 3:

				peep();
				break;

			case 4:

				display();
				break;

			case 5:
				break;
		     }
		}
	while (ch!=5);
	getch();
}
void push(int x)
{
	if(top==max-1)
	{
		printf("\nstack overflow");
	}
	else
	{
		top=top+1;
		stack[top]=x;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("stack underflow");
	}
	else
	{
		printf("%d deleted",stack[top]);
		top=top-1;
	}
}
void peep()
{
	int i,ele;
	int flag=0;
	printf("enter element for peep");
	scanf("%d",&ele);
	for(i=0;i<=top;i++)
	{
		if(stack[i]==ele)
		{
			printf("%d found on %d",ele,i);
			break;

		}

	}

}
void display()
{
	int i;
	if(top==-1)
	{
		printf("\nstack is empty");
	}
	else
	{
		printf("\nstack is");
		for(i=top;i>=0;i--)
		{
			printf("\n%d",stack[i]);
		}
	 }
}