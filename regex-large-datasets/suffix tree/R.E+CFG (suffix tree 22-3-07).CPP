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

	/* Structure of a datatree node */

struct item
{
	char *info;
	struct item **child;
	int *bool1;
	int datalen;
}*root,*root1;

 /* Node of a parse tree */
struct tree
{
	char *dat;
	struct tree *left,*right;
}*ptree,*pushp,*popp;

  /* Structure of a Stack */
struct stack
{
	struct tree *node;
}stack[100];


	/* Prototypes */

void create(char[],struct item*);
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
{
	int h;
	for(h=0;h<alphanum;h++)
	{
		if(d==alpha[h])
		{
			return(h);
		}
	}
	return(NOT_A_SYMBOL);
}

void create(char data[],struct item *p)
{
	int k,i,j;
	for(i=0;i<strlen(data);i++)
	{
		k=find(data[i]);
		if(k==NOT_A_SYMBOL)
		{
			printf("ERROR 78: \'%c\' is not in the Given Alphabet\n",data[i]);
			getch();
			exit(0);
		}
		if(p->child[k]==NOT_PRESENT)
		{
			p->child[k]=(struct item *)malloc(sizeof(struct item)); //ERROR in DEV C++ compiler
			p->child[k]->child=(struct item **)malloc(alphanum*sizeof(struct item*));
			p=p->child[k];
			p->info=(char *)malloc(sizeof(char));
			p->info[0]=data[i];
			p->bool1=(int *)malloc(sizeof(int));
			p->bool1[0]=0;
			p->datalen=1;
			for(j=0;j<alphanum;j++)
				 p->child[j]=NOT_PRESENT;
		}
		else
		{
			p=p->child[k];
		}
	}
	p->bool1[0]=1;
}

	/* Root Compression */
void rootcompress(struct item *p)
{	int i;
	for(i=0;i<alphanum;i++)
	{
		if(p->child[i]!=NOT_PRESENT)
		{
			compress(p->child[i]);
		}
	}
	return;
}

	/* Compression of n-ary Tree */
void compress(struct item *p)
{
	int x,i,j,q1,c=1,temp1[100],r;
	char temp[100];
	struct item *q;

	q=p;
	while(c==1)
	{
		c=0;
		for(i=0;i<alphanum;i++)
		{
			if(p->child[i]!=NOT_PRESENT)
			{
				c++;
			}
		}
		if(c==1)
		{
			strcpy(temp,q->info);
			for(r=0;r<q->datalen;r++)
			{
				temp1[r]=q->bool1[r];
			}
			for(j=0;p->child[j]==NOT_PRESENT;j++);
			{
				p=p->child[j];
			}
			q->bool1=(int *)realloc(q->bool1,q->datalen*sizeof(int)+2);
			if(q->bool1==NULL)
			{
				printf("ERROR 109:");
				getch();
				exit(0);
			}

			q->info=(char *)realloc(q->info,q->datalen*sizeof(char)+2);

			if(q->info==NULL)
			{
				printf("ERROR 115:") ;
				getch();
				exit(0);
			}
			strcpy(q->info,temp);
			for(r=0;r<q->datalen;r++)
			{
				q->bool1[r]=temp1[r];
			}
			q->info[q->datalen]=p->info[0];
			if(p->bool1[0]==1)
			{
				q->bool1[q->datalen]=1;
			}
			else
			{
				q->bool1[q->datalen]=0;
			}
			q->datalen=q->datalen+1;
			for(x=0;x<alphanum;x++)
			{
				q->child[x]=p->child[x];
			}
			p=q;
		}
		else if(c>1)
		{
			for(q1=0;q1<alphanum;q1++)
			{
				if(p->child[q1]!=NOT_PRESENT)
				{
					compress(p->child[q1]);
				}
			}
		}
		else
		{
			return;
		}
	}

}


 /*Printing of the database Tree*/

void printroot(struct item *p)
{
	int i,j;
	struct item *c;
	for(i=0;i<alphanum;i++)
	{
		if(p->child[i]!=NOT_PRESENT)
		{
			c=p->child[i];
			for(j=0;j<c->datalen;j++)
			{
				printf("%c  ",c->info[j]);//c->bool1[j]);
			}
			printf("\t\t");
		}
	}
	printf("\n");
	for(j=0;j<alphanum;j++)
	{
		if(p->child[j]!=NOT_PRESENT)
		{
			printroot(p->child[j]);
		}
	}
	return;
}


 /*RE Checking*/

