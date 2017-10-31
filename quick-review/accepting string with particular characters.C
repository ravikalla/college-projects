/*program to accept string including SPACE*/
void main()
{	char s[70];
	clrscr();
	scanf("%[A-z 0-9!@#$%^&*()_+-=\|,.<>?'{}]s",s);
	printf("\n\n\t\t%s",s);
	getch();
}