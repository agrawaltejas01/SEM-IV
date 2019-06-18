#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include <iostream>
using namespace std;
struct Point	{
	int x;
	int y;
};

Point p[10];
int i=0;

void point(int x,int y)
{
	glVertex2f(x,y);
}

void dda(Point p1,Point p2)
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

void drawPoly()
{
	int j;
	for(j=0;j<i-1;j++)
	dda(p[j],p[j+1]);
	
	dda(p[j],p[0]);
}

void myMouseFunc(int button, int state, int x, int y)
{
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			p[i].x = x;
			p[i].y = 480 - y;
			i++;
		}
		else if(button == GLUT_RIGHT_BUTTON) {
			drawPoly();
			i=0;
		}
}

void renderFunction()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.5f, 1.0f, 1.0f);
	gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
	//glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glFlush();
    renderFunction();
    glutMouseFunc(myMouseFunc);
    glutMainLoop();    
    return 0;
}

