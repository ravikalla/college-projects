// "searching" the database for the language satisfying the given regular expression
// Elimination of "unit productions", reduction to "CHOMSKY NORMAL FORM", reduction to "GRIEBACH NORMAL FORM", "searching" the database for the language satisfying the given grammar
//Done on 2-8-06
//At 00hr:54min.
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>

#define NOT_PRESENT (struct item *)300
#define NOT_A_SYMBOL 100

	/* Structure of a node */
struct item
{	char *info;
	struct item **child;
	int *bool1;
	int datalen;
	int **position;
	int *pos_len;
}*root;//,*root1;

 /* Node of a parse tree */
struct tree
{	char *dat;
	struct tree *left,*right;
}*ptree,*pushp,*popp;

  /* Structure of a Stack */
struct stack
{	struct tree *node;
}stack[100];

	/* Prototypes */
void create(char[],struct item*,int,int);
void compress(struct item*);
void search(struct item*);
int find(char);
void print(struct item *);
void printroot(struct item *);
void check(char[]);

	/* Global Declaration */
char alpha[100],st[100],se[100],str[100],*k;
int i,n,top=0,z,alphanum;

	  /* Position of alphabet in array */
int find(char d)
{	int h;
	for(h=0;h<alphanum;h++)
		if(d==alpha[h])
			return(h);
	return(NOT_A_SYMBOL);
}

void create(char data[],struct item *p,int start,int end)
{	int k,i,j,length;
	for(i=0;i<strlen(data);i++)
	{	k=find(data[i]);
		if(k==NOT_A_SYMBOL)
		{	printf("%c is not in the Given Alphabet\n",data[i]);
			return;
		}
		if(p->child[k]==NOT_PRESENT)
		{	p->child[k]=(struct item *)malloc(sizeof(struct item)); //ERROR in DEV C++ compiler
			p->child[k]->child=(struct item **)malloc(alphanum*sizeof(struct item*));
			p=p->child[k];
			p->info=(char *)malloc(sizeof(char));
			p->info[0]=data[i];
			p->pos_len=(int *)malloc(sizeof(int));
			p->pos_len[0]=0;
			p->bool1=(int *)malloc(sizeof(int));
			p->bool1[0]=0;
			p->datalen=1;
			p->position=(int**)malloc(sizeof(int*));
			p->position[0][0]=start;
			  p->pos_len[0]++;
			start++;
			for(j=0;j<alphanum;j++)
				 p->child[j]=NOT_PRESENT;
		}
		else
			{
			  p=p->child[k];
			  p->position[0]=(int*)realloc(p->position[0],p->pos_len[0]*sizeof(int)+1);
			  p->position[0][p->pos_len[0]]=start;
			  p->pos_len[0]++;
			  start++;
			 }
			 printf("%d\n",p->position[0][p->pos_len[0]-1]);
			}
	p->bool1[0]=1;
}

	/* Root Compression */
void rootcompress(struct item *p)
{	int i;
	for(i=0;i<alphanum;i++)
		if(p->child[i]!=NOT_PRESENT)
			compress(p->child[i]);
	return;
}

	/* Compression of n-ary Tree */
