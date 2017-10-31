#include<graphics.h>
#include<conio.h>
#include<dos.h>

int depth,maxx,maxy,maxz;
class a
{   public:
	int x,y,z;
	char color;
}temp,temp1,temp2;//temp3,temp4,temp5,temp6;
void main()
{   const int NO_OF_STARS=580;
	a d[NO_OF_STARS];
	a find(float,float,float);
	int i,j,zjump=5;
	detectgraph(&i,&j);
	initgraph(&i,&j,"");

	depth=1;
	maxx=getmaxx()/2;
	maxy=getmaxy()/2;
	maxz=maxy*depth;
	setcolor(2);

	settextstyle(5,0,4);
	setcolor(1);
	outtextxy(10,10,"gvp");
	setcolor(2);
	outtextxy(500,10,"engg");
	setcolor(3);
	outtextxy(500,400,"cse");
	setcolor(4);
	outtextxy(10,400,"coll");
	int max_x_tot=getmaxx(),max_y_tot=getmaxy();
	char color;
	int temp_x=0,temp_y=0;

	for(i=0;i<NO_OF_STARS;)
	{   if(max_x_tot<=++temp_x)
		{	temp_x=0;
			temp_y++;
			if(temp_y>=max_y_tot+1)
				break;
		}
		if((color=getpixel(temp_x,temp_y))!=0)
		{   i++;
			d[i].color=color;
			d[i].x=temp_x-maxx;
			d[i].y=maxy-temp_y;
			if(d[i].x>0 && d[i].y>0)
				d[i].z=maxz/2;
			else if(d[i].x<0 && d[i].y<0)
				d[i].z=-maxz/2;
			else if(d[i].x<0 && d[i].y>0)
				d[i].z=0;
			else
				d[i].z=maxz;
		}
	}
	cleardevice();
	j=i;
	while(!kbhit())
	{   for(i=0;i<j;i++)
		{	temp=find(d[i].x,d[i].y,d[i].z);
			temp1=find((d[i].x>0)*(d[i].x-100)+(d[i].x<=0)*(d[i].x+100),(d[i].y>0)*(d[i].y-100)+(d[i].y<=0)*(d[i].y+100),d[i].z);
			temp2=find((d[i].x>0)*(d[i].x-maxx)+(d[i].x<=0)*(d[i].x+maxx),(d[i].y>0)*(d[i].y-maxy)+(d[i].y<=0)*(d[i].y+maxy),d[i].z);
/*			temp3=find((d[i].x>0)*(d[i].x-300)+(d[i].x<=0)*(d[i].x+300),(d[i].y>0)*(d[i].y-100)+(d[i].y<=0)*(d[i].y+100),d[i].z);
			temp4=find((d[i].x>0)*(d[i].x-maxx)+(d[i].x<=0)*(d[i].x+maxx),(d[i].y>0)*(d[i].y-100)+(d[i].y<=0)*(d[i].y+100),d[i].z);
			temp5=find((d[i].x>0)*(d[i].x-50)+(d[i].x<=0)*(d[i].x+200),(d[i].y>0)*(d[i].y-50)+(d[i].y<=0)*(d[i].y+200),d[i].z);
			temp6=find((d[i].x>0)*(d[i].x-200)+(d[i].x<=0)*(d[i].x+200),(d[i].y>0)*(d[i].y-maxy)+(d[i].y<=0)*(d[i].y+maxy),d[i].z);
*/
			putpixel(temp.x,temp.y,d[i].color);
			putpixel(temp1.x,temp1.y,d[i].color+1);
			putpixel(temp2.x,temp2.y,d[i].color+2);
/*			putpixel(temp3.x,temp3.y,d[i].color+3);
			putpixel(temp4.x,temp4.y,d[i].color+4);
			putpixel(temp5.x,temp5.y,d[i].color+5);
			putpixel(temp6.x,temp5.y,d[i].color+6);
*/		}
		delay(5);
		for(i=0;i<NO_OF_STARS;i++)
		{   temp=find(d[i].x,d[i].y,d[i].z);
			putpixel(temp.x,temp.y,0);
			temp1=find((d[i].x>0)*(d[i].x-100)+(d[i].x<=0)*(d[i].x+100),(d[i].y>0)*(d[i].y-100)+(d[i].y<=0)*(d[i].y+100),d[i].z);
			putpixel(temp1.x,temp1.y,0);
			temp2=find((d[i].x>0)*(d[i].x-maxx)+(d[i].x<=0)*(d[i].x+maxx),(d[i].y>0)*(d[i].y-maxy)+(d[i].y<=0)*(d[i].y+maxy),d[i].z);
			putpixel(temp2.x,temp2.y,0);
/*			temp3=find((d[i].x>0)*(d[i].x-300)+(d[i].x<=0)*(d[i].x+300),(d[i].y>0)*(d[i].y-100)+(d[i].y<=0)*(d[i].y+100),d[i].z);
			temp4=find((d[i].x>0)*(d[i].x-maxx)+(d[i].x<=0)*(d[i].x+maxx),(d[i].y>0)*(d[i].y-100)+(d[i].y<=0)*(d[i].y+100),d[i].z);
			temp5=find((d[i].x>0)*(d[i].x-50)+(d[i].x<=0)*(d[i].x+200),(d[i].y>0)*(d[i].y-50)+(d[i].y<=0)*(d[i].y+200),d[i].z);
			temp6=find((d[i].x>0)*(d[i].x-200)+(d[i].x<=0)*(d[i].x+200),(d[i].y>0)*(d[i].y-maxy)+(d[i].y<=0)*(d[i].y+maxy),d[i].z);
			putpixel(temp3.x,temp3.y,0);
			putpixel(temp4.x,temp4.y,0);
			putpixel(temp5.x,temp5.y,0);
			putpixel(temp6.x,temp5.y,0);
*/			if((d[i].z=d[i].z-zjump)<=-maxz)
				d[i].z=maxz;
		}
	}
}
struct a find(float x1,float y1,float z1)
{   a d;
	d.x=(maxx)+x1*(.5-.5*z1/(maxz*depth));
	d.y=(maxy)-y1*(.5-.5*z1/(maxz*depth));
	d.z=z1;
	return d;
}