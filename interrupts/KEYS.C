/*CTRL ALT DEL keys are ON*/
main()
{
char far *kb;
kb=(char far *)0x417;
*kb=64;
*kb=32;
*kb=16;
}