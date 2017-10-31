#include<stdio.h>
main()
{
	char c[7]={'a','b','c','d','e','f','g'};
	char temp[8];
	int i1,i2,i3,i4,i5,i6,i7;
	FILE *f=fopen("1.txt","w");
	for(i1=0;i1<7;i1++)
	{
		temp[0]=c[i1];
		for(i2=0;i2<7;i2++)
		{
			temp[1]=c[i2];
			for(i3=0;i3<7;i3++)
			{
				temp[2]=c[i3];
				for(i4=0;i4<7;i4++)
				{
					temp[3]=c[i4];
					for(i5=0;i5<7;i5++)
					{
						temp[4]=c[i5];
						for(i6=0;i6<7;i6++)
						{
							temp[5]=c[i6];
							for(i7=0;i7<7;i7++)
							{
								temp[6]=c[i7];
								temp[7]='\0';
								fprintf(f,"%s\n",temp);
							}
						}
					}
				}
			}
		}
	}
}