void compress(struct item *p)
{	int x,i,j,q1,c=1,pos=0,temp1[100],r;
	char temp[100];
	struct item *q;
	q=p;
	while(c==1)
	{	c=0;
		for(i=0;i<alphanum;i++)
			if(p->child[i]!=NOT_PRESENT)
				c++;
		if(c==1)
		{	strcpy(temp,q->info);
			for(r=0;r<q->datalen;r++)
			  temp1[r]=q->bool1[r];
			for(j=0;p->child[j]==NOT_PRESENT;j++);
			p=p->child[j];
			q->bool1=(int *)realloc(q->bool1,q->datalen*sizeof(int)+2);
			if(q->bool1==NULL)
			{	printf("ERROR 109:");
				 getch();
				exit(0);
			}
			q->info=(char *)realloc(q->info,q->datalen*sizeof(char)+2);
			if(q->info==NULL)
			{	printf("ERROR 115:") ;
				getch();
				exit(0);
			}
			strcpy(q->info,temp);
			q->position=(int **)realloc(q->position,q->datalen*sizeof(int *)+2);
			q->position[q->datalen]=(int *)realloc(q->position[q->datalen],p->datalen*sizeof(int)+2);
			q->pos_len=(int *)realloc(q->pos_len,sizeof(int)+1);
			for(pos=0;pos<p->pos_len[0];pos++)
			  {
				q->position[q->datalen][pos]=p->position[0][pos];
				q->pos_len[q->datalen]++;
   			  }
			for(r=0;r<q->datalen;r++)
			  q->bool1[r]=temp1[r];
			q->info[q->datalen]=p->info[0];
			if(p->bool1[0]==1)
				q->bool1[q->datalen]=1;
			else
				q->bool1[q->datalen]=0;
			q->datalen=q->datalen+1;
			for(x=0;x<alphanum;x++)
				q->child[x]=p->child[x];
			p=q;
		}
		else if(c>1)
			for(q1=0;q1<alphanum;q1++)
				if(p->child[q1]!=NOT_PRESENT)
					compress(p->child[q1]);
		else
			return;
	}

}
 /*Printing of the database Tree*/
void printroot(struct item *p)
{	int i,j;
	struct item *c;
	for(i=0;i<alphanum;i++)
		if(p->child[i]!=NOT_PRESENT)
		{	c=p->child[i];
			for(j=0;j<c->datalen;j++)
				printf("%c  ",c->info[j]);//c->bool1[j]);
			printf("\t\t");
		}
	printf("\n");
	for(j=0;j<alphanum;j++)
		if(p->child[j]!=NOT_PRESENT)
			printroot(p->child[j]);
	return;
}
 /*RE Checking*/
void check(char str[])
{	int cnt=0,i;
	for(;i<strlen(str);i++)
	{	if(str[i]=='(')
		{	i++;
			check(str);
		}
		if(str[i]=='+'||str[i]=='-'||str[i]=='.'||str[i]=='*')
			cnt++;
		if(str[i]==')')
		{	if(cnt>1)
			{	perror("ERROR11");
			    getch();
				exit(0);
			}
			i++;
			return;
		}
	}
}
		/*Parse Tree construction*/
void push()
{	char p[100];
	strcpy(p,k);
	pushp=(struct tree *)malloc(sizeof(struct tree));
	strcpy(k,p);
	pushp->dat=(char *)malloc(sizeof(char)*strlen(k));
	strcpy(pushp->dat,k);
	pushp->left=NULL;
	pushp->right=NULL;
	stack[top++].node=pushp;
}

void pop1()
{	popp=stack[top-1].node;
	popp->left=stack[top-2].node;
	popp->right=NULL;
	top=top-3;
	stack[top++].node=popp;
}

void pop()
{	int a,l,r;
	if(str[i-1]=='*')
		pop1();
	else
	{	popp=stack[top-2].node;
		popp->left= stack[top-3].node ;
		popp->right=stack[top-1].node;
		top=top-4;
		stack[top++].node=popp;
	}
}

void construct()
{	char s[100];
	n=strlen(str);
	for(i=0;i<n;i++)
		if(str[i]!=')')
		{	z=0;
			k=(char *)malloc(sizeof(char));
			if(str[i]<='z'&&str[i]>='a')
			{	while(str[i]<='z'&&str[i]>='a')
				{	strcpy(s,k);
					k=(char *)realloc(k,sizeof(char));
					strcpy(k,s);
					k[z]=str[i];
					z++;
					i++;
				}
				k[z]='\0';
				i--;
			}
			else
			{	k[z]=str[i];
				k[++z]='\0';
			}
			push();
		}
		else
			pop();
}

