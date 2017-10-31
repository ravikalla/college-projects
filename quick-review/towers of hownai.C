/*Tower of Honoi: we are given a tower of N disks,
initially stacked in increasing size on one of three pegs.
The objective is to transfer the entire tower to
one of the other pegs, moving only one disk at a
time and never a larger one onto a smaller. In this
variation of tower of honoi, peg two contains 1-8 disks
and peg one contains 9-12 disks. How many minimum moves
are needed to move all the disks to the third peg moving
only one disk at a time and never a larger one onto a smaller?
*/
#define MAX 15
int t1[MAX],t2[MAX],t3[MAX],t1_top=0,t2_top=0,t3_top=0;
void tower(int,char,char,char);
void change(char,char);
void disp();
char check();
int tot=0;
void main()
{	int i,n;
	clrscr();
	printf("How many no.s do u put on tower a:-");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	t1[i]=n-i;
		t2[i]=0;
		t3[i]=0;
	}
	t1_top=i;
	t2_top=t3_top=0;
	disp();
	for(;i<MAX;i++)
	{	t1[i]=0;
		t2[i]=0;
		t3[i]=0;
	}
	tower(n,'a','b','c');
	disp();
	printf("\n%d iterations",tot);
	getch();
}
void tower(int n,char i,char j,char k)
{	if(n>=1)
	{	tower(n-1,i,k,j);
//		printf("\nmove disk from tower %c to tower %c",i,j);
		change(i,j);
		tot++;
		if(check()=='y')
		{	printf("\n%d iterations",tot);
			disp();
			exit(0);
		}
		tower(n-1,k,j,i);
	}
}
void change(char c1,char c2)
{	switch (c1)
	{	case 'a':
			switch (c2)
			{	case 'b':
					t2[t2_top]=t1[t1_top-1];
					t1[t1_top-1]=0;
					t2_top++;
					t1_top--;
					break;
				case 'c':
					t3[t3_top]=t1[t1_top-1];
					t1[t1_top-1]=0;
					t3_top++;
					t1_top--;
					break;
			}
			break;
		case 'b':
			switch (c2)
			{	case 'a':
					t1[t1_top]=t2[t2_top-1];
					t2[t2_top-1]=0;
					t1_top++;
					t2_top--;
					break;
				case 'c':
					t3[t3_top]=t2[t2_top-1];
					t2[t2_top-1]=0;
					t3_top++;
					t2_top--;
					break;
			}
			break;
		case 'c':
			switch (c2)
			{	case 'a':
					t1[t1_top]=t3[t3_top-1];
					t3[t3_top-1]=0;
					t1_top++;
					t3_top--;
					break;
				case 'b':
					t2[t2_top]=t3[t3_top-1];
					t3[t3_top-1]=0;
					t2_top++;
					t3_top--;
					break;
			}
			break;
	}
}
void disp()
{   int i;
	static int j;
	if(getch()==27)
		exit(0);
	clrscr();
	printf("%d time",++j);
	for(i=0;i<MAX;i++)
	{	printf("\n\t%d\t%d\t%d",t1[i],t2[i],t3[i]);
	}
}
char check()
{   int i;
	for(i=0;i<8;i++)
	{	if(t2[i]!=8-i)
			return('n');
	}
	return('y');
}
