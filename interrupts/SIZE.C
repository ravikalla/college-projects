#include<stdio.h>
#include<conio.h>
void main(void)
{
clrscr();
unsigned int far *m;
m=(unsigned int far *)0x413;
gotoxy(30,12);
printf("\"BASE MEMORY\"size is %d KB",*m);
getch();
}