#include<stdlib.h>
#include"dos.h"
void interrupt our();
void interrupt (*prev)();
char far *vid=(char far *)0xB8000000L;
int ticks;
main()
{	prev=getvect(8);
	setvect(8,our);
	keep(0,1000);
}
void interrupt our()
{
	int row,col;
	char far *v,ch;
	ticks++;
	if(ticks>=3)
	{
		col=random(79);
		row=random(24);
		ch=*(vid+row*160+col*2);
		while(ch==' ')
		{
			col=random(79);
			row=random(24);
			ch=*(vid+row*160+col*2);
		}
		for(;row<=24;row++)
		{
			v=vid+row*160+col*2;
			*(v-160)=' ';
			*v=ch;
			delay(25);
		}
		ticks=0;
	}
	(*prev)();
}