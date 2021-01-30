#include<stdio.h>
#include<conio.h>
#define max 30
int binary(int a[],int l, int r , int x)
{
	if(r>=1)
	{
		int mid=l+(r-1)/2;

	if(a[mid]==x)
		return mid;
	if(a[mid]>x)
		return binary(a,l,mid-1,x);
	return binary(a,mid+1,r,x);
	}
	return -1;
}
void main()
{
	int a[max], i,n,result,search;
	printf("enter no of elements:=");
	scanf("%d",&n);
	printf("enter elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter element for search");
	scanf("%d",&search);
	result=binary(a,0,n-1,search);
	if(result==-1)
		printf("element not found");
	else
		printf("element found on %d",result+1);
	getch();
}