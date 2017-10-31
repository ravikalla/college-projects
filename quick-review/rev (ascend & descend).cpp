// Written by K.V.V.N.Ravi Shankar of GayatriCollegeOfEngineering(Visakhapatnam,Andhrapradesh,India)
// studying III'rd year B.Tech. in ComputerScienceDepartment.
// Written on 31-jan-06 1:30 am.

/*		25-jan-06For code4bill question
Question:
An array of size N has distinct values 1…N in random order.
You have only operator called rev(X) (where X is any value from 0 to N-1)
which reverses all values from 0 to X (example values 2,3,1,4 and rev(2)
gets you 1,3,2,4). Our objective is to sort the array using minimum number
of Rev(X) functions. How many permutations of N size array require exactly
N number of rev(X) operators to get sorted?
	Eg: for size 3 only 1,3,2 requires 3 moves. 

Answer:
		(considering both ascending and descending order)
I have first written a function 'rec()' which is recursively
called and finds all the possible sequences from 1 to N
where N is the maximum number in the array.

For every different sequence of numbers, we find no. of 'rev()'
functions used to sort in ASCENDING and DESCENDING order and
find the lesser no. among them.('asc_fun()' and 'des_fun()'
are used to find the count of no. of usages of 'rev()'
function).

If the no. obtained is equal to the MAX number,then 'count'
variable is incremented.

Finally after checking all the possible array combinations,
the 'count' variable is printed.
*/

//Code:	optimal for g++ compiler

#include<iostream.h>
unsigned int a[100];	//actual array for all sequences
unsigned int b[100];	//temporary array for sorting
unsigned long int count;//solution
int N;		//MAX no. in the array(input by user)
char bool1=0;
unsigned long int temp1,temp2;//to store the no. of 'rev()' used for ASCENDING and DESCENDING
void rec(int);	//finds all the possibilities of no.s in the array
int asc_fun();	//returns the no. of 'rev()' used for sort in ascending order
int des_fun();	//returns the no. of 'rev()' used for sort in descending order
void rev(int);	//to reverse the elements in the temporary array b[]
int main()
{   int i,n;
	cout<<"\nEnter the N no. in the array:";
	cin>>N;
	count=0;
	rec(N-1);
	cout<<"Count is "<<count<<endl;
	return(0);
}
void rec(int n)
{   int i,j,k;
	for(i=1;i<=N;i++)	//for keeping all the possible no.s in the n'th element
	{   for(j=n+1;j<N;j++)//for checking if the no. to be inserted is already present in the previous elements
			if(a[j]==i)
			{   bool1=1;
				break;
			}
		if(bool1==1)
		{	bool1=0;
			continue;     //if the no. to be inserted is present in the previous elements,
		}				  //then continue to insert the next possible element
		else
			a[n]=i;       //else insert the no.in to the n'th element
		if(n==0)			//if the n'th element is the last element,check for their ascending and desceding order count
		{   temp1=des_fun();
			temp2=asc_fun();
			if(temp1<=temp2)//if descending has less count,
			{	if(temp1==N)//and it is equal to no. of elements in the array,
					count++;//increment the count.
			}
			else			//if ascending has less count,
				if(temp2==N)//and is equal to no. of elements in the array
					count++;//increment the count.
		}
		else				//if n is not the last element,
			rec(n-1);		//call the function recursively for the next element.
	}
}
int asc_fun()				//Find the no. of 'rev()' functions used for sorting
{   int i,j,ind,count1=0;	//in ascending order.
	for(i=0;i<N;i++)		//Storing the actual array in the temporary array.
		b[i]=a[i];
	for(i=N-1;i>0;i--)
	{   ind=i;
		for(j=i-1;j>=0;j--)
			if(b[j]>b[ind])
				ind=j;
		if(ind!=i)
		{	rev(ind);
			rev(i);
			count1+=2;
		}
	}
	return(count1);
}
int des_fun()				//Find the no. of 'rev()' functions used for sorting
{   int i,j,ind,count1;		//in ascending order.
	for(i=0;i<N;i++)
		b[i]=a[i];
	for(i=N-1,count1=0;i>0;i--)
	{   ind=i;
		for(j=i-1;j>=0;j--)
			if(b[j]<b[ind])
				ind=j;
		if(ind!=i)
		{	rev(ind);
			rev(i);
			count1+=2;
		}
	}
	return(count1);
}
void rev(int n)
{   int i,j;
	for(i=0,j=n;i<j;i++,j--)
	{	b[i]+=b[j];
		b[j]=b[i]-b[j];
		b[i]-=b[j];
	}
}