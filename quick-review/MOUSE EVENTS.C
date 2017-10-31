#include<dos.h>
/*function to initialize mouse*/
int init(void)
{
	union REGS i,o;
	i.x.ax=0;
	int86(0x33,&i,&o);
	return o.x.ax;
}

/*function to show curser*/
void show(void)
{
	union REGS i,o;
	i.x.ax=1;
	int86(0x33,&i,&o);
}

/*function to hide mouse cursor*/
void hide(void)
{
	union REGS i,o;
	i.x.ax=2;
	int86(0x33,&i,&o);
}

/*function to read mouse information*/
void inf(int *r,int *l,int *row,int *col)
{
	union REGS i,o;
	i.x.ax=3;
	int86(0x33, &i,&o);
	*r=0;
	*l=0;
	switch(o.x.bx)
	{
		case 1: *l=1;
			break;
		case 2: *r=1;
			break;
		case 3: *l=1;
			*r=1;
	}
	*row=(o.x.dx/8)+1;
	*col=(o.x.cx/8)+1;
}

/*moving mouse cursor by inputting values from keyboard*/
void move(int r,int c)
{
	union REGS i,o;
	i.x.dx=8*(r-1);
	i.x.cx=8*(c-1);
	i.x.ax=4;
	int86(0x33,&i,&o);
}

/*reading the button pressed queue*/
void press(int *no,int *r1,int *c1)
{
	union REGS i,o;
	i.x.bx=0;           /*   clears the queue of left button   */
	i.x.ax=5;
	int86(0x33,&i,&o);
	getch();
	*no=o.x.bx;         /*   no.of times pressed               */
	*r1=(o.x.dx/8)+1;   /*   row. where last time pressed      */
	*c1=(o.x.cx/8)+1;   /*   col. where last time pressed      */
}

/*reading the mouse button released queue*/
void release(int *no,int *r,int *c)
{
	union REGS i,o;
	i.x.bx=0;           /*   clears the queue of left button   */
	i.x.ax=6;
	int86(0x33,&i,&o);
	*no=o.x.bx;
	*r=o.x.dx/8+1;
	*c=o.x.cx/8+1;
}

/*restrict mouse cursor horizontally*/
void hor(int r,int l)
{
	union REGS i,o;
	i.x.ax=7;
	i.x.cx=8*(r-1);
	i.x.dx=8*(l-1);
	int86(0x33,&i,&o);
}

/*restrict mouse cursor vertically*/
void ver(int t,int b)
{
	union REGS i,o;
	i.x.ax=8;
	i.x.cx=8*(t-1);
	i.x.dx=8*(b-1);
	int86(0x33,&i,&o);
}

/*changing mouse cursor appereance*/
void app(char sch,char sat,char cch,char cat) /* screen character,screen attribute,curser character,curser attribute*/
{
	union REGS i,o;
	i.h.ch=sat;
	i.h.dh=cat;
	i.h.cl=sch;
	i.h.dl=cch;
	i.x.ax=0xa;
	i.x.bx=0;
	int86(0x33,&i,&o);
}

void main()
{
int *no,*r1,*c1;
clrscr();
if(init())
printf("mouse initialized");
show();
app(0,0,24,0);
getch();
}