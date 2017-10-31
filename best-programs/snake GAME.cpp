/*this program is written by K.V.V.N.Ravi Shankar*/
/*GAYATRI COLLEGE OF ENGINEERING(III/IV-cse)*/
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<stdlib.h>
void main()
{	int p=0;
	char c='M',x=10,x1=9,x2=8,x3=7,x4=6,x5=5,x6=4,x7=3,x8=2,x9=1,x10=0,y=10,y1=10,y2=10,y3=10,y4=10,y5=10,y6=10,y7=10,y8=10,y9=10,y10=10,px=40,py=14;
	clrscr();
	textcolor(2);
	gotoxy(px,py);
	cprintf("*");
	while(c!=13)
	{	delay(100);
		if(kbhit())c=getch();
		if(c=='M'){x++;if(x==79)x=0;}
		if(c=='K'){x--;if(x==0)x=79;}
		if(c=='H'){y--;if(y==0)y=23;}
		if(c=='P'){y++;if(y==24)y=0;}
		x10=x9;x9=x8;x8=x7;x7=x6;x6=x5;x5=x4;x4=x3;x3=x2;x2=x1;x1=x;
		y10=y9;y9=y8;y8=y7;y7=y6;y6=y5;y5=y4;y4=y3;y3=y2;y2=y1;y1=y;
		gotoxy(x1,y1);
		cprintf("*");
		gotoxy(x1,y1);
		cprintf("*");
		gotoxy(x2,y2);
		cprintf("*");
		gotoxy(x3,y3);
		cprintf("*");
		gotoxy(x4,y4);
		cprintf("*");
		gotoxy(x5,y5);
		cprintf("*");
		gotoxy(x6,y6);
		cprintf("*");
		gotoxy(x7,y7);
		cprintf("*");
		gotoxy(x8,y8);
		cprintf("*");
		gotoxy(x9,y9);
		cprintf("*");
		gotoxy(x10,y10);
		cprintf(" ");
		if(x==px&&y==py)
		{	p++;
			px=random(75)+4;
			py=random(20)+2;
			gotoxy(px,py);
			cprintf("*");
			gotoxy(1,1);
			printf("Score:-%d",p);
		}
	}
}
/*this program is written by K.V.V.N.Ravi Shankar*/
/*GAYATRI COLLEGE OF ENGINEERING(III/IV-cse)*/