#include<dos.h>
void main()
{
char far *kb=(char far *)0x417;
*kb=*kb|32;
*kb=*kb|64;
*kb=*kb|16;
}
