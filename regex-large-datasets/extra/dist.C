/*Name: K.V.V.N.Ravi Shankar
  Date: 04/02/07 22:54
  Description: Basic program to find distances between two strings
*/
int dist(char *c1,char *c2)	//'c1' and 'c2' contain the strings for finding distance between them
{   int n1,n2,n3;
	if(strlen(c1)==0)
		return(strlen(c2));
	else if(strlen(c2)==0)
		return(strlen(c1));
	else if(c1[0]==c2[0])
		return(dist(c1+1,c2+1));

	n1=1+dist(c1+1,c2);//deletion
	n2=1+dist(c1+1,c2+1);//substitution
	n3=1+dist(c1,c2+1);//insert

	if(n1<=n2 && n1<=n3)
		return(n1);
	else if(n2<=n1 && n2<=n3)
		return(n2);
	else if(n3<=n1 && n3<=n2)
		return(n3);
}
void main()
{   printf("Distance is : %d",dist("vinters","writers"));
}
