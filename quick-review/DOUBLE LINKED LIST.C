struct node
{	int num;
	struct node *l,*r;
}*start,*end;
void main()
{	char a,mainmenu();
	void create(),display(),insert(),del();
	clrscr();
	while(1)
	{	clrscr();
		a=mainmenu();
		switch (a)
		{	case '1':create();
				break;
			case '2':display();
				break;
			case '3':insert();
				break;
			case '4':del();
				break;
			case '5':exit(0);
		}
	}
}
char mainmenu()
{	printf("\n\t\t1.Create node.\n\t\t2.Display all nodes.\n\t\t3.Insert node\n\t\t4.Delete node.\n\t\t5.Exit.\n\t\tEnter your choice:-");
	return(getche());
}
void create()
{	struct node *p;
	start=end='\0';
	do
	{     p=(struct node *)malloc(sizeof(struct node));
		printf("\nEnter an element:-");
		scanf("%d",&(p->num));
		if(start=='\0')
		{	p->l=p->r='\0';
			start=end=p;
		}
		else
		{	end->r=p;
			p->l=end;
			end=p;
			end->r='\0';
		}
		printf("Do you continue:-");
	}while('y'==tolower(getche()));
}
void display()
{	struct node *p;
	char c;
	printf("\nHow to display(from [l]eft/from [r]ight):-");
	flushall();
	c=getchar();
	if(c=='l')
		for(p=start;p!='\0';p=p->r)
			printf("==>%d",p->num);
	if(c='r')
		for(p=end;p!='\0';p=p->l)
			printf("==>%d",p->num);
	getch();
}
void insert()
{	struct node *p,*a=start;
	int i,j;
	printf("\nWhich number to be inserted:-");
	scanf("%d",&i);
	p=(struct node *)malloc(sizeof(struct node));
	p->num=i;
	printf("Where to be inserted:-");
	scanf("%d",&i);
	for(j=1;j<i;j++)
		a=a->r;
	p->l=a->l;
	p->r=a;
	a->l->r=p;
	a->l=p;
}
void del()
{	struct node *p=start;
	int i,j;
	printf("\nWhich node to be deleted:-");
	scanf("%d",&i);
	if(i==1)
	{	start=start->r;
		start->l='\0';
		free(p);
	}
	else
	{	for(j=1;j!=i;j++,p=p->r);
		p->r->l=p->l;
		p->l->r=p->r;
		free(p);
	}
}