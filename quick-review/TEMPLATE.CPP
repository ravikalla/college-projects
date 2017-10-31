#include<iostream.h>
#include<conio.h>
template <class t>
t ravi(t a,t b)
{	t c;
	c=a+b;
	return(c);
	}
void main(void)
{	int a,b,c;
	clrscr();
	cin>>a>>b;
	c=ravi(a,b);
	cout<<c;
	getche();
}
