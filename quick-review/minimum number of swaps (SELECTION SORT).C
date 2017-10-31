/*An array contains 5 occurences of 0s,
9 occurences of 1s and 6 occurences
of 2s in any order. The array is to
be sorted using only swap operations.
What is the minimum number of swaps
needed in the worst case to sort the array?
*/
void print_list(int[],int);
void swap(int *,int *);
int count=0;
void main()
{//   int a[]={2,2,2,2,2,2,1,1,1,1,1,1,1,0,1,1,0,0,0,0};
	int a[]={0,0,0,0,0,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2};
	int i,j,temp,k;
	clrscr();
	for(i=0;i<19;i++)
	{   temp=a[i];
		k=i;
		for(j=i;j<20;j++)
		{	if(a[j]>temp)
			{	temp=a[j];
				k=j;
			}
		}
		if(a[i]<temp)
			swap(&a[i],&a[k]);
	}
	print_list(a,20);
	printf("\ncount is %d",count);
	getch();
}
void print_list(int y[],int n)
{	int i;
	for(i=0;i<n;i++)
		printf("%2d",y[i]);
	printf("\n");
}
void swap(int * a,int * b)
{	int t;
	count++;
	t=*a;
	*a=*b;
	*b=t;
}