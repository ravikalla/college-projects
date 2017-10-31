/*lucky no. or not*/
main()
{	int a,b,c,d;
	printf("enter any no.");
	scanf("%d",&a);
	clrscr();
	b=0;d=a;
	while (a>9)
	{	while(a!=0)
		{	c=a%10;b=b+c;a=a/10;
		}
		a=b;
	}
	printf("the lucky no. of %d is %d",d,a);
}