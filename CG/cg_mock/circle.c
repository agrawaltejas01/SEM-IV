#include <stdio.h>
//#include <iostream>
#include <GL/glut.h>
#include<math.h>
//using namespace std;

int Xc, Yc, x, y, r;

void setpixel(int x,int y)
{
	glVertex2f(x,y);
}

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+Xc, y+Yc);
	glEnd();
}

void brez(int x1,int y1,int x2,int y2)	{
	glBegin(GL_LINES);
	int p,ddx,ddy,ddxdy;
	int dx=abs(x2-x1);
	int dy=abs(y2-y1);
	int kx=dx;
	int ky=dy;
	int x,y;
	x=x1;y=y1;
	if(dy<dx)	{
		p=2*dy-dx;
		setpixel(x,y);
		while(kx!=0)	{
			if(x2>x1)	x++;
			else	x--;
			if(p<0)	{
			p=p+2*dy;
			}
			else	{
			if(y2>y1)	y++;
				else	y--;
				p=p+2*dy-2*dx;
			}
			setpixel(x,y);
			kx--;
		}
	}
	else	{
		p=2*dx-dy;
		setpixel(x,y);
		while(ky!=0)	{
			if(y2>y1)	y++;
			else	y--;
			if(p<0)	{
				p=p+2*dx;
			}
			else	{
				if(x2>x1)	x++;
				else	x--;
				p=p+2*dx-2*dy;
			}
			setpixel(x,y);
			ky--;
		}
	}
	glEnd();
}

void myInit (void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}

void circlemid(int x, int y, int r)
{
	x = 0;
	y = r;
	float p = 5/4 - r;

	plot(x,y);

	while(x < y)
	{
		if(p < 0)
		{
			x++;
			p += 2*x+1;
		}
		else
		{
			x++;
			y--;
			p += 2*(x-y)+1;
		}
		plot(x,y);	plot(x,-y);
		plot(-x,-y);	plot(-x,y);
		plot(y,x);	plot(y,-x);
		plot(-y,-x);	plot(-y,x);
	}
}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	circlemid(x,y,r);

	glColor3f(0.5f, 1.0f, 1.0f);
	brez(Xc-sqrt(3)*r,Yc-r,Xc+sqrt(3)*r,Yc-r);
	brez(Xc-sqrt(3)*r,Yc-r,Xc,Yc+2*r);
	brez(Xc+sqrt(3)*r,Yc-r,Xc,Yc+2*r);

	glColor3f(1.0f, 0.5f, 1.0f);
	circlemid(x,y,2*r);
	glFlush ();
}

int main(int argc, char** argv)
{	
	printf("Enter the coordinates of the center:\n\n");
	printf("X-coordinate   : "); scanf("%d",&Xc);
	printf("\nY-coordinate   : "); scanf("%d",&Yc);
	printf("\nEnter radius : "); scanf("%d",&r);

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Line Drawing Alogrithms");
	myInit ();
	glutDisplayFunc(myDisplay);
	//myInit ();
	glutMainLoop();
return 0;
}
