/*There are 15 steps. A person is starting from
the bottom climbing to the top. A person can climb,
at a time, one, two or three steps. In how many
ways can he climb the steps and reach the top?*/
void main()
{ int tot=0,x[15];
  for(x[0]=1;x[0]<=3;x[0]++)
  { if(x[0]>=15){ tot++;break;}
	for(x[1]=1;x[1]<=3;x[1]++)
	{ if(x[0]+x[1]>=15){ tot++;break;}
	  for(x[2]=1;x[2]<=3;x[2]++)
	  { if(x[0]+x[1]+x[2]>=15){ tot++;break;}
		for(x[3]=1;x[3]<=3;x[3]++)
		{ if(x[0]+x[1]+x[2]+x[3]>=15){ tot++;break;}
		  for(x[4]=1;x[4]<=3;x[4]++)
		  { if(x[0]+x[1]+x[2]+x[3]+x[4]>=15){ tot++;break;}
			for(x[5]=1;x[5]<=3;x[5]++)
			{ if(x[0]+x[1]+x[2]+x[3]+x[4]+x[5]>=15){ tot++;break;}
			  for(x[6]=1;x[6]<=3;x[6]++)
			  { if(x[0]+x[1]+x[2]+x[3]+x[4]+x[5]+x[6]>=15){ tot++;break;}
				for(x[7]=1;x[7]<=3;x[7]++)
				{ if(x[0]+x[1]+x[2]+x[3]+x[4]+x[5]+x[6]+x[7]>=15){ tot++;break;}
				  for(x[8]=1;x[8]<=3;x[8]++)
				  { if(x[0]+x[1]+x[2]+x[3]+x[4]+x[5]+x[6]+x[7]+x[8]>=15){ tot++;break;}
					for(x[9]=1;x[9]<=3;x[9]++)
					{ if(x[0]+x[1]+x[2]+x[3]+x[4]+x[5]+x[6]+x[7]+x[8]+x[9]>=15){ tot++;break;}
					  for(x[10]=1;x[10]<=3;x[10]++)
					  { if(x[0]+x[1]+x[2]+x[3]+x[4]+x[5]+x[6]+x[7]+x[8]+x[9]+x[10]>=15){ tot++;break;}
						for(x[11]=1;x[11]<=3;x[11]++)
						{ if(x[0]+x[1]+x[2]+x[3]+x[4]+x[5]+x[6]+x[7]+x[8]+x[9]+x[10]+x[11]>=15){ tot++;break;}
						  for(x[12]=1;x[12]<=3;x[12]++)
						  { if(x[0]+x[1]+x[2]+x[3]+x[4]+x[5]+x[6]+x[7]+x[8]+x[9]+x[10]+x[11]+x[12]>=15){ tot++;break;}
							for(x[13]=1;x[13]<=3;x[13]++)
							{ if(x[0]+x[1]+x[2]+x[3]+x[4]+x[5]+x[6]+x[7]+x[8]+x[9]+x[10]+x[11]+x[12]+x[13]>=15){ tot++;break;}
							  for(x[14]=1;x[14]<=3;x[14]++)
							  { if(x[0]+x[1]+x[2]+x[3]+x[4]+x[5]+x[6]+x[7]+x[8]+x[9]+x[10]+x[11]+x[12]+x[13]+x[14]>=15){ tot++;break;}
							  }
							}
						  }
						}
					  }
					}
				  }
				}
			  }
			}
		  }
		}
	  }
	}
  }
  printf("%d",tot);
}