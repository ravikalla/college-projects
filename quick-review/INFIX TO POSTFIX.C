 /*INFIX TO POSTFIX*/
 void main()
 {
 char c,i[50],p[50],s[40],si=0,sp=0,ss=0;
 clrscr();
 printf("Enter infix expression:-");
 gets(i);
 while(i[si]!='\0')
 {	c=i[si++];
	if(c=='(')
		s[ss++]=c;
	else if(c=='^')
	{	for(;s[ss-1]=='^';p[sp++]=s[--ss]);
		s[ss++]=c;
	}
	else if(c=='*'||c=='/')
	{	for(;s[ss-1]=='*'||s[ss-1]=='/'||s[ss-1]=='^';p[sp++]=s[--ss]);
		s[ss++]=c;
	}
	else if(c=='+'||c=='-')
	{	for(;s[ss-1]=='*'||s[ss-1]=='/'||s[ss-1]=='+'||s[ss-1]=='-'||s[ss-1]=='^';p[sp++]=s[--ss]);
		s[ss++]=c;
	}
	else if(c==')')
	{	for(;s[ss-1]!='(';p[sp++]=s[--ss]);
		ss--;
	}
	else  
		p[sp++]=c;
 }
 p[sp]='\0';
 printf("\nPostfix notation is %s",p);
 getch();
 }