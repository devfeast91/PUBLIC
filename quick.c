#include<stdio.h>
#include<conio.h>
int k,us_arr[5];
void Q_Sort(int arr[],int first, int last)
{
int temp,i,j,pivot;
i=first;
j=last;
pivot=arr[(first+last)/2];
do
{
while(arr[i]<pivot)
i++;
while(arr[j]>pivot)
j--;
if(i<=j)
{
temp=arr[i];
arr[i++]=arr[j];
arr[j]=temp;
}
}while(i<=j);
if(first<j)
Q_Sort(arr,first,j);
if(i<last)
Q_Sort(arr,i,last);
}
void main(void)
{
clrscr();
printf("\n\n\tEnter Elements to SORT using QUICK SORT");
for(k=0;k<5;k++)
{
printf("\n\t\t[%d] = ",k);
scanf("%d",&us_arr[k]);
}
Q_Sort(us_arr,0,4);
printf("\n\n\tSorted Elements Using Quick Sort: \n");
for(k=0;k<5;k++)
{
printf("\n\t\t[%d] = %d",k,us_arr[k]);
}
getch();
}