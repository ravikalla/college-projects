#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void main()
{
	char s1[50],s2[30],s3[50][10],s4[10],s5[10];
	int j,k,m,n=0,e,f,a,b=0,h,c[50],p,l,d,s=0,flag;
	clrscr();
	printf("Enter the Main string\n");
	while(1)
	{
		scanf("%c",&s1[n]);
		if(s1[n]=='\n')
			break;
		n++;
	}
	printf("Enter no of substrings you want to search:\n");
	scanf("%d",&k);
	printf("enter the strings:\n");
	for(l=0;l<k;l++)
	{
		scanf("%s",s2);
		strcpy(s5,s2);
		d=0;
		m=strlen(s2);
		c[l]=hash(s2);
		strcpy(s3[l],s2);

		for(e=0;e<m;e++)
		{
			s2[e]=s1[e];
		}
		h=hash(s2);

		for(e=0;e<(n-m+1);e++)
		{
			for(j=0;j<k;j++)
			{
				if(h==c[j])
				{
					for(f=e,a=0;f<e+m;f++,a++)
						s2[a]=s1[f];
					if(strcmp(s3[j],s2)==0)
					{
						d++;
						printf("string %s is found at %d position\n",s2,e+1);
						strcpy(s4,s2);
						s=j;
						b++;
					}
				}
			}
			for(f=e+1,a=0;f<=e+m;f++,a++)
				s2[a]=s1[f];
			h=hash(s2);
		}
		if(d>1)
			printf("string %s is repeated %d times\n",s4,d);
		if(d==0)
			printf("string is %s not present\n",s5);
		c[s]=0;
	}
	if(b==0)
		printf("Sub Strings are not found in Main String\n");
	getch();
}

hash(char *s)
{
	int l=0,i,val=0;
	while(*s)
	{
		l++;
		s++;
	}
	for(i=0;i<l;i++)
    {
		s--;
		val+=(*s)*((double)pow(101,i));
	}
	return val;
}
