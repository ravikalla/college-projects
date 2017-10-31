#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
struct ravi1
{   char x[5000];
};
void main()
{	fstream q;
	q.open("ravi",ios::in|ios::binary);
	if(q.fail())
		cout<<"file not found";
	else
	{	ravi1 b;
		int c=0;
		while(!q.eof())
		{	q.read((char *)&b,sizeof(b));
			cout<<b.x;
			c++;
		}
		cout<<c;
		q.close();
	}
	getch();
}