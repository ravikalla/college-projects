/* MOVE MOUSE CURSOR*/
#include<dos.h>
#include<stdio.h>
int i(void);
void sc(void);
void mm(int r,int c);
void setcur(char a,char b,char c,char d);
 main()
 {
 int r,l,row,col;
 clrscr();
	if(!i())
	{
	printf("mouse not initialized");
	exit(1);
	}
 printf("mouse initialized\n");
 sc();
 printf("press any key to move the mouse cursor");
 getch();
 mm(10,10);
 setcur(0,0,250,2);
 getch();
 return(0);
 }



int i(void)
{
union REGS i,o;
int86(0x33,&i,&o);
return(o.x.ax);
}




void sc(void)
{
union REGS i,o;
i.x.ax=1;
int86(0x33,&i,&o);
}




void mm(int r,int c)
{
union REGS i,o;
i.x.dx=8*(r-1);
i.x.cx=8*(c-1);
i.x.ax=4;
int86(0x33,&i,&o);
}



void setcur(char a,char b,char c,char d)
{
union REGS i,o;
i.h.ch=a;
i.h.dh=b;
i.h.cl=c;
i.h.dl=d;
i.x.ax=0xa;
i.x.bx=0;
int86(0x33,&i,&o);
}
