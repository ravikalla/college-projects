/*finds character when coordinates are given*/
void main()
{
char far *p;
char a;
int x,y;
p=(char *)0xB8000000L;
fflush();
scanf("%d%d",&x,&y);
p=p+2*((80*y)+x);
a=*p;
p--;
*p='*';
p+=2;
*p='*';
gotoxy(72,23);
printf("***%c***\n",a);
getch();
}