void inorder(struct tree *p)
{   int i;
	if(p==NULL)
		return;
	else
	{	inorder(p->left);
		for(i=0;i<strlen(p->dat);i++)
			printf("%c",p->dat[i]);
		inorder(p->right);
	}
}

void ep()
{	int k1,k2,l,i,o,o1;
	for(i=0;i<strlen(str);)
	{	if(str[i]=='!' || (str[i]=='^' && (str[i+1]=='+'|| (str[i-1]=='+'))))
		{	if(str[i-1]=='(')
			{	o=i-1;
				o1=i+2;
				while(str[o1]!=')')
				{	str[o]=str[o1];
					o++;
		  			o1++;
				}
				o1++;
				while(str[o1]!='\0')
				{	str[o]=str[o1];
					o++;
					o1++;
				}
			}
			else
			{	o=i+2;
				o1=i-1;
				l=i-1;
		 		while(str[l]!='(') l--;
				while(str[o]!='\0')
				{	str[o1]=str[o];
					o1++;
					o++;
				}
				str[o1]='\0';
				while(str[l]!='\0')
				{	str[l]=str[l+1];
					l++;
				}
				i=0;
			}
			str[o]='\0';
			i=0;
		}
		else if(str[i]=='^' && (str[i+1]=='.'|| str[i-1]=='.'))
		{	k2=i;
			while(str[k2]!='(') k2--;
			k1=i;
			while(str[k1]!=')') k1++;
			str[k2]='^';
			k2++;
			k1=k1+1;
			while(str[k1]!='\0')
				str[k2++]=str[k1++];
			str[k2]='\0';
			i=0;
		}
		else
			i++;
	 }
}

/* RAVI's work start here	*/
//	Compressing the parse tree
void reg_compress(struct tree *p)
{	if(p==NULL)
		return;

	reg_compress(p->left);
	reg_compress(p->right);

	//	((a*)*)=a*
	if(p->dat[0]=='*' && p->left->dat[0]=='*')
		p->left=p->left->left;
	//	(a*).(a*)=a*
	//	(a*)+(a*)=a*
	if((p->dat[0]=='.' || p->dat[0]=='+') && (p->left->dat[0]=='*' && p->right->dat[0]=='*'))
	{	if((p->left->left->dat[0]!='+' && p->left->left->dat[0]!='.' && p->left->left->dat[0]!='*') && (p->right->left->dat[0]!='+' && p->right->left->dat[0]!='.' && p->right->left->dat[0]!='*'))
		{	if(strcmp(p->left->left->dat,p->right->left->dat)==0)
			{	p->dat[0]='*';
				p->left=p->left->left;
				p->right=NULL;
			}
		}
	}
	//	(((a*).(b*))*)=((a+b)*)
	//	(((a*)+(b*))*)=((a+b)*)
	if(p->dat[0]=='*' && (p->left->dat[0]=='+' || p->left->dat[0]=='.') && (p->left->left->dat[0]=='*' && p->left->right->dat[0]=='*'))
	{	p->left->dat[0]='+';
		p->left->left=p->left->left->left;
		p->left->right=p->left->left;
	}
	//	a+a=a
	if(p->dat[0]=='+' && (p->left->dat[0]!='+' && p->left->dat[0]!='.' && p->left->dat[0]!='*') && (p->right->dat[0]!='+' && p->right->dat[0]!='.' && p->right->dat[0]!='*') && strcmp(p->left->dat,p->right->dat)==0)
	{	strcpy(p->dat,p->left->dat);
		p->left=p->right=NULL;
	}
	//	a.b=ab
	if(p->dat[0]=='.' && (p->left->dat[0]!='+' && p->left->dat[0]!='.' && p->left->dat[0]!='*') && (p->right->dat[0]!='+' && p->right->dat[0]!='.' && p->right->dat[0]!='*'))
	{	strcpy(p->dat,p->left->dat);
		strcat(p->dat,p->right->dat);
		p->left=p->right=NULL;
	}
}


	/*Searching a Regular expression in the database tree starts here*/

