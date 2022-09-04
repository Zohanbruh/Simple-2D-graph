#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>


	int mmx,mmy;
	int n,i,mx,my,x[50],y[50],col[50];

void title()
{

	printf("---***************************************||SIMPLE 2D GRAPH||********************************************---\n");
	printf("---*******************************************************************************************************---\n");
}
char* tostr(int n)
{
	char * ch;
	itoa(n,ch,10);
	return ch;
}

void ini()
{
	title();
	printf("Enter the number of plots : ");
	scanf("%d",&n);
	printf("Please enter maximum X and Y coordinates : ");
	scanf("%d %d",&mx,&my);
	mmx=0.1*mx;
	mmy=0.1*my;
	printf("Please enter positive numbers.\nEnter the plots in format : <x-coordinate> <y-coordinate> <color>\nColor options are 1-Blue, 2-Green, 3-Cyan, 4-Red, 5-Magenta.\n");
	for(i=0;i<n;i++)
	{     re:
		scanf("%d %d %d",&x[i],&y[i],&col[i]);
		if(x[i]>0 && x[i]<=mx && y[i]>0 && y[i]<=my && col[i]>0 && col[i]<6)
		{
		}
		else
		{
			printf("Error ");
			goto re;
		}
	}
	return;
}


void initial()
{


	settextstyle(BOLD_FONT,HORIZ_DIR,2);
	outtextxy(275,0,(char*)"SCATTER GRAPH");

	setlinestyle(SOLID_LINE,0,2);
	// Draw X and Y Axis
	line(90,410,90,50);
	line(90,410,590,410);
	line(85,60,90,50);
	line(95,60,90,50);
	line(585,405,590,410);
	line(585,415,590,410);

	outtextxy(55,60,(char*)"Y");
	outtextxy(580,430,(char*)"X");
	outtextxy(60,430,(char*)"0");

	// Markings in Y axis
	outtextxy(70,378,(char*)tostr(mmy));
	outtextxy(70,346,(char*)tostr(2*mmy));
	outtextxy(70,314,(char*)tostr(3*mmy));
	outtextxy(70,282,(char*)tostr(4*mmy));
	outtextxy(70,250,(char*)tostr(5*mmy));
	outtextxy(70,218,(char*)tostr(6*mmy));
	outtextxy(70,186,(char*)tostr(7*mmy));
	outtextxy(70,154,(char*)tostr(8*mmy));
	outtextxy(70,122,(char*)tostr(9*mmy));
	outtextxy(60,90,(char*)tostr(10*mmy));

    line(80,378,90,378);
    line(80,346,90,346);
    line(80,314,90,314);
    line(80,282,90,282);
    line(80,250,90,250);
    line(80,218,90,218);
    line(80,186,90,186);
    line(80,154,90,154);
    line(80,122,90,122);
    line(80,90,90,90);


	// Markings in X axis

	outtextxy(140,420,(char*)tostr(mmx));
	outtextxy(190,420,(char*)tostr(2*mmx));
	outtextxy(240,420,(char*)tostr(3*mmx));
	outtextxy(290,420,(char*)tostr(4*mmx));
	outtextxy(340,420,(char*)tostr(5*mmx));
	outtextxy(390,420,(char*)tostr(6*mmx));
	outtextxy(440,420,(char*)tostr(7*mmx));
	outtextxy(490,420,(char*)tostr(8*mmx));
	outtextxy(540,420,(char*)tostr(9*mmx));
	outtextxy(590,420,(char*)tostr(10*mmx));

    line(140,420,140,410);
    line(190,420,190,410);
    line(240,420,240,410);
    line(290,420,290,410);
    line(340,420,340,410);
    line(390,420,390,410);
    line(440,420,440,410);
    line(540,420,540,410);
    line(590,420,590,410);
    line(490,420,490,410);
}



int main()
{
	int gd = DETECT,gm;
	float cx,cy;
	initgraph(&gd, &gm, (char*)"");
	ini();
	//clrscr();
	cleardevice();
	initial();


	for(i=0;i<n;i++)
	{
		setcolor(col[i]);
		cx=90+((500/mx)*x[i]);
		cy=410-((360/my)*y[i]);
		circle(cx,cy,2);
		setfillstyle(1,col[i]);
	       floodfill(cx,cy,col[i]);
	}

	getch();
	closegraph();
	return 0;
}
