//Mouse Handling
//2918
#include<GL/freeglut.h>
#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
struct pixel	{//pixel structure
	GLbyte red,green,blue;
}e,f,b,a;

int ch=1,xp,yp;

struct Point	{//point structure
	int x;
	int y;
}p[50];
int i=0;
void point(int x,int y)//point insert
{
	glVertex2f(x,y);
}
void boundry_fill(int x,int y)//boundary fill algorithm
{
	glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,&e);//read pixel
	if((e.red!=b.red || e.green!=b.green || e.blue!=b.blue) && (e.red!=a.red || e.green!=a.green || e.blue!=a.blue))
	{
		glColor3ub(a.red,a.green,a.blue);
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
	glFlush();
		boundry_fill(x+1,y);
		boundry_fill(x-1,y);
		boundry_fill(x,y+1);
		boundry_fill(x,y-1);
	}
	glFlush();
}
void draw()//pallete drawing
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);

	glColor3ub(244,67,54);glVertex2f(100,100);glVertex2f(100,125);glVertex2f(125,125);glVertex2f(125,100);
	glColor3ub(233,30,99);glVertex2f(126,100);glVertex2f(126,125);glVertex2f(150,125);glVertex2f(150,100);
	glColor3ub(156,39,176);glVertex2f(151,100);glVertex2f(151,125);glVertex2f(175,125);glVertex2f(175,100);
	glColor3ub(103,58,183);glVertex2f(176,100);glVertex2f(176,125);glVertex2f(200,125);glVertex2f(200,100);
	glColor3ub(63,81,181);glVertex2f(201,100);glVertex2f(201,125);glVertex2f(225,125);glVertex2f(225,100);
	glColor3ub(33,150,243);glVertex2f(226,100);glVertex2f(226,125);glVertex2f(250,125);glVertex2f(250,100);
	glColor3ub(3,169,244);glVertex2f(251,100);glVertex2f(251,125);glVertex2f(275,125);glVertex2f(275,100);
	glColor3ub(0,188,212);glVertex2f(276,100);glVertex2f(276,125);glVertex2f(300,125);glVertex2f(300,100);
	glColor3ub(0,150,136);glVertex2f(301,100);glVertex2f(301,125);glVertex2f(325,125);glVertex2f(325,100);
	glColor3ub(76,175,80);glVertex2f(326,100);glVertex2f(326,125);glVertex2f(350,125);glVertex2f(350,100);
	glColor3ub(139,195,74);glVertex2f(351,100);glVertex2f(351,125);glVertex2f(375,125);glVertex2f(375,100);
	glColor3ub(205,220,57);glVertex2f(376,100);glVertex2f(376,125);glVertex2f(400,125);glVertex2f(400,100);
	glColor3ub(255,235,59);glVertex2f(401,100);glVertex2f(401,125);glVertex2f(425,125);glVertex2f(425,100);
	glColor3ub(255,193,7);glVertex2f(426,100);glVertex2f(426,125);glVertex2f(450,125);glVertex2f(450,100);
	glColor3ub(255,152,0);glVertex2f(451,100);glVertex2f(451,125);glVertex2f(475,125);glVertex2f(475,100);
	glColor3ub(255,87,34);glVertex2f(476,100);glVertex2f(476,125);glVertex2f(500,125);glVertex2f(500,100);
	glColor3ub(121,85,72);glVertex2f(501,100);glVertex2f(501,125);glVertex2f(525,125);glVertex2f(525,100);

	glEnd();
	glFlush();
}
void dda(Point p1,Point p2)//line draw algorithm
{
	float dx,dy,k;
	float xinc,yinc,steps,x,y;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	x = p1.x;
	y = p1.y;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	xinc = dx/steps;
	yinc = dy/steps;
	//glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	point(round(x),round(y));
	for(k=0;k<steps;k++)
	{
		x = x+xinc;
		y = y+yinc;
		point(round(x),round(y));
	}
	glEnd();
	glFlush();
}
void drawPoly()//polygon draw algorithm
{
	int j;
	glColor3ub(b.red,b.green,b.blue);
	for(j=0;j<i-1;j++)
	dda(p[j],p[j+1]);

	dda(p[j],p[0]);
}
void myMouseFunc(int button, int state, int x, int y)//mouse function
{
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			p[i].x = x;
			p[i].y = 480 - y;
			i++;
		}
		if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
			switch(ch)
			{
				case 1:
				drawPoly();
				i=0;
				ch=2;
				break;
					case 2:
					xp = x;
					yp = 480 - y;
					glReadPixels(xp,yp,1,1,GL_RGB,GL_UNSIGNED_BYTE,&f);//read pixel
					a.red = f.red;
					a.green = f.green;
					a.blue = f.blue;
					ch=3;
					break;
				case 3:
				xp = x;
				yp = 480 - y;
				boundry_fill(xp,yp);
				ch=1;
				break;
			}
		}
}
void renderFunction()//window set function
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}
int main(int argc, char** argv)//main
{
	b.red = 100;
	b.green = 100;
	b.blue = 100;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Mouse Eventss");
    renderFunction();
    glutMouseFunc(myMouseFunc);
	glutDisplayFunc(draw);
    glutMainLoop();    
    return 0;
}
