#include<stdio.h>
#include<conio.h>
#define max 30
void main()
{
	int a[max],i,j,k,n,temp,xchange;
	clrscr();
	printf("enter number of elements");
	scanf("%d",&n);
	printf("\nenter elements");
	for(i=0;i<n;i++)
	{
		scanf("\n%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		xchange=0;
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				xchange++;
			}
		}
	}


	for(i=0;i<n;i++)
	{
		printf("\n%d",a[i]);
	}
	getch();
}