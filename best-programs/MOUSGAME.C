/*							    MOUSE BALL GAME									*/

/*written by K.V.V.N.RAVI SHANKAR of GAYATRI COLLEGE OF ENGINEERING(II/IV CSE dept.)*/
/*	written in BORLAND C++ version*/

/*	program that moves two objects (ball and stick) at a time without any
	DEADLOCK using a plain C program (This is similar to MULTITASKING concept)
	using only data_variables and loops.*/

#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdio.h>
void main(int argc,char * argv[])
{	int GRA_DRIVER,GRA_MODE;			/*graphics initialization variables*/
	int CIRCLE_HORIZONTAL=0,CIRCLE_VERTICAL=0;/*circle's horizontal and vertical motion are
											 stored in these variables as 0(RIGHT/DOWN)
											 and 1(LEFT/UP)*/
									/*THE COORDINATES USED ARE IN PIXELS*/
	int BAR_X=100,BAR_Y=450;			/*rectangle's coordinates*/
	int CIRCLE_X=0,CIRCLE_Y=0;			/*circle's coordinates*/
	int TIME=0;						/*clock variable which acts as a clock*/
	int CIR_PERIOD=1;		            /*no of periods the circle waits(acts as quality)*/
	int SCORE=0;
	int REFRESH=20;  					/*acts like refresh rate of the screen*/
	char CIR_INC=3;					/*incremental value of circle's coordinates*/
	static char BUTTON;
	union REGS i,o;

	clrscr();
	detectgraph(&GRA_DRIVER,&GRA_MODE);
	initgraph(&GRA_DRIVER,&GRA_MODE,"c:\\tc\\bgi");/*the screen is changed to graphics mode.*/

	i.x.ax=0;          				/*mouse initialization*/
	int86(0x33,&i,&o);
/*	i.x.ax=1;
	int86(0x33,&i,&o);
	i.x.ax=15;
	i.x.cx=1000;
	i.x.dx=1000;
	int86(0x33,&i,&o);
*/
	printf("\n\n\t\t\tGRAPHICS PROGRAM");
	gotoxy(15,5);
	/*printf("Enter quality(10 to 50):-");
	scanf("%d",&CIR_PERIOD);*/
	printf("Enter speed(1 to 50 in decreasing order of speed):-");
	scanf("%d",&REFRESH);

	setfillstyle(1,2);
	settextstyle(4,0,4);
	for(TIME=0;BUTTON!=13;TIME++)          /*loop ends if KEY=13 (13 is scancode for ENTER KEY*/
	{	delay(REFRESH);
		if(TIME==CIR_PERIOD)    		 /*for every period no of times the circle's
										   coordinate values are updated.*/
		{	TIME=0;
			if(CIRCLE_HORIZONTAL==0)	 /*checks if circle is moving RIGHT*/
			{	CIRCLE_X+=CIR_INC;		 /*increases circle's X coordinate*/
				if(CIRCLE_X>=635)		 /*if maximum X coordinate(635) is reached*/
					CIRCLE_HORIZONTAL=1; /*the circle is set to move left
										   i.e. decrease X coordinate*/
			}
			if(CIRCLE_HORIZONTAL==1)	 /*checks if circle is moving LEFT*/
			{	CIRCLE_X-=CIR_INC;		 /*decreases circle's X coordinate*/
				if(CIRCLE_X<=5)			 /*if minimum X coordinate(5) is reached*/
					CIRCLE_HORIZONTAL=0; /*the circle is set to move right
										   i.e. increase X coordinate*/
			}
			if(CIRCLE_VERTICAL==0)		 /*checks if circle is moving DOWN*/
			{	CIRCLE_Y+=CIR_INC;		 /*increases circle's Y coordinate*/
				if(CIRCLE_Y>=460)		 /*if circle touches BOTTOM,then stop the game*/
					break;
				else if((CIRCLE_Y+5>=BAR_Y&&CIRCLE_Y+5<=BAR_Y+10)&&CIRCLE_X>=BAR_X&&CIRCLE_X<=BAR_X+50)
				{						 /*if rectangle is touched,set the circle to go UP*/
					sound(500);
					delay(30);
					nosound();
					SCORE++;
					CIRCLE_VERTICAL=1;	 /*set circle to move UP*/
				}
			}
			if(CIRCLE_VERTICAL==1)		 /*checks if circle is moving UP*/
			{	CIRCLE_Y-=CIR_INC;		 /*decreases circle's Y coordinate*/
				if(CIRCLE_Y<=5)
				{						 /*if TOP is touched,set the circle to go DOWN*/
					sound(500);
					delay(10);
					nosound();
					CIRCLE_VERTICAL=0;	 /*set the circle to go DOWN*/
				}
			 }
		}
		i.x.ax=3;               		/*to get status of x,y coordinates*/
		int86(0x33,&i,&o);
		BUTTON=o.x.bx;
		BAR_X=(o.x.cx);
		BAR_Y=(o.x.dx);
		cleardevice();
		gotoxy(10,3);
		printf("Score is %d",SCORE);
		bar(BAR_X,BAR_Y,BAR_X+50,BAR_Y+10);/*draws a recangle of length 50 & width 10*/
		circle(CIRCLE_X,CIRCLE_Y,10);	 /*draws a circle of radius 5*/
	}
	cleardevice();
	outtextxy(225,220,"GAME OVER");
	getch();
	closegraph();                       /*closes the graphics mode*/
	execv("win.exe",argv);
}										/*end of MAIN program*/