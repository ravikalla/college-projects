/*6 people got on a train at its starting point.
There are 12 stations on which they can get off
(excluding the starting point. What is the total
number of different ways they can do this
considering that at least 4 people get off
at least at one station?
*/
void main()
{	static int rem,st[12],four_st,four,count;
	for(four_st=0;four_st<12;four_st++)
	{	for(four=4;four<=6;four++)
		{   rem=6-four;
			if(rem==0)
			{	count++;
				break;
			}
			for(st[0]=0;st[0]<=6-four;st[0]++)
			{   if(four_st!=0)
					rem-=st[0];
				if(rem==0)
				{	count++;
					break;
				}
				for(st[1]=0;st[1]<=6-four;st[1]++)
				{   if(four_st!=1)
						rem-=st[1];
					if(rem==0)
					{	count++;
						break;
					}
					for(st[2]=0;st[2]<=6-four;st[2]++)
					{   if(four_st!=2)
							rem-=st[2];
						if(rem==0)
						{	count++;
							break;
						}
						for(st[3]=0;st[3]<=6-four;st[3]++)
						{   if(four_st!=3)
								rem-=st[3];
							if(rem==0)
							{	count++;
								break;
							}
							for(st[4]=0;st[4]<=6-four;st[4]++)
							{   if(four_st!=4)
									rem-=st[4];
								if(rem==0)
								{	count++;
									break;
								}
								for(st[5]=0;st[5]<=6-four;st[5]++)
								{   if(four_st!=5)
										rem-=st[3];
									if(rem==0)
									{	count++;
										break;
									}
									for(st[6]=0;st[6]<=6-four;st[6]++)
									{   if(four_st!=6)
											rem-=st[6];
										if(rem==0)
										{	count++;
											break;
										}
										for(st[7]=0;st[7]<=6-four;st[7]++)
										{   if(four_st!=7)
												rem-=st[7];
											if(rem==0)
											{	count++;
												break;
											}
											for(st[8]=0;st[8]<=6-four;st[8]++)
											{   if(four_st!=8)
													rem-=st[8];
												if(rem==0)
												{	count++;
													break;
												}
												for(st[9]=0;st[9]<=6-four;st[9]++)
												{   if(four_st!=9)
														rem-=st[9];
													if(rem==0)
													{	count++;
														break;
													}
													for(st[10]=0;st[10]<=6-four;st[10]++)
													{   if(four_st!=10)
															rem-=st[10];
														if(rem==0)
														{	count++;
															break;
														}
														for(st[11]=0;st[11]<=6-four;st[11]++)
														{   if(four_st!=11)
																rem-=st[11];
															if(rem==0)
															{	count++;
																break;
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
	printf("total is =%d",count);
	getch();
}