struct list		//structure stores the strings which are searched at a level in the 'search_reg_expr' function
{	struct item *data;
	int start,end;
	char *str;
	int length;
	int complete;
	struct list *next;
}*ending;

struct list *search_reg_expr(struct tree *r1,struct list *l11,int flag)
{   int i,j,k,bool11=0;
	struct list *list1,*list2,*l1,*l2;
	if(r1==NULL)
	{	printf("ERROR 371 : Data not present in tree");
	    getch();
		exit(0);
	}
	/*allocating memory to all node pointers*/
	list1=(struct list *)malloc(sizeof(struct list));
	list2=(struct list *)malloc(sizeof(struct list));
	l1=(struct list *)malloc(sizeof(struct list));
	l2=(struct list *)malloc(sizeof(struct list));

	/*allocating memory to data items in the nodes*/
	list1->data=(struct item *)malloc(sizeof(struct item *));
	list2->data=(struct item *)malloc(sizeof(struct item *));
	l1->data=(struct item *)malloc(sizeof(struct item *));
	l2->data=(struct item *)malloc(sizeof(struct item *));

	/*allocating memory to the next pointers of the present nodes list*/
	list1->next=(struct list *)malloc(sizeof(struct list *));
	list2->next=(struct list *)malloc(sizeof(struct list *));
	l1->next=(struct list *)malloc(sizeof(struct list *));
	l2->next=(struct list *)malloc(sizeof(struct list *));

	/* l1 contains the data of l11 */
	l1->data=l11->data;
	l1->start=l11->start;
	l1->end=l11->end;
	l1->str=(char *)malloc(((l11->length)*sizeof(char))+2);
	strcpy(l1->str,l11->str);
	l1->length=l11->length;
	l1->complete=l11->complete;
	l1->next=ending;