void check(char str[])
{
	int cnt=0,i;
	for(;i<strlen(str);i++)	//ERROR : Memory error if 'i' is initialized to 0
	{
		if(str[i]=='(')
		{
			i++;
			check(str);
		}
		if(str[i]=='+'||str[i]=='-'||str[i]=='.'||str[i]=='*')
		{
			cnt++;
		}
		if(str[i]==')')
		{
			if(cnt>1)
			{
				perror("ERROR11");
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
{
	char p[100];
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
{
	popp=stack[top-1].node;
	popp->left=stack[top-2].node;
	popp->right=NULL;
	top=top-3;
	stack[top++].node=popp;
}

void pop()
{
	if(str[i-1]=='*')
	{
		pop1();
	}
	else
	{
		popp=stack[top-2].node;
		popp->left= stack[top-3].node ;
		popp->right=stack[top-1].node;
		top=top-4;
		stack[top++].node=popp;
	}
}

void construct()
{
	char s[100];
	n=strlen(str);
	for(i=0;i<n;i++)
	{
		if(str[i]!=')')
		{
			z=0;
			k=(char *)malloc(sizeof(char));
			if(str[i]<='z'&&str[i]>='a')
			{
				while(str[i]<='z'&&str[i]>='a')
				{
					strcpy(s,k);
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
			{
				k[z]=str[i];
				k[++z]='\0';
			}
			push();
		}
		else
			pop();
	}
}

void inorder(struct tree *p)
{   int i;
	if(p==NULL)
	{
		return;
	}
	else
	{
		inorder(p->left);
		for(i=0;i<strlen(p->dat);i++)
		{
			printf("%c",p->dat[i]);
		}
		inorder(p->right);
	}
}

void ep()
{	int k1,k2,l,i,o,o1;
	for(i=0;i<strlen(str);)
	{
		if(str[i]=='!' || (str[i]=='^' && (str[i+1]=='+'|| (str[i-1]=='+'))))
		{
			if(str[i-1]=='(')
			{
				o=i-1;
				o1=i+2;
				while(str[o1]!=')')
				{
					str[o]=str[o1];
					o++;
		  			o1++;
				}
				o1++;
				while(str[o1]!='\0')
				{
					str[o]=str[o1];
					o++;
					o1++;
				}
			}
			else
			{
				o=i+2;
				o1=i-1;
				l=i-1;
		 		while(str[l]!='(')
				{
					l--;
				}
				while(str[o]!='\0')
				{
					str[o1]=str[o];
					o1++;
					o++;
				}
				str[o1]='\0';
				while(str[l]!='\0')
				{
					str[l]=str[l+1];
					l++;
				}
				i=0;
			}
			str[o]='\0';
			i=0;
		}
		else if(str[i]=='^' && (str[i+1]=='.'|| str[i-1]=='.'))
		{	k2=i;
			while(str[k2]!='(')
			{
				k2--;
			}
			k1=i;
			while(str[k1]!=')')
			{
				k1++;
			}
			str[k2]='^';
			k2++;
			k1=k1+1;
			while(str[k1]!='\0')
			{
				str[k2++]=str[k1++];
			}
			str[k2]='\0';
			i=0;
		}
		else
		{
			i++;
		}
	}
}


//	Compressing the parse tree

void reg_compress(struct tree *p)
{
	if(p==NULL)
	{
		return;
	}

	reg_compress(p->left);
	reg_compress(p->right);

	//	((a*)*)=a*
	if(p->dat[0]=='*' && p->left->dat[0]=='*')
	{
		p->left=p->left->left;
	}
	//	(a*).(a*)=a*
	//	(a*)+(a*)=a*
	if((p->dat[0]=='.' || p->dat[0]=='+') && (p->left->dat[0]=='*' && p->right->dat[0]=='*'))
	{
		if((p->left->left->dat[0]!='+' && p->left->left->dat[0]!='.' && p->left->left->dat[0]!='*') && (p->right->left->dat[0]!='+' && p->right->left->dat[0]!='.' && p->right->left->dat[0]!='*'))
		{
			if(strcmp(p->left->left->dat,p->right->left->dat)==0)
			{
				p->dat[0]='*';
				p->left=p->left->left;
				p->right=NULL;
			}
		}
	}

	//	(((a*).(b*))*)=((a+b)*)
	//	(((a*)+(b*))*)=((a+b)*)
	if(p->dat[0]=='*' && (p->left->dat[0]=='+' || p->left->dat[0]=='.') && (p->left->left->dat[0]=='*' && p->left->right->dat[0]=='*'))
	{
		p->left->dat[0]='+';
		p->left->left=p->left->left->left;
		p->left->right=p->left->left;
	}

	//	a+a=a
	if(p->dat[0]=='+' && (p->left->dat[0]!='+' && p->left->dat[0]!='.' && p->left->dat[0]!='*') && (p->right->dat[0]!='+' && p->right->dat[0]!='.' && p->right->dat[0]!='*') && strcmp(p->left->dat,p->right->dat)==0)
	{
		strcpy(p->dat,p->left->dat);
		p->left=p->right=NULL;
	}

	//	a.b=ab
	if(p->dat[0]=='.' && (p->left->dat[0]!='+' && p->left->dat[0]!='.' && p->left->dat[0]!='*') && (p->right->dat[0]!='+' && p->right->dat[0]!='.' && p->right->dat[0]!='*'))
	{
		strcpy(p->dat,p->left->dat);
		strcat(p->dat,p->right->dat);
		p->left=p->right=NULL;
	}
}


	/*Searching a Regular expression in the database tree starts here*/

struct list		//structure stores the strings which are searched at a level in the 'search_reg_expr' function
{
	struct item *data;
	int start,end;
	char *str;
	int length;
	int complete;
	struct list *next;
}*ending;

struct list *search_reg_expr(struct tree *r1,struct list *l11,int flag)
{
	int i,j,k,bool11=0;
	struct list *list1,*list2,*l1,*l2;
	if(r1==NULL)
	{
		printf("ERROR 371 : Data not present in tree");
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
	{
		case'+':
			list1->next=search_reg_expr(r1->left,l1,flag);	//Keep the leftside nodes list in the next pointer of the temporary node 'temp1'
			list2->next=search_reg_expr(r1->right,l1,flag);	//Keep the rightstde nodes list in the next pointer of the temporary node 'temp2'
			for(l2=list1;l2->next->end!=1;l2=l2->next);	//Make 'l2' as the node pointing to the end of leftlist
			l2->next=list2->next;				//Append rightlist to leftlist and return
			return(list1->next);
		case'.':
			list1->next=search_reg_expr(r1->left,l1,0);	//Find left list
			if(list1->next->end==1)			//If it is empty, no need to check rightlist. Return empty list
			{
				return(ending);
			}
			l1=list1;
			l2=list2;
			do
			{
				l2->next=search_reg_expr(r1->right,l1->next,flag);
				for(;l2->next->end!=1;l2=l2->next);
				l1=l1->next;
			}while(l1->next->end!=1);
			return(list2->next);
		case'*':
			l2=search_reg_expr(r1->left,l1,0);
			if(l2->end==1 || (l2->data==l1->data && l2->start==l1->start && l2->next->end==1))	//If the string is empty, return the pointer itself
			{
				if(flag==1 && l1->complete==0)
				{
					return(ending);
				}
				else
				{
					return(l1);
				}
			}
			else if(l2->data==l1->data && l2->start==l1->start)
			{
				l1=list2=l2;
				l2=l2->next;
			}
			else
			{
				l1->next=list2=l2;
			}
			while(list2->next->end!=1)
			{
				list2=list2->next;
			}
			do
			{
				list2->next=search_reg_expr(r1->left,l2,0);
				while(list2->next->end!=1)
				{
					list2=list2->next;
				}
				l2=l2->next;
			}while(l2->end!=1);
			if(flag==0)
			{
				return(l1);
			}
			while(l1->complete!=1)
			{
				if(l1->end==1)
				{
					return(l1);
				}
				l1=l1->next;
			}
			for(l2=l1;l2->next->end!=1;)
			{
				if(l2->next->complete!=1)
				{
					l2->next=l2->next->next;
					continue;
				}
				l2=l2->next;
			}
			return(l1);
		default:
			for(i=0;r1->dat[i]!='\0';i++)	//For every char of regular expression(R.E) until R.E. is completed
			{
				for(j=l1->start;j<l1->data->datalen;j++,i++)//For every character of database tree untill tree is completed
				{
					if(r1->dat[i]=='\0')//If the R.E is completed.
					{
						if(flag==1)			//If the requirement is to send the STRING AS A WHOLE
						{
							if(bool11==1)		//If last character that is matched is the endable character in the database
							{
								goto out;			//Return all the pointers that are matched till then
							}
							else
							{
								return(ending);
							}
						}
						else
						{
							l1->start=j;
							l1->complete=bool11;
							l1->next=ending;
							return(l1);
						}
					}
					if(l1->data->info[j]!=r1->dat[i])//If the characters in the syntaxtree & data tree are unmatched(Assuming that ends of the strings are always '\0')
					{
						return(ending);
					}
					else
					{	l1->str=(char *)realloc(l1->str,((l1->length)*sizeof(char))+2);
						l1->str[l1->length]=l1->data->info[j];
						l1->str[l1->length+1]='\0';
						l1->length++;
						bool11=l1->data->bool1[j];
					}
				}
				if(r1->dat[i]=='\0')
				{
					if(flag==1)
					{
						if(bool11==1)
						{
							goto out;
						}
						else
						{
							return(ending);
						}
					}
					else
					{
						l1->start=j;
						l1->complete=bool11;
						l1->next=ending;
						return(l1);
					}
				}
				k=find(r1->dat[i]);
				if(k==NOT_A_SYMBOL || l1->data->child[k]==NOT_PRESENT)
				{
					return(ending);
				}
				else
				{
					l1->data=l1->data->child[k];
					j=l1->start=l1->end=0;
					l1->next=ending;
					i--;
				}
			}
			if(flag==1)		//can be IF((flag==1 && bool11==1) || (flag==0)) ELSE
			{
				if(bool11==1)
				{
out:
					l1->start=j;
					l1->complete=bool11;
					l1->next=ending;
					return(l1);
				}
				else
				{
					return(ending);
				}
			}
			else
			{
				l1->start=j;
				l1->complete=bool11;
				l1->next=ending;
				return(l1);
			}
	}
}


/* Searching strings for CONTEXT FREE GRAMMARS start here */
//Done on 25-9-06
//At 19hr:00min.

class prod_link		//Structure contains set of productions corresponding to each non terminal in structure 'variable'
{
	public:
		int n_prod;	//No. of productions
		char **prod;//Production strings
		prod_link()	//Initiate no. of productions to 0
		{
			n_prod=0;
		}
		void produce()	//Taking productions for the first time normally
		{
			printf("Enter no. of productions:");
			fflush(stdin);
			scanf("%d",&n_prod);
			prod=(char **)malloc(sizeof(char *) * n_prod);

			char temp[100]="";
			int i,j,temp1;

			for(i=0;i<n_prod;i++)
			{
				printf("Enter production : ");
				fflush(stdin);
				scanf("%s",temp);// ERROR : Use of 'temp' before definition
				for(temp1=0,j=0;j<i;j++)
				{
					if(strcmp(temp,prod[j])==0)
					{
						i--;
						n_prod--;
						temp1=1;
						break;
					}
				}
				if(temp1==1)
				{
					continue;
				}
				prod[i]=(char *)malloc(sizeof(char)*strlen(temp)+1);
				strcpy(prod[i],temp);
			}
		}
		void produce_automatic(char *temp)	//initiating the productions with the one that is passed to it
		{
			n_prod=1;
			prod=(char **)malloc(sizeof(char *) * n_prod);
			prod[0]=(char *)malloc(sizeof(char)*strlen(temp)+1);
			strcpy(prod[0],temp);
		}
		void add_prod(char *str)	//Adding production to the end of the present productions
		{
			int j,temp;
			for(temp=0,j=0;j<n_prod;j++)
			{
				if(strcmp(str,prod[j])==0)
				{
					temp=1;
					break;
				}
			}
			if(temp==1)
			{
				return;
			}
			n_prod++;
			prod=(char **)realloc(prod,sizeof(char *) * n_prod);
			prod[n_prod-1]=(char *)malloc(sizeof(char)*strlen(str)+1);
			strcpy(prod[n_prod-1],str);
		}
		void sub_prod(int j,char *str)	//Replaces the j'th production by 'str'
		{
			int i;
			prod[j]=(char *)realloc(prod[j],sizeof(char)*strlen(str)+1);
			strcpy(prod[j],str);
		}
		void print()	//Prints all the productions
		{
			int i;
			for(i=0;i<n_prod;i++)
			{
				printf(" %s |",prod[i]);
			}
		}
};

class variable		//Contains the variable name & the structure 'prod_link' which contains the productions
{
	public:
		char car;
		struct prod_link *p;
		void prod()	//Reads variable name & acceptance of the productions using 'produce' function in structure 'prod_link'
		{
			printf("\nEnter variable name in a single character:");
			fflush(stdin);
			scanf("%c",&car);
			p=(prod_link *)malloc(sizeof(prod_link));
			p->produce();
		}
		void prod_automatic(char left, char *right)	//Produces a node with a character & a production
		{
			car=left;
			p=(prod_link *)malloc(sizeof(prod_link));
			p->produce_automatic(right);
		}
		void print()		//Prints the productions
		{
			printf("\n%c ---> ",car);
			p->print();
		}
};

int no_var;
variable *v;

int is_terminal(char c)
{
	if(c>='a' && c<='z')
	{
		return(1);
	}
	return(0);
}
char is_production(char *str)	//checks whether the string in 'str' is on the right side of the production or not
{
	int i,j;
	for(i=0;i<no_var;i++)
	{
		for(j=0;j<v[i].p->n_prod;j++)
		{
			if(strcmp(str,v[i].p->prod[j])==0)
			{
				return(v[i].car);
			}
		}
	}
	return('\0');
}

char new_var()		// Returns new variable which is not previously assigned
{	char *c="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#$%^&*Å";	//new non-terminals
	static int i;
	int j;
	for(j=0;j<no_var;j++)
	{
		if(c[i]==v[j].car)
		{
			i++;
			j=0;
		}
	}
	if(i>=strlen(c))
	{
		perror("ERROR(750) : new variables can't be assigned");
		exit(0);
	}
	return(c[i++]);
}

int get_index(char c)	//returns index of a NON-TERMINAL
{
	int i;
	for(i=0;i<no_var;i++)
	{
		if(v[i].car==c)
		{
			return(i);
		}
	}
	return(-1);
}

void create_production(char left, char *right)	//Creates a new production with new variable 'left' on the left & 'right' on the right side of the production
{
	no_var++;
	v=(variable *)realloc(v,sizeof(variable)*no_var);	//contains variables & it's productions
	v[no_var-1].prod_automatic(left,right);
}

void elim_unit()		//Elimination of unit productions
{
	int i,j,k,l,m;
	variable v1;

	for(i=0;i<no_var;i++)
	{
		for(j=0;j<v[i].p->n_prod;j++)
		{
			if(strlen(v[i].p->prod[j])==1 && (m=get_index(v[i].p->prod[j][0]))!=-1)
			{
				v1.p=(prod_link *)malloc(sizeof(prod_link));
				v1.p->n_prod=0;
				v1.p->prod=(char **)malloc(sizeof(char *));
				v1.car=v[i].car;
				for(k=0;k<v[i].p->n_prod;k++)
				{
					if(k!=j)
					{
						v1.p->add_prod(v[i].p->prod[k]);
					}
					else
					{
						for(l=0;l<v[m].p->n_prod;l++)
						{
							if((v1.car!=v[m].p->prod[l][0]) || (strlen(v[m].p->prod[l])!=1))
							{
								v1.p->add_prod(v[m].p->prod[l]);
							}
						}
					}
				}
				v[i]=v1;
				j=-1;
			}
		}
	}
}

void before_gnf()		//Required form for GNF. Eg : 'A->aBcD' is converted to 'A->aBCD','C->c'
{
	int i,j,k;			//i.e convert terminals in the middle of the production with non terminals. i.e. every production should have one terminal or any no. of non-terminals only
	char *temp="00",temp1;
	for(i=0;i<no_var;i++)
	{
		for(j=0;j<v[i].p->n_prod;j++)
		{
			if(strlen(v[i].p->prod[j])==1)	//if production is of the form A->a, then noneed to reduce terminals
			{
				if(is_terminal(v[i].p->prod[j][0]))
				{
					continue;
				}
				else
				{
					printf("ERROR(807) : NOT PROPER GRAMMAR (encountered UNIT productions in CNF) %s at %d %d %d",v[i].p->prod[j],i,j,no_var);
					exit(0);
				}
			}
			for(k=1;v[i].p->prod[j][k]!='\0';k++)	//for each character of the production
			{
				if(is_terminal(v[i].p->prod[j][k]))
				{
					temp[0]=v[i].p->prod[j][k];	//'temp' string contains the right side of the production
					temp[1]='\0';
					if((temp1=is_production(temp))!='\0');
					else
					{
						temp1=new_var();			//'temp1' char contains a new variable
						create_production(temp1,temp);	//creates new production 'temp1' on left & 'temp' on right of the production
					}
					v[i].p->prod[j][k]=temp1;
				}
			}
		}
	}
}

void lemma1(int i,int j)	// 'i' is the variable index & 'j' is it's production index. Replaces the first variable with it's productions for i'th variable's j'th production
{   int k,l;
	char c,*temp;
	c=v[i].p->prod[j][0];
	for(k=0;k<no_var;k++)	//finding the position of the first variable of the production
	{
		if(v[k].car==c)
		{
			break;
		}
	}
	for(l=0;l<v[k].p->n_prod;l++)
	{
		temp=(char *)malloc(sizeof(char) * (strlen(v[k].p->prod[l])+strlen(v[i].p->prod[j])) + 1);
		strcpy(temp,v[k].p->prod[l]);
		strcat(temp,v[i].p->prod[j]+1);
		if(l==v[k].p->n_prod-1)
		{
			v[i].p->sub_prod(j,temp);
		}
		else
		{
			v[i].p->add_prod(temp);
		}
	}
}

void lemma2(int k)
{
	char c;
	char *str="";
	int i,j;

	variable v1;
	variable v2;
	c=new_var();
	v1.car=c;
	v2.car=v[k].car;
	no_var++;
	v1.p=(prod_link *)malloc(sizeof(prod_link));
	v1.p->n_prod=0;
	v1.p->prod=(char **)malloc(sizeof(char *));
	v2.p=(prod_link *)malloc(sizeof(prod_link));
	v2.p->n_prod=0;
	v2.p->prod=(char **)malloc(sizeof(char *));

	// A -> Aa1|Aa2|Aa3|Aa4|..........|Aan
	// A -> b1|b2|b3|b4|..........|bm
	for(i=0;i<v[k].p->n_prod;i++)
	{
		if(v[k].car==v[k].p->prod[i][0])	// Z -> ai | aiZ (1<=i<=n)
		{
            v1.p->add_prod(v[k].p->prod[i]+1);
			str=(char *)realloc(str,strlen(v[k].p->prod[i]) * sizeof(char) + 2);	//ERROR : while allocating memory to 'str'
			strcpy(str,v[k].p->prod[i]+1);
			j=strlen(str);
			str[j]=c;
			str[j+1]='\0';
			v1.p->add_prod(str);
		}
		else								// A -> bi|biZ (1<=i<=m)
		{
			v2.p->add_prod(v[k].p->prod[i]);
			str=(char *)realloc(str,sizeof(char) * strlen(v[k].p->prod[i]) + 2);
			strcpy(str,v[k].p->prod[i]);
			j=strlen(str);
			str[j]=c;
			str[j+1]='\0';
			v2.p->add_prod(str);
		}
	}
	v=(variable *)realloc(v,sizeof(variable)*no_var);	//contains variables & it's productions
	v[no_var-1]=v1;
	v[k]=v2;
}
void gnf()		//Reducing the given CFG(Context Free Grammar) to GNF(Griebach Normal Form)
{
	int i,j,k,l;
	for(i=0;i<no_var;i++)	//Transform the productions whith left variable index greater than right variable index
	{
		for(j=0;j<v[i].p->n_prod;j++)
		{
			if(is_terminal(v[i].p->prod[j][0]))
			{
				continue;
			}
			k=get_index(v[i].car);
			l=get_index(v[i].p->prod[j][0]);
			if(k==-1 || l==-1)
			{
				printf("ERROR(955) : Variable not present %c : %d : %d : %s : %d : %d",v[i].car,j,v[i].p->n_prod,v[i].p->prod[j],k,l);
				exit(0);
			}
			else if(k>l)		// If left variable index greater than right variable index
			{
                 lemma1(i,j);
                 j=-1;
			}
			else if(k==l)		// If left variable index equal to right variable index
			{
				lemma2(i);
				j=-1;
			}
		}
	}
	for(i=0;i<no_var;i++)		//Transform the productions whith left variable index less than right variable index
	{
		for(j=0;j<v[i].p->n_prod;j++)
		{
			if(is_terminal(v[i].p->prod[j][0]))
			{
				continue;
			}
			k=get_index(v[i].car);
			l=get_index(v[i].p->prod[j][0]);
			if(k==-1 || l==-1)
			{
				printf("ERROR (1019) : Variable (%c or %c) not present",v[i].car,v[i].p->prod[j][0]);
				exit(0);
			}
			else if(k<l)
			{
				lemma1(i,j);
			}
			else
			{
				perror("ERROR (248) : i>j format");
				exit(0);
			}
		}
	}
}

struct list *search_cfg(char *s,struct list *p)	//Searching CFG which is in GNF with Database tree
{
	int i,k,found;
	char *str;
	struct list *p1=(struct list *)malloc(sizeof(struct list));
	struct list *p2=(struct list *)malloc(sizeof(struct list));
	struct list *p3=(struct list *)malloc(sizeof(struct list));

		/* copying 'p' to 'p1' */
	p1->data=(struct item *)malloc(sizeof(struct item *));
	p1->next=(struct list *)malloc(sizeof(struct list *));
	p1->data=p->data;
	p1->start=p->start;
	p1->end=p->end;
	p1->str=(char *)malloc(((p->length)*sizeof(char))+2);
	strcpy(p1->str,p->str);
	p1->length=p->length;
	p1->complete=p->complete;
	p1->next=ending;

	if(is_terminal(s[0]))	/* if the first alphabet in the production is a terminal */
	{
		while(p1->start>=p1->data->datalen)	/* data in the present 'data node' is complete, go to the child node */
		{
			k=find(s[0]);
			if(k==NOT_A_SYMBOL || p1->data->child[k]==NOT_PRESENT)
			{
				return(ending);
			}
			else
			{
				p1->data=p1->data->child[k];
				p1->start=0;
			}
		}
		if(s[0]!=p1->data->info[p1->start])
		{
			return(ending);
		}
		p1->str=(char *)realloc(p1->str,(sizeof(char) * (p1->length))+2);
		p1->str[p1->length]=s[0];
		p1->length++;
		p1->str[p1->length]='\0';
		p1->start++;
		if(s[1]=='\0')	/* if the given string is of the form S->a */
		{
			//if(p1->data->bool1[p1->start-1]==1)/* if the string is accepted */
			//{
			//	p1->end=1;
				return(p1);
			//}
			//else				/* if the string is not accepted */
			//{
			//	return(ending);
			//}
		}
		else	/* if the given string is of the form S->aB */
		{
			p1->end=0;
			return(search_cfg(s+1,p1));
		}
	}
	else		/* if the first alphabet in the production is a non-terminal */
	{
		for(found=-1,i=0;i<no_var;i++)
		{
			if(s[0]==v[i].car)
			{
				found=i;
				break;
			}
		}
		if(found==-1)
		{
			perror("Error: Variable not present in the given productions");
			return(ending);
		}
		p2=p3;
		p3->next=ending;
		str=(char *)malloc(sizeof(char));
		for(int i=0;i<v[found].p->n_prod;i++)	/* for every production of variable */
		{
			for(;p3->next!=ending;p3=p3->next);
			str=(char *)realloc(str,(strlen(v[found].p->prod[i])*sizeof(char))+(strlen(s+1)*sizeof(char))+2);
			strcpy(str,v[found].p->prod[i]);
			strcat(str,s+1);
			p3->next=search_cfg(str,p1);
		}
		return(p2->next);
	}
}

void cfg(struct list *l1)		//Reduces the given CFG in to GNF & searches it in the data base tree
{
	struct list *l2;
	int i;
	char c[2];

	printf("\nEnter no. of variables:");
	scanf("%d",&no_var);
	v=(variable *)malloc(sizeof(variable)*no_var);	//contains variables & it's productions
	printf("{ The first variable should always be a START variable }");
	for(i=0;i<no_var;i++)
	{
		v[i].prod();			//creates productions for variable
	}
	printf("\nProductions before reduction are:");
	for(i=0;i<no_var;i++)
	{
		v[i].print();
	}
	// modifying the grammar starts here
	elim_unit();
	printf("\nProductions after elimination of unit productions are:");
	for(i=0;i<no_var;i++)
	{
		v[i].print();
	}
	before_gnf();
	printf("\nProductions after 'before gnf' are:");
    for(i=0;i<no_var;i++)
	{
		 v[i].print();
	}
    gnf();
	printf("\nProductions after GNF are:");
	for(i=0;i<no_var;i++)
	{
		v[i].print();
	}
	// modifying the grammar ends here

	//searching the grammar with data tree
	fflush(stdin);
	printf("\n\nEnter START SYMBOL (any variable) : ");
	scanf("%c",&c[0]);c[1]='\0';	//Deciding the start symbol
	l2=search_cfg(c,l1);
	printf("\n==========================");
	printf("\nFor CFG, the language is :");
	printf("\n==========================");
	for(;l2!=ending;l2=l2->next)
	{
		printf("\n\t%s",l2->str);
	}
	printf("\n==========================");
}

/*RAVI's work for CFG end here*/


	/* Main Program begins */

int main()
{
	int i,j,checkcnt;
	char s[100];
	struct list *l1,*l2;
	printf("\nEnter the number of symbols in the alphabet: ");
	scanf("%d",&alphanum);
	root=(struct item *)malloc(sizeof(struct item));
	root->child=(struct item **)malloc(alphanum*sizeof(struct item*));
	root->info=(char *)malloc(sizeof(char));
	root->info[0]='\0';
	root->datalen=0;
	printf("Enter the Symbol of Alphabet and Press Enter:\n(Terminals should be lower case alphabets only)\n");
	fflush(stdin);
	for(i=0;i<alphanum;i++)
	{
		scanf("%c",&alpha[i]);
		fflush(stdin);
	}
	for(i=0;i<alphanum;i++)
	{
		root->child[i]=NOT_PRESENT;
	}
	/* Simple acceptance of strings
	printf("Enter number of Strings: ");
	int n1;
	scanf("%d",&n1);
	root1=root;
	for(i=0;i<n1;i++)
	{
		root=root1;
		printf("Enter the string : ");
		scanf("%s",s);
		fflush(stdin);
		create(s,root);
	}
	*/

		// Construction of SUFFIX TREE from a Text (instead of simple acceptance of strings)
	printf("Enter the text : ");
	scanf("%s",s);
	root1=root;
	for(i=0;s[i]!='\0';i++)
	{
		root=root1;
		fflush(stdin);
		create(s+i,root);
	}

//	printf("Database Tree before compression\n");
//	printroot(root1);
	rootcompress(root);
//	printf("Database Tree After comression\n");
//	printroot(root1);
	printf("Enter Regular Expression (! for EPSILON and ^ for PHI) : ");
	scanf("%s",str);
	fflush(stdin);
	ep();
	if(strlen(str)==1 && str[0]=='^')
	{
		printf("Result is PHI");
		return(0);
	}
	for(i=0;i<strlen(str);i++)
	{
		checkcnt=0;
		for(j=0;j<alphanum;j++)
		{
			if(str[i]==alpha[j]||str[i]==')'||str[i]=='('||str[i]=='*'||str[i]=='.'||str[i]=='+')
			{
				checkcnt++;
			}
		}
		if(checkcnt==0)
		{
			perror("ERROR");
			getch();
			exit(0);
		}

	}
	check(str);	//Error: NULL POINRTER ASSIGNMENT ERROR
	fflush(stdin);
	construct();	//ERROR : when "(a.((bc)*))" is given, '(' is the 'a' left child in the tree
	ptree=stack[0].node ;
	reg_compress(ptree);	//R.E. compress functions by ravi
//	printf("In order traversal\n");
//	inorder(ptree);

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
*/
	//	Search strings for the Regular Expression
	l1->next=search_reg_expr(ptree,l1,0);

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
	{
		printf("\n\t%s",l2->next->str);
		l2=l2->next;
	}
	printf("\n=====================================");

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
	cfg(l1);

	getch();
	return(0);
}













void for_all_nodes(struct item *p)
{
	int i,j;
	struct item *c;
	for(i=0;i<alphanum;i++)
	{
		if(p->child[i]!=NOT_PRESENT)
		{
			c=p->child[i];
			for(j=0;j<c->datalen;j++)
			{
				printf("%c  ",c->info[j]);//c->bool1[j]);
			}
			for_all_nodes(p->child[j]);
		}
	}
}
