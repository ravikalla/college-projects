/*What is the probability of two people
arriving at a restaurant withing 21 minutes
of each other between 1 PM and 5 PM?
The answer needs to be rounded to 4
decimal places with no trailing zeroes.
(e.g .15 needs to be represented as 0.15,0.154567
needs to be represented as 0.1546)
*/
void main()
{	int i,j,k;
	static unsigned long int l=0.0;
	float f=1;
	clrscr();
	for(i=0;i<240;i++)
	{	for(j=i;j>=0 && j>i-21;j--)
		{	l+=1;
		}
		for(j=i+1;j<=240 && j<i+21;j++)
		{	l+=1;
		}
	}
	printf("%ld",l);
	printf("prob is %lf",l/(240*240));
	getch();
}