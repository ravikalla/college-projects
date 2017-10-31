#include<stdio.h>
#include<conio.h>
void main()
{
char a;
int x=10,y=10;
clrscr();
a=getch();
while(a!=13)
{
if(a=='M'){x++;if(x==79)x=0;}
if(a=='K'){x--;if(x==0)x=79;}
if(a=='H'){y--;if(y==0)y=23;}
if(a=='P'){y++;if(y==24)y=0;}
gotoxy(x,y);
printf("\"GAYATRI COLLEGE OF ENGINEERING\"");
a=getch();
clrscr();
}
}
