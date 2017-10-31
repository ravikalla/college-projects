/*this program is written by K.V.V.N.Ravi Shankar*/
/*GAYATRI COLLEGE OF ENGINEERING(III/IV-cse)*/
#include<graphics.h>
#include<conio.h>
#include<dos.h>
void main(void)
{	int f,z,a=0,p=0,q=0,x=100,y=450,x1=0,y1=0,i=0;
	static char cirinc=3,rx=20,ry=10;

	detectgraph(&f,&z);
	initgraph(&f,&z,"");
	outtextxy(100,100,"Use ARROW keys to move the BAR");
	getch();
	cleardevice();
	setfillstyle(1,2);
	for(i=0;a!=13;i++)
	{	delay(1);
		circle(x1,y1,10);
		if(i==15)
		{	i=0;
			if(p==0)
			{	x1+=cirinc;
				if(x1>=635)
					p=1;
			}
			if(p==1)
			{	x1-=cirinc;
				if(x1<=5)
					p=0;
			}

			if(q==0)
			{	y1+=cirinc;
				if(y1>=460||(y1>=y-10&&x1>=x-10&&x1<=x+50))
				{	if(y1>=y&&x1>=x-10&&x1<=x+9)
					{	sound(1000);
						delay(1);
						nosound();
					}
					q=1;
				}
			}

			if(q==1)
			{	y1-=cirinc;
				if(y1<=5||(y1==y&&x1>=x-1&&x1<=x+9))
				{	if(y1==y&&x1>=x-1&&x1<=x+9)
					{	sound(1000);
						delay(1);
						nosound();
					}
					q=0;
				}
			}
		}
		if(kbhit())
		{	a=getch();
			if(a=='M')
			{	x+=rx;
				if(x>=635)
				x=5;
			}
			if(a=='K')
			{	x-=rx;
				if(x<5)
					x=635;
			}
			if(a=='H')
			{	y-=ry;
				if(y<=0)
					y=480;
			}
			if(a=='P')
			{	y+=ry;
				if(y>=475)
					y=0;
			}
		}
		cleardevice();
		bar(x,y,x+50,y+10);
		circle(x1,y1,10);
	}
	closegraph();
}
/*this program is written by K.V.V.N.Ravi Shankar*/
/*GAYATRI COLLEGE OF ENGINEERING(III/IV-cse)*/