/*	What is the maximum square with no trees in it
	that can be obtained in a given rectangular
	field with trees at integral coordinates in the
	field */

#include<conio.h>
#include<stdio.h>
void main()
{	int i[31][31],x,y,x1,y1,x2,y2,lt,lt1,L,X,Y,X1,Y1,w;
	X=Y=X1=Y1=100;
	L=0;
	printf("\nEnter lt. of side of field:");
	scanf("%d",&lt);
	for(x=0;x<=31;x++)
		for(y=0;y<=31;y++)
			i[y][x]=1;
	for(x=0;x<=lt;x++)
		for(y=0;y<=lt;y++)
			i[y][x]=0;
	printf("(min=0 & max=20 & end=100)\n");
	do
	{   printf("Enter (x,y) coordinates of a tree:");
		scanf("%d %d",&x1,&y1);
		if(x1<=lt && y1<=lt)
			i[y][x]=1;
	}while(x1<=lt && y1<=lt);
	for(x=0;x<lt;x++)
	{	for(y=0;y<lt;y++)
		{   w=0;
			for(lt1=2;(x+lt1)<=lt && (y+lt1)<=lt;lt1++)
			{	x1=(x+lt1);
				y1=(y+lt1);
				for(x2=x+1;x2<x1;x2++)
				{	for(y2=y+1;y2<y1;y2++)
					{	if(i[y2][x2]==1)
						{	w=1;
							break;
						}
					}
					if(w==1)
						break;
				}
				if(w==0 && lt1>L)
				{	L=lt1;
					X=x;
					Y=y;
					X1=x1;
					Y1=y1;
					printf("%d %d %d %d\n",X,Y,X1,Y1);
					getch();
				}
				else if(w==1)
					break;
			}
			if(w==1)
				break;
		}
	}
	if(L==1)
	{	X=Y=0;
		X1=Y1=1;
	}
	printf("maximum square is \nx1 = %d\ny1 = %d\nx2 = %d\ny2 = %d\nlength = %d",X,Y,X1,Y1,L);
	getch();
}
