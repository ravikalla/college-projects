#include<stdio.h>
main()
{
	char c[5]={'a','b','c','d','e'};
	char temp[6];
	int i1,i2,i3,i4,i5;
	FILE *f=fopen("1.txt","w");
	for(i1=0;i1<5;i1++)
	{
		temp[0]=c[i1];
		for(i2=0;i2<5;i2++)
		{
			temp[1]=c[i2];
			for(i3=0;i3<5;i3++)
			{
				temp[2]=c[i3];
				for(i4=0;i4<5;i4++)
				{
					temp[3]=c[i4];
					for(i5=0;i5<5;i5++)
					{
						temp[4]=c[i5];
						temp[5]='\0';
						fprintf(f,"%s\n",temp);
					}
				}
			}
		}
	}
}
