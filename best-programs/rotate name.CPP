/*this program is written by K.V.V.N.Ravi Shankar*/
/*GAYATRI COLLEGE OF ENGINEERING(III/IV-cse)*/
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
int depth,maxx,maxy,maxz;
class a
{   public:
	int x,y,z;
	float radius,angle;
	char color;
}temp,temp1,temp2;
void main()
{   const int NO_OF_STARS=550;
	a d[NO_OF_STARS];
	a find(float,float,float);
	int i,j,zjump=1;
	detectgraph(&i,&j);
	initgraph(&i,&j,"");
	char bool=0;
	depth=1;
	maxx=getmaxx()/2;
	maxy=getmaxy()/2;
	maxz=maxy*depth;
	setcolor(2);

	settextstyle(5,0,5);
	setcolor(2);
	outtextxy(150,210,"HAI");
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
			d[i].radius=sqrtl(d[i].x*d[i].x+d[i].y*d[i].y);
			d[i].angle=atan2l(d[i].y,d[i].x)*180/3.147;
		 }
	}
	cleardevice();
	j=i;
	char rot_clock='a',mov_front='a';
	int angle=0;
	color=1;
	while(bool!=27)
	{   if(kbhit())
		{	bool=getch();
			rot_clock=(rot_clock=='a')*'b'+(rot_clock!='a')*'a';
			color=(color%14)+1;
		}
		if(rot_clock=='a')
			angle=(angle+1)%360;
		else if(rot_clock!='a')
			angle=(angle>0)*(angle-1)+(angle<=0)*360;
		for(i=0;i<j;i++)
		{   d[i].x=(maxx)+d[i].radius*cos((angle-d[i].angle)*3.147/180)*(.5-.5*d[i].z/(maxz*depth));
			d[i].y=(maxy)+d[i].radius*sin((angle-d[i].angle)*3.147/180)*(.5-.5*d[i].z/(maxz*depth));
			temp.x=(maxx)+(d[i].radius+10)*cos((angle-(d[i].angle+10))*3.147/180)*(.5-.5*d[i].z/(maxz*depth));
			temp.y=(maxy)+(d[i].radius+10)*sin((angle-(d[i].angle+10))*3.147/180)*(.5-.5*d[i].z/(maxz*depth));
			temp1.x=(maxx)+(d[i].radius+30)*cos((angle-(d[i].angle+60))*3.147/180)*(.5-.5*d[i].z/(maxz*depth));
			temp1.y=(maxy)+(d[i].radius+30)*sin((angle-(d[i].angle+60))*3.147/180)*(.5-.5*d[i].z/(maxz*depth));
			temp2.x=(maxx)+(d[i].radius+50)*cos((angle-(d[i].angle+90))*3.147/180)*(.5-.5*d[i].z/(maxz*depth));
			temp2.y=(maxy)+(d[i].radius+50)*sin((angle-(d[i].angle+90))*3.147/180)*(.5-.5*d[i].z/(maxz*depth));

			putpixel(temp.x,temp.y,d[i].color+1);
			putpixel(temp1.x,temp1.y,d[i].color+2);
			putpixel(temp2.x,temp2.y,d[i].color+3);
			putpixel(d[i].x,d[i].y,color);
			if(mov_front=='a')
			{	if((d[i].z=d[i].z-zjump)<=-maxz)
					mov_front='b';
			}
			else
			{	if((d[i].z=d[i].z+zjump)>=maxz)
					mov_front='a';
			}
		}
		delay(10);
		for(i=0;i<j;i++)
		{	temp.x=(maxx)+(d[i].radius+10)*cos((angle-(d[i].angle+10))*3.147/180)*(.5-.5*d[i].z/(maxz*depth));
			temp.y=(maxy)+(d[i].radius+10)*sin((angle-(d[i].angle+10))*3.147/180)*(.5-.5*d[i].z/(maxz*depth));
			temp1.x=(maxx)+(d[i].radius+30)*cos((angle-(d[i].angle+60))*3.147/180)*(.5-.5*d[i].z/(maxz*depth));
			temp1.y=(maxy)+(d[i].radius+30)*sin((angle-(d[i].angle+60))*3.147/180)*(.5-.5*d[i].z/(maxz*depth));
			temp2.x=(maxx)+(d[i].radius+50)*cos((angle-(d[i].angle+90))*3.147/180)*(.5-.5*d[i].z/(maxz*depth));
			temp2.y=(maxy)+(d[i].radius+50)*sin((angle-(d[i].angle+90))*3.147/180)*(.5-.5*d[i].z/(maxz*depth));
			putpixel(temp.x,temp.y,0);
			putpixel(temp1.x,temp1.y,0);
			putpixel(temp2.x,temp2.y,0);
			putpixel(d[i].x,d[i].y,0);

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
/*this program is written by K.V.V.N.Ravi Shankar*/
/*GAYATRI COLLEGE OF ENGINEERING(III/IV-cse)*/