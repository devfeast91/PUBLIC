#include<stdio.h>
#include<conio.h>
#define max 30
void main()
{
	int a[max],i,j,k,n,temp,small;
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
		small=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[small])
			small=j;
		}
		if(small!=i)
		{
			temp=a[i];
			a[i]=a[small];
			a[small]=temp;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n%d",a[i]);
	}
	getch();
}