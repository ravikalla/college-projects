/*converting DEL key to CTRL+Y key*/
#include<dos.h>
void interrupt (*old)();
void interrupt new1();
char far *ptr=(char far *)0x41c;
void main()
{	old=getvect(0x09);
	setvect(0x09,new1);
	keep(0,1000);
}
void interrupt new1()
{	if(inportb(0x60)==83)
	{	*((char far *)0x400+*ptr)=25;
		if(*ptr==60)
			*ptr=30;
		else
			*ptr+=2;
		outportb(0x20,0x20);
		return;
	}
	(*old)();
}