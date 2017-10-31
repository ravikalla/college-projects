/*this program is written by K.V.V.N.Ravi Shankar*/
/*GAYATRI COLLEGE OF ENGINEERING(III/IV-cse)*/
void main()
{	char *s;
	int len,i,j;
	clrscr();
	puts("Enter any string");
	gets(s);
	len=strlen(s);
	for(i=0;!kbhit();i=(i+1)%len)
	{	gotoxy(40-len/2,12);
		delay(500);
		j=i;
		do
		{	putch(s[j]);
			j=(j+1)%len;
		}while(j!=i);
	}
}
/*this program is written by K.V.V.N.Ravi Shankar*/
/*GAYATRI COLLEGE OF ENGINEERING(III/IV-cse)*/