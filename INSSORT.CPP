#include<stdio.h>
#include<conio.h>
#define max 30
void main()
{
	int i,j=0,count=0,no,n,a[max],k;
	clrscr();
	printf("enter no of elements");
	scanf("%d",&n);
	while(count<n)
	{
		printf("enter element");
		scanf("%d",&no);
		count++;
		i=j-1;
		while(no<a[i]&&i>=0)
		{
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=no;
		j++;
		for(i=0;i<count;i++)
		{
			printf("%d",a[i]);
		}
	}
	getch();
}