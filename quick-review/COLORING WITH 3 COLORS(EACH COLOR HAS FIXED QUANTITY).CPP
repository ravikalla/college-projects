/*Brave warrior, now it is time for the final war.
Maximus has gathered his armies and is going to
attack Rome. You know that Good shall Triumph
and Thou are going to die, but a brave gladiator
is one who dies for loyalty to his Emperor.
Before facing death thou shall do this last
task, It is to position the armies of Commodus
for the final battle.

Commodus is resourceful and he will not give up
without a brave war. He has given huge amounts of
gold and summoned a large number of warriors W0
from Country(0), W1 from Country(1) and W2 from
Country(2). These warriors should be used
effectively and not more than one warrior
is needed to defend a fortress. Thou shall
find out how to arrange these armies in the
fortresses in Rome. There is also one more
problem, if you place two warriors from the
same country in adjacent Fortresses, thou shall
end up in trouble because these guys are talkative
and will end up merrymaking instead of defending
the city of Rome. Its now time to use thy
experience and valor, to arrange these men and
fortition the maximum number of fortresses in Rome.

You will be given blocks of input terminated by
0 0 0 0 0. The first line consists of N M W0 W1 W2.
N is the number of fortresses in Rome. M is the
number of paths between these fortresses. W0, W1, W2
are the number of warriors from COUNTRY(0),
COUNTRY(1) and COUNTRY(2) respectively. The
next M lines contains pairs x, y (1<=x<=N) and
(1<=y<=N) representing that there is a path between
the fortresses x and y. You must output the maximum
number of fortresses that can be fortitioned.


1<=N<=30
0<=M<=435

Sample Input

4 5 1 2 1

1 2
2 4
1 3
3 4
2 3

4 4 1 2 1

1 2
2 4
1 3
3 4

0 0 0 0 0

Sample Output

4
4

*/
#include<iostream.h>
#include<conio.h>
struct node
{	int i;
	int tot;
	int color;
	struct node *a[29];
}*p[30];
int n,e,c[3],count=0,max=0;
void construct();
void find(node *);
int main()
{	while(1)
	{	cin>>n>>e>>c[1]>>c[2]>>c[3];
		if(n==0)
		{	break;
		}
		construct();
		find(p[0]);
		cout<<"\n"<<count;
	}
	cout<<"\n"<<max;
	return(0);
}
void construct()
{   int i,j,k;
	for(i=0;i<n;i++)
	{	p[i]->color=0;
		p[i]->tot=0;
	}
	for(i=0;i<e;i++)
	{	cin>>j>>k;
		p[j-1]->a[p[j-1]->tot]=p[k-1];
		p[k-1]->a[p[k-1]->tot]=p[j-1];
		(p[j-1]->tot)++;
		(p[k-1]->tot)++;
	}
}
void find(node *q)
{   int i,j,k,c1[3]={0,0,0};
	for(i=0;i<q->tot;i++)
	{   if(q->a[i]->color==0)
			continue;
		else if(q->a[i]->color==1)
			c1[0]=1;
		else if(q->a[i]->color==2)
			c1[1]=1;
		else if(q->a[i]->color==3)
			c1[2]=1;
	}
	for(j=0;j<3;j++)
	{	if(c1[j]==1 || c[j]==0)
			continue;
		else
		{	q->color=j+1;
			c[j]--;
			count++;
			if(count>max)
				max=count;
			for(k=0;k<q->tot;k++)
				if(q->a[k]->color==0)
				   find(q->a[k]);
		}
		q->color=0;
		c[j]++;
		count--;
	}
}