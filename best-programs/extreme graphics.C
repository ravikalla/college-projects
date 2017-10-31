/*this program is written by K.V.V.N.Ravi Shankar*/
/*GAYATRI COLLEGE OF ENGINEERING(III/IV-cse)*/
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<conio.h>

struct a
{
	int x,y,z;
}d;

void main()
{
	struct a b;
	struct a find(float,float,float);
	static int i1,j;
	float x,y,z;
	double sqr(double);
	double i=50;
	static int speed=2,x1=100,y1=100,z1=100;
	static char ax='a',ay='a',az='a',ai='a',color=2;


	detectgraph(&i1,&j);
	initgraph(&i1,&j,"c:\\tc\\bgi");
	cleardevice();

	while(!kbhit())
	{
		if(ax=='a')
		{
			x1+=speed;
			if(x1>=540)
				ax='b';
		}
		else if(ax=='b')
		{
			x1-=speed;
			if(x1<=100)
				ax='a';
		}
		if(ay=='a')
		{
			y1+=speed;
			if(y1>=380)
				ay='b';
		}
		else if(ay=='b')
		{
			y1-=speed;
			if(y1<=100)
				ay='a';
		}
		if(az=='a')
		{
			z1+=speed;
			if(z1>=240)
				az='b';
		}
		else if(az=='b')
		{
			z1-=speed;
			if(z1<=-240)
				az='a';
		}
		delay(10);
		cleardevice();
		for(x=-i;x<=i;x+=10)
		{
			for(y=-i;y<=i;y+=10)
			{
				z=sqrt(160000-x*x-y*y);
				b=find(x1+x,y1+y,z1+z);
				putpixel(b.x,b.y,color);
			}
		}
		if(ai=='a')
		{
			i++;
			if(i==250)
				ai='b';
		}
		else
		{
			i--;
			if(i==50)
				ai='a';
		}
	}
	getch();
}

struct a find(float x1,float y1,float z1)
{
	if(z1<=240*3)
	{
		d.x=320+x1*(240-z1)/(240);
		d.y=240-y1*(240-z1)/(240);
	}
	else
	{
		d.x=d.y=0;
	}

	d.z=z1;
	return d;
}
/*this program is written by K.V.V.N.Ravi Shankar*/
/*GAYATRI COLLEGE OF ENGINEERING(III/IV-CSE)*/