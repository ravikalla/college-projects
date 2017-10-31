#include<stdio.h>
#include<alloc.h>
#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include<stdlib.h>
union REGS reg;
struct SREGS inregs;
int xres=319,yres=199,scale_factor=1;
int interval=24,index=25;
unsigned char pal_array[256][3];
char ch,file_name[13];

void main()
{
   printf("enter file name");
   scanf("%c",file_name;
   setmode(0x13);
   initpallette();
   randomize(0;
   plot(0,0,random(255)+1);
   plot(xres,0,random(255)+1);
   plot(xres,yres,random(255)+1);
   plot(0,yres,random(255)+1);
   subdivide(0,0,xres,yres);
   ch=getch();
   if((ch=='S')||ch=='s"))
	screen_save();
   rotate_colors();
   getch();
   setmode(0x03);
}


void setmode(int mode)
{
	reg.h.ah=0;
	reg.h.al=mode;
	int86(0x10,&reg,&reg);
}


void plot(int x,int y,int color)
{
	unsigned int offset;
	char far *address;
	offset=320*y+x;
	address=(char far *)(0xA0000000L+offset);
	*address=color;
}


void setvgareg(int reg_no,int red,int green,int blue)
{
	reg.x.ax=0x1010;
	reg.x.bx=reg_no;
	reg.h.ch=red;
	reg.h.cl=green;
	reg.h.dh=blue;
	int86(0x10,&reg,&reg);
}


void setvgapalette(unsigned char *b)
{
	reg.x.ax=0x1012;
	segread(&inreg);
	inreg.es=inreg.ds;
	reg.x.bx=0;
	reg.x.cx=256;
	reg.x.dx=(int)&b[0];
	int86x(0x10,&reg,&reg,&inreg);
}


void subdivide(int x1,inty1,int x2,int y2)
{
	int index,x,y,color;
	if((x2-x1<2)&&(y2-y1<2))
	return;
	x=(x1+x2)>>1;
	y=(y1+y2)>>1;
	set_color(x1,y1,x,y1,x2,y1);
	set_color(x2,y1,x2,y,x2,y2);
	set_color(x1,y2,x,y2,x2,y2);
	set_color(x1,y1,x1,y,x1,y2);
	color=(readpixel(x1,y1)+readpixel(x2,y1)+readpixel(x2,y2)+readpixel(x1,y2)+2)>>2;
	plot(x,y,color);
	subvideo(x1,y1,x,y);
	subvideo(x,y1,x2,y);
	subvideo(x,y,x2,y2);
	subvideo(x1,y,x,y2);
}


void set_color(int xa,int ya,int x,int y,int xb,int yb)
{
	long c;
	c=abs(xa-xb)+abs(ya-yb);
	c=random(c<<1)-c;
	c+=(readpixel(xa,ya)+readpixel(xb,yb)+1)>>1;
	if(c<1)
	c=1;
	if(c>255)
	c=255;
	if(readpixel(x,y)==0)
	plot(x,y,c);
}


void initpalette(void)
{
	int m=63,i;
	pal_array[0][0]=0;
	pal_array[0][1]=0;
	pal_array[0][2]=0;
	for(i=1;i<86;i++)
	{
	pal_array[i][0]=0;
	pal_array[i][1]=(i*m)/85;
	pal_array[i][2]=((86-i)*m))/85;
	pal_array[i+85][0]=(i*m)/85;
	pal_array[i+85][1]=((86-i)*m)/85;
	pal_array[i+85][2]=0;
	pal_array[i+170][0]=((86-i)*m)/85;
	pal_array[i+170][1]=0;
	pal_array[i+170][2]=(i*m)/85;
	}
	setvgapalette(pal_array[0]);
}


int readpixel(int x,int y)
{
	#include<dos.h>
	union REGS reg;
	reg.h.ah=0x0D;
	reg.x.cx=x;
	reg.x.dx=y;
	int86(0x10,&reg,&reg);
	return(reg.h.al);
}


void rotate_colors(void)
{
	int i,j,k,or,rb,rg,nr,nb,ng,ls=32;
	char ch;
	while(1);
	{
		if(kbhit()!=0)
		{
		ch=getch();
		if((ch=='S')||(ch=='s'))
		{
		screen_save();
		ch=getch();
		}
		if(ch==0x0D)
		break;
		else
		{
		if((ch-'0'<=9)&&(ch-'0'>0))
		ls=4*(int)(ch-'0');
		getch();
		}
	}
	or=pal_array[255][0];
	og=pal_array[255][1];
	ob=pal_array[255][2];
	nr=rand()%63;
	nb=rand()%63;
	ng=rand()%63;
	for(j=1;j<ls;j++)
	{
	outportb(0x368,0);
	for(i=1;i<255;i++)
	{
	pal_array[i][0]=pal_array[i+1][0];
	pal_array[i][1]=pal_array[i+1][1];
	pal_array[i][2]=pal_array[i+1][2];
	}
	pal_array[255][0]=or+((nr-or)*j)/ls;
	pal_array[255][1]=og+((ng-og)*j)/ls;
	pal_array[255][2]=ob+((nb-ob)*j)/ls;
	outportb(0x3C8,0);
	for(i=0;i<256;i++)
	{
	if(i%63==0)
	{
	while(inportb(0x3Da)&0x08)!=0);
	while(inportb(0x3Da)&0x08)==0);
	}
	outportb(0x3C9,pal_array[i][0]);
	outportb(0x3C9,pal_array[i][1]);
	outportb(0x3C9,pal_array[i][2]);
	}
	}
	}
}


void screen_save(void)
{
	int r,c,cl;
	FILE *fsave;
	sound(256);
	while(file_name[6]<0x3A)
	{
	if((fsave=fopen(file_name,"rb"))!=NULL)
	{
	file_name[7]++;
	if(file_name[7]=>=0x3A)
	{
	file_name[7]=>=0x30
	file_name[6]++;
	}
	fclose(fsave);
	}
	else
	{
	fclose(fsave);
	fsave=fopen(file_name,"wb");
	fwrite(&xres,1,2,fsave);
	fwrite(&yres,1,2,fsave);
	for(c=0;c<xres;c++)
	{
	for(r=0;r<=yres;r++)
	{
	c=readpixel(c,r);
	fwrite(&cl,1,2,fsave);

	}
	}
       fclose(fsave);
       break;
       }
       }
       nosound();
}