#include<stdio.h>
#include<conio.h>
#define max 30
void main()
{
	int n,i,search,a[max];
	clrscr();
	printf("enter the no of elements:=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("[%d]=",i);
		scanf("%d",&a[i]);
	}
	printf("enter element for search");
	scanf("%d",&search);
	for(i=0;i<n;i++)
	{
		if(a[i] == search)
		{
		       printf("element found on %d position",i+1);
		       break;

		}
	}
	if(i==n)
	printf("not found");
	getch();
}