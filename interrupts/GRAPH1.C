/* To be tested*/
void main()
{
char far *p;
int i;
p=(char far *)0xA0000000L;
for(i=0;i<30000;i++)
{
p++;
*p=i;
}
kbhit();
}