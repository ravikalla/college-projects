/* TO CHANGE CHARACTERS OF SCREEN REGULARLY*/
#include"dos.h"
void interrupt our();
void interrupt (*prev)();
char far *scr=(char far *)0xB8000000;
int t;
unsigned char c;

main()
{
prev=getvect(8);
setvect(8,our);
keep(0,500);
}

void interrupt our()
{
int i;
t++;
if(t==81)
{
t=0;
for(i=0;i<4000;i++);
{
*(scr+i)=c;
c++;
}
(*prev)();
}
}