	switch(r1->dat[0])	//Check the present node in the syntax tree
	{	case'+':
			list1->next=search_reg_expr(r1->left,l1,flag);	//Keep the leftside nodes list in the next pointer of the temporary node 'temp1'
			list2->next=search_reg_expr(r1->right,l1,flag);	//Keep the rightstde nodes list in the next pointer of the temporary node 'temp2'
			for(l2=list1;l2->next->end!=1;l2=l2->next);	//Make 'l2' as the node pointing to the end of leftlist
			l2->next=list2->next;				//Append rightlist to leftlist and return
			return(list1->next);
		case'.':
			list1->next=search_reg_expr(r1->left,l1,0);	//Find left list
			if(list1->next->end==1)			//If it is empty, no need to check rightlist. Return empty list
				return(ending);
			l1=list1;
			l2=list2;
			do
			{	l2->next=search_reg_expr(r1->right,l1->next,flag);
				for(;l2->next->end!=1;l2=l2->next);
				l1=l1->next;
			}while(l1->next->end!=1);
			return(list2->next);
		case'*':
			l2=search_reg_expr(r1->left,l1,0);
			if(l2->end==1 || (l2->data==l1->data && l2->start==l1->start && l2->next->end==1))	//If the string is empty, return the pointer itself
				if(flag==1 && l1->complete==0)
					return(ending);
				else
					return(l1);
			else if(l2->data==l1->data && l2->start==l1->start)
			{	l1=list2=l2;
				l2=l2->next;
			}
			else
				l1->next=list2=l2;
			while(list2->next->end!=1)
				list2=list2->next;
			do
			{	list2->next=search_reg_expr(r1->left,l2,0);
				while(list2->next->end!=1)
					list2=list2->next;
				l2=l2->next;
			}while(l2->end!=1);
			if(flag==0)
				return(l1);
			while(l1->complete!=1)
			{	if(l1->end==1)
					return(l1);
				l1=l1->next;
			}
			for(l2=l1;l2->next->end!=1;)
			{   if(l2->next->complete!=1)
				{	l2->next=l2->next->next;
					continue;
				}
				l2=l2->next;
			}
			return(l1);
		default:
			for(i=0;r1->dat[i]!='\0';i++)	//For every char of regular expression(R.E) until R.E. is completed
			{	for(j=l1->start;j<l1->data->datalen;j++,i++)//For every character of database tree untill tree is completed
				{	if(r1->dat[i]=='\0')//If the R.E is completed.
						if(flag==1)			//If the requirement is to send the STRING AS A WHOLE
							if(bool11==1)		//If last character that is matched is the endable character in the database
								goto out;			//Return all the pointers that are matched till then
							else
								return(ending);
						else
						{	l1->start=j;
							l1->complete=bool11;
							l1->next=ending;
							return(l1);
						}
					if(l1->data->info[j]!=r1->dat[i])//If the characters in the syntaxtree & data tree are unmatched(Assuming that ends of the strings are always '\0')
						return(ending);
					else
					{	l1->str=(char *)realloc(l1->str,((l1->length)*sizeof(char))+2);
						l1->str[l1->length]=l1->data->info[j];
						l1->str[l1->length+1]='\0';
						l1->length++;
						bool11=l1->data->bool1[j];
					}
				}
				if(r1->dat[i]=='\0')
					if(flag==1)
						if(bool11==1)
							goto out;
						else
							return(ending);
					else
					{	l1->start=j;
						l1->complete=bool11;
						l1->next=ending;
						return(l1);
					}
				k=find(r1->dat[i]);
				if(k==NOT_A_SYMBOL || l1->data->child[k]==NOT_PRESENT)
					return(ending);
				else
				{	l1->data=l1->data->child[k];
					j=l1->start=l1->end=0;
					l1->next=ending;
					i--;
				}
			}
			if(flag==1)		//can be IF((flag==1 && bool11==1) || (flag==0)) ELSE
			{	if(bool11==1)
				{	out:
					l1->start=j;
					l1->complete=bool11;
					l1->next=ending;
					return(l1);
				}
				else
				{	return(ending);
				}
			}
			else
			{	l1->start=j;
				l1->complete=bool11;
				l1->next=ending;
				return(l1);
			}
	}
}

	/* Main Program begins */
