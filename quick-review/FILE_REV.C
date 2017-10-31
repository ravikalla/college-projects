#include<stdio.h>
main()
{	FILE *p1,*p2;int i=0,j=0;char ch,a[50];
	scanf("%s",&a);
	p1=fopen("reverse","w");
	fprintf(p1,"%s",a);
	fclose(p1);

	p1=fopen("reverse","r");
	p2=fopen("rev","w");
	while(!feof(p1))
	{	ch=fgetc(p1);
		j++;
	}
	for(i=j;i!=0;i--)
	{	fseek(p1,i,0);
		ch=fgetc(p1);
		fputc(ch,p2);
	}
	getche();
}