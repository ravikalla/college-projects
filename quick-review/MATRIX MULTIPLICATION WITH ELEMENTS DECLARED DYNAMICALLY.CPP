//Matrix multiplication of any sized matrices
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<process.h>
void main(void)
{
int **a,**b,**c,ai,aj,bi,bj,i,j,p1,q1,p2,q2;
clrscr();
printf("Enter 'ros*colums' of matrix \"A\" & 'ros*colums' of matrix \"B\":-\n   ");
scanf("%d%d%d%d",&ai,&aj,&bi,&bj);
if(aj!=bi)
{
printf("F A T A L   E R R O R   ---------->can't be multiplied");
getch();
exit(0);
}
a=(int**)malloc(ai);
	for(i=0;i<ai;i++)
	*(a+i)=(int*)malloc(aj*2);

b=(int**)malloc(bi);
	for(i=0;i<bi;i++)
	*(b+i)=(int*)malloc(bj*2);
c=(int**)malloc(ai);
	for(i=0;i<ai;i++)
	*(c+i)=(int*)malloc(bj*2);
printf("Enter values for matrix \"A\":-\n   ");
	for(i=0;i<ai;i++)
	{
	for(j=0;j<aj;j++)
	{
	scanf("%d",&a[i][j]);
	}
	printf("\n   ");
	}
printf("\nEnter values for matrix \"B\":-\n   ");
	for(i=0;i<bi;i++)
	{
	for(j=0;j<bj;j++)
	{
	scanf("%d",&b[i][j]);
	}
	printf("\n   ");
	}

	for(i=0;i<ai;i++)
	{
		for(j=0;j<bj;j++)
		{
		c[i][j]=0;
			for(p2=0,q1=0;p2<aj&&q1<bi;p2++,q1++)
			c[i][j]=c[i][j]+a[i][p2]*b[q1][j];
		}
	 }
printf("Values of matrix\"A\":-\n   ");
 for(i=0;i<ai;i++)
 {
	for(j=0;j<aj;j++)
	printf("  %d",a[i][j]);
 printf("\n   ");
 }

printf("Values of matrix\"B\":-:-\n   ");
 for(i=0;i<bi;i++)
 {
	for(j=0;j<bj;j++)
	printf("  %d",b[i][j]);
printf("\n   ");
}

printf("Product of elements of two given arrays is:-\n   ");
 for(i=0;i<ai;i++)
 {
	for(j=0;j<bj;j++)
	printf("  %d",c[i][j]);
 printf("\n   ");
 }
getch();
}

