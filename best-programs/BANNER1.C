/*this program is written by K.V.V.N.Ravi Shankar*/
/*GAYATRI COLLEGE OF ENGINEERING(III/IV-cse)*/
void main()
{	char c[10];
	int i,len;
	void put(char,int);
	clrscr();
	puts("Enter any string   ");
	gets(c);
	clrscr();
	for(i=0;i<strlen(c)&&i<10;i++)
		put(c[i],i);
	getch();
}
void put(char c,int i)
{	int row,col,mask;
	char far *c1;
	for(row=0;row<8;row++)
	{   col=8*i+1;
		c1=(char far *)0xFFA6000EL+(c*8)+row;
		mask=128;
		while(mask)
		{   if((mask) & (*c1))
			{	gotoxy(col,row+1);
				putch('*');
			}
			col++;
			mask=mask>>1;
		}
	}
}
/*this program is written by K.V.V.N.Ravi Shankar*/
/*GAYATRI COLLEGE OF ENGINEERING(III/IV-cse)*/