int main()
{	int choice,i,n1,old=0,new1=0,count=0,j,n,checkcnt;
	char s[100];
	struct list *l1,*l2;
//	clrscr();
	printf("\nEnter the number of symbols in the alphabet: ");
	scanf("%d",&alphanum);
	root=(struct item *)malloc(sizeof(struct item));
	root->child=(struct item **)malloc(alphanum*sizeof(struct item*));	//inserted by ravi
	root->info=(char *)malloc(sizeof(char));
	root->info[0]='\0';
	root->datalen=0;
	printf("Enter the Symbol of Alphabet and Press Enter:\n(Terminals should be lower case alphabets only)\n");
	fflush(stdin);
	for(i=0;i<alphanum;i++)
	{	scanf("%c",&alpha[i]);
		fflush(stdin);
	}
	for(i=0;i<alphanum;i++)
		root->child[i]=NOT_PRESENT;      //Error : Memory allocation not given to root->child
	FILE *file1=fopen("data.txt","r");
	n1=0;
	count=0;
	old=0;
	new1=0;
	while(fscanf(file1,"%s",s)!=EOF)
	{   fflush(stdin);
		new1=old+strlen(s);
		create(s,root,old,new1);
		n1++;
		old=new1+1;
	}

/*	printf("Enter number of Strings: ");
	scanf("%d",&n1);
	root1=root;
	for(i=0;i<n1;i++)
	{	root=root1;
		printf("Enter the string : ");
		scanf("%s",s);
		fflush(stdin);
		create(s,root);
	}
*/
//	printf("Database Tree before compression\n");
//	printroot(root1);
	rootcompress(root);
//	printf("Database Tree After comression\n");
//	printroot(root1);

//REGULAR EXPRESSION
	printf("\nEnter Regular Expression (! for EPSILON and ^ for PHI) : ");
	fflush(stdin);
	scanf("%s",str);
	printf("\n%s",str);

	ep();
	if(strlen(str)==1 && str[0]=='^')
	{	printf("Result is PHI");
		return(0);
	}
	for(i=0;i<strlen(str);i++)
	{	checkcnt=0;
		for(j=0;j<alphanum;j++)
		{	if(str[i]==alpha[j]||str[i]==')'||str[i]=='('||str[i]=='*'||str[i]=='.'||str[i]=='+')
				checkcnt++;
		}
		if(checkcnt==0)
		{	perror("ERROR");
			getch();
			exit(0);
		}
	}
	check(str);	//Error: NULL POINRTER ASSIGNMENT ERROR
	fflush(stdin);
	construct();	//ERROR : when "(a.((bc)*))" is given, '(' is the 'a' left child in the tree
	ptree=stack[0].node ;
	reg_compress(ptree);	//R.E. compress functions by ravi
	printf("In order traversal\n");
	inorder(ptree);

	/*RAVI's work start here*/
	root->info=(char *)malloc(sizeof(char));
	root->info[0]='\0';
	ending=(struct list *)malloc(sizeof(struct list));
	ending->str=(char *)malloc(sizeof(char));
	ending->str[0]='\0';
	ending->length=0;
	ending->complete=0;	//it could be anything
	ending->end=1;
	l1=(struct list *)malloc(sizeof(struct list));
	l1->data=(struct item *)malloc(sizeof(struct item));
	l1->data=root;
	l1->str=(char *)malloc(sizeof(char));
	l1->str[0]='\0';
	l1->length=0;
	l1->start=0;
	l1->end=0;
	l1->complete=0;	//it could be anything
	l1->next=ending;
//	Start timer
/*	struct time timer1,timer2;
	int hour,min,sec,hund;
	unsigned long int time3;
	gettime(&timer1);
*/	//	Search strings for the Regular Expression
	l1->next=search_reg_expr(ptree,l1,1);
	//	End timer
/*	gettime(&timer2);
	hour=(timer2.ti_hour>=timer1.ti_hour)*(timer2.ti_hour-timer1.ti_hour)+(timer2.ti_hour<timer1.ti_hour)*(timer2.ti_hour+12-timer1.ti_hour);
	min=(timer2.ti_min>=timer1.ti_min)*(timer2.ti_min-timer1.ti_min)+(timer2.ti_min<timer1.ti_min)*(timer2.ti_min+60-timer1.ti_min);
	sec=(timer2.ti_sec>=timer1.ti_sec)*(timer2.ti_sec-timer1.ti_sec)+(timer2.ti_sec<timer1.ti_sec)*(timer2.ti_sec+60-timer1.ti_sec);
	hund=(timer2.ti_hund>=timer1.ti_hund)*(timer2.ti_hund-timer1.ti_hund)+(timer2.ti_hund<timer1.ti_hund)*(timer2.ti_hund+100-timer1.ti_hund);
	time3=hund+sec*100+min*60*100+hour*60*60*100;
	printf("\nstart time : %d sec, %d hundredths",timer1.ti_sec,timer1.ti_hund);
	printf("\nend time   : %d sec, %d hundredths",timer2.ti_sec,timer2.ti_hund);
	printf("\nTime: %d hundredths of a second",time3);
*/
	l2=l1;
	printf("\n=====================================");
	printf("\nThe matched strings are:");
	printf("\n=====================================");
	while(l2->next->end!=1)
	{	printf("\n\t%s",l2->next->str);
		l2=l2->next;
	}
	printf("\n=====================================");
	getch();
	return(0);
}
