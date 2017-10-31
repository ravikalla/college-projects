/*What is the power of 7 which gives the
result with LSB digits same as pow(7,7)
*/
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
int num[7];
int temp;
void main()
{	unsigned long int i,j;
	clrscr();
	for(i=8;!kbhit();i++)
	{	num[0]=1;
		num[1]=num[2]=num[3]=num[4]=num[5]=0;
		for(j=0;j<i;j++)
		{   temp=num[0]*7;
			num[0]=temp%10;
			temp=num[1]*7+temp/10;
			num[1]=temp%10;
			temp=num[2]*7+temp/10;
			num[2]=temp%10;
			temp=num[3]*7+temp/10;
			num[3]=temp%10;
			temp=num[4]*7+temp/10;
			num[4]=temp%10;
			temp=num[5]*7+temp/10;
			num[5]=temp%10;
		}
		if(num[0]==3 && num[1]==4 && num[2]==5 && num[3]==3 && num[4]==2 && num[5]==8)
		{	cout<<"pow is : "<<i;
			exit(0);
		}
	}
}