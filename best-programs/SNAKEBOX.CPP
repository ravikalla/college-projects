#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>
//the box rotates in anti clock wise direction when seen from top
static int len;
struct a
{	int x,y,z;
}d,temp,snake;
unsigned long int sqt(unsigned long int);
void main()
{	struct a b[4],e[4];
	struct a find(double,double,double);
	int i,j,angle,angle_step=10,x=0,y=-150,z=0,h_x,h_y,h_z;
	int y1=10,y2,z1=200;
	y2=y1-2*y1;
	snake.x=x;
	snake.y=y+y2;
	snake.z=0;
	detectgraph(&i,&j);
	initgraph(&i,&j,"c:\\tc\\bgi");
	angle=0;
	j=0;
	while(i!=13)
	{   if(kbhit())
		{	i=getch();
			j=1;
		}
		if(j==1)
		{	j=0;
			if(i==72)
			{	y1+=10;
				if(y1>=230)
					y1=-230;
			}
			else if(i==80)
			{	y1-=10;
				if(y1<=-230)
					y1=230;
			}
			else if(i==77)
			{   angle=(angle+angle_step)%360;
			}
			else if(i==75)
			{	angle-=+angle_step;
				if(angle<=0)
					angle=359;
			}
		}
		b[0]=find(x+310*cos(((angle+45)%360)*3.14159/180),y+y1,z+z1*sin(((45+angle)%360)*3.14159/180));
		b[1]=find(x+310*cos(((angle+135)%360)*3.14159/180),y+y1,z+z1*sin(((135+angle)%360)*3.14159/180));
		b[2]=find(x+310*cos(((angle+225)%360)*3.14159/180),y+y1,z+z1*sin(((225+angle)%360)*3.14159/180));
		b[3]=find(x+310*cos(((angle+315)%360)*3.14159/180),y+y1,z+z1*sin(((315+angle)%360)*3.14159/180));
		e[0]=find(x+310*cos(((angle+45)%360)*3.14159/180),y+y2,z+z1*sin(((45+angle)%360)*3.14159/180));
		e[1]=find(x+310*cos(((angle+135)%360)*3.14159/180),y+y2,z+z1*sin(((135+angle)%360)*3.14159/180));
		e[2]=find(x+310*cos(((angle+225)%360)*3.14159/180),y+y2,z+z1*sin(((225+angle)%360)*3.14159/180));
		e[3]=find(x+310*cos(((angle+315)%360)*3.14159/180),y+y2,z+z1*sin(((315+angle)%360)*3.14159/180));
//		temp=find(x,y+(y1+y2)/2,z);
		temp=find(x+snake.x*cos(((angle+90)%360)*3.14159/180),snake.y,snake.z);
		snake.x=x+sqt(snake.z*snake.z+snake.x*snake.x)*cos(((angle+90)%360)*3.14159/180);
		snake.z+=3;
		delay(150);
		cleardevice();
		circle(temp.x,temp.y,3);
		line(b[1].x,b[1].y,b[0].x,b[0].y);
		line(b[1].x,b[1].y,b[2].x,b[2].y);
		line(b[2].x,b[2].y,b[3].x,b[3].y);
		line(b[3].x,b[3].y,b[0].x,b[0].y);
		line(e[1].x,e[1].y,e[0].x,e[0].y);
		line(e[1].x,e[1].y,e[2].x,e[2].y);
		line(e[2].x,e[2].y,e[3].x,e[3].y);
		line(e[3].x,e[3].y,e[0].x,e[0].y);
		line(b[0].x,b[0].y,e[0].x,e[0].y);
		line(b[1].x,b[1].y,e[1].x,e[1].y);
		line(b[2].x,b[2].y,e[2].x,e[2].y);
		line(b[3].x,b[3].y,e[3].x,e[3].y);
	}
	closegraph();
}
struct a find(double x1,double y1,double z1)
{	len=3;
	if(z1<=240*len)
	{	d.x=320+x1*(240*len-z1)/(240*len);
		d.y=240-y1*(240*len-z1)/(240*len);
	}
	else
		d.x=d.y=0;
	d.z=z1;
	return d;
}
unsigned long int sqt(unsigned long int i)
{   unsigned long int j;
	for(j=0;j*j<i;j++);
	return(j);
}