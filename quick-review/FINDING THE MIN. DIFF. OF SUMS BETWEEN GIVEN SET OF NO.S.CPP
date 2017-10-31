/*Thou have moved thy armies to COUNTRY(2)
and is ready for an all in attack. Thou
have to capture Lucilla and Maximus alive
or dead. There is a problem confronting
ou though, Lucilla and Maximus are known
to be hiding in different places. If thou
attack one first the other shall flee.
Thou have to therefore divide and conquer.
Prosthemus thy faithful companion has decided
to lend you a helping hand and lead the second army.

Thou now have to divide thy men into two armies to
conquer and capture Maximus and Lucilla at the same
time. Thou have the excellent capability to determine
the strengths of each of thy armymen. Thou now have
to distribute thy army into two armies of nearly equal
strength.

The input consists of multiple blocks.
Each block consists of single integer N
(number of men in thy army) followed by
N Integers in the next line representing
the strengths of each of the armymen ( K ).
Thou have to divide thy armies such that
the difference between the two armies is
minimal in terms of strength and output this
difference in strength alone. The input will
end with the single integer 0

1<=N<=500
1<=k<=500

Sample Input:

8
1 2 3 4 5 6 7 8

4
2 3 4 7

0
Sample Output:

0
2

*/#include<iostream.h>
void find(int);
void comp_sum();
int depth,a[500],t[500],min,no=1,sum1,sum;
int main()
{   int i;
	while(1)
	{   cin>>no;
		if(no==0)
			break;
		sum1=0;
		for(i=0;i<no;i++)
		{	cin>>a[i];
			sum1+=a[i];
		}
		min=sum1;
		for(depth=0;depth<no;depth++)
		{	find(depth);
		}
		cout<<"\n"<<min;
	}
	return(0);
}

void find(int i)
{   int j,k;
	if(i==0)
	{	for(j=0;j<no;j++)
		{	for(k=i+1;k<=depth;k++)
			{	if(a[j]==t[k])
					goto asd;
			}
			t[i]=a[j];
			comp_sum();
			if((sum1-2*sum)<min && sum1>=2*sum)
				min=sum1-2*sum;
			asd:
		}
	}
	else
	{	for(j=0;j<no;j++)
		{	for(k=i+1;k<=depth;k++)
			{	if(a[j]==t[k])
					goto asd1;
			}
			t[i]=a[j];
			find(i-1);
			asd1:
		}
	}
}

void comp_sum()
{   int i;
	sum=0;
	for(i=0;i<=depth;i++)
	{	sum+=t[i];
	}
}