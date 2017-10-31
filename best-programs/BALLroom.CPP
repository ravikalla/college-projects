/*this program is written by K.V.V.N.Ravi Shankar*/
/*GAYATRI COLLEGE OF ENGINEERING(III/IV-cse)*/

#include<graphics.h>
#include<conio.h>
#include<dos.h>
int depth,maxx,maxy,maxz;
class a
{   public:
	int x,y,z;
}d;
void main()
{   a b,b1,b2,b3,b4,c1,c2,c3,c4;
	a find(float,float,float);
	int i,j,xjump=3,yjump=3,zjump=1;
	char ax='a',ay='a',az='a';
	static int x1,y1,z1,radius=50;
	detectgraph(&i,&j);
	initgraph(&i,&j,"");

	depth=5;
	maxx=getmaxx()/2;
	maxy=getmaxy()/2;
	maxz=maxy*depth;
	setcolor(2);
	while(!kbhit())
	{	if(ax=='a')
		{	x1+=xjump;
			if(x1>=maxx-35)
			{	ax='b';
				setcolor(i=(i+1)%15);
			}
		}
		else if(ax=='b')
		{	x1-=xjump;
			if(x1<=-maxx+35)
			{	ax='a';
				setcolor(i=(i+1)%15);
			}
		}
		if(ay=='a')
		{	y1+=yjump;
			if(y1>=maxy-35)
				ay='b';
		}
		else if(ay=='b')
		{	y1-=yjump;
			if(y1<=-maxy+35)
				ay='a';
		}
		if(az=='a')
		{   z1+=zjump;
			if(z1>=maxz-35)
				az='b';
		}
		else if(az=='b')
		{   z1-=zjump;
			if(z1<=-maxz+35)
				az='a';
		}
		delay(10);
		cleardevice();
		b1=find(-maxx+10,maxy-10,-maxz+10);
		b2=find(maxx-10,maxy-10,-maxz+10);
		b3=find(maxx-10,-maxy+10,-maxz+10);
		b4=find(-maxx+10,-maxy+10,-maxz+10);
		c1=find(-maxx+10,maxy-10,maxz-10);
		c2=find(maxx-10,maxy-10,maxz-10);
		c3=find(maxx-10,-maxy+10,maxz-10);
		c4=find(-maxx+10,-maxy+10,maxz-10);
		line(b1.x,b1.y,b2.x,b2.y);
		line(b2.x,b2.y,b3.x,b3.y);
		line(b3.x,b3.y,b4.x,b4.y);
		line(b4.x,b4.y,b1.x,b1.y);
		line(c1.x,c1.y,c2.x,c2.y);
		line(c2.x,c2.y,c3.x,c3.y);
		line(c3.x,c3.y,c4.x,c4.y);
		line(c4.x,c4.y,c1.x,c1.y);
		line(b1.x,b1.y,c1.x,c1.y);
		line(b2.x,b2.y,c2.x,c2.y);
		line(b3.x,b3.y,c3.x,c3.y);
		line(b4.x,b4.y,c4.x,c4.y);
		radius=50*(.5-.5*z1/(maxz*depth-35));
		b=find(x1,y1,z1);
		circle(b.x,b.y,radius);
		b1=find(-maxx+10,y1+10,z1);
		b2=find(-maxx+10,y1-10,z1);
		b3=find(-maxx+10,y1,z1+30);
		b4=find(-maxx+10,y1,z1-30);
		line(b1.x,b1.y,b2.x,b2.y);
		line(b3.x,b3.y,b4.x,b4.y);

		b1=find(maxx-10,y1+10,z1);
		b2=find(maxx-10,y1-10,z1);
		b3=find(maxx-10,y1,z1+30);
		b4=find(maxx-10,y1,z1-30);
		line(b1.x,b1.y,b2.x,b2.y);
		line(b3.x,b3.y,b4.x,b4.y);

		b1=find(x1+10,maxy-10,z1);
		b2=find(x1-10,maxy-10,z1);
		b3=find(x1,maxy-10,z1+30);
		b4=find(x1,maxy-10,z1-30);
		line(b1.x,b1.y,b2.x,b2.y);
		line(b3.x,b3.y,b4.x,b4.y);

		b1=find(x1+10,-maxy+10,z1);
		b2=find(x1-10,-maxy+10,z1);
		b3=find(x1,-maxy+10,z1+30);
		b4=find(x1,-maxy+10,z1-30);
		line(b1.x,b1.y,b2.x,b2.y);
		line(b3.x,b3.y,b4.x,b4.y);

	}
}
struct a find(float x1,float y1,float z1)
{	d.x=(maxx)+x1*(.5-.5*z1/(maxz*depth));
	d.y=(maxy)-y1*(.5-.5*z1/(maxz*depth));
	d.z=z1;
	return d;
}
/*this program is written by K.V.V.N.Ravi Shankar*/
/*GAYATRI COLLEGE OF ENGINEERING(III/IV-cse)*/