main()
{
int i;char far *vidmem;
clrscr();
vidmem=0xB8000000;
for(i=0;i<2000;i++)
{
*vidmem='R';
vidmem++;
*vidmem=i;
vidmem++;
}
getche();
}

