#include<stdio.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<string.h>
float X1,X2,Y1,Y2;
float round_value(float v)
{
	return (v+0.5);
}
void LineDDA(float X1,float Y1,float X2, float Y2)
{
	float dx=(X2-X1);
	float dy=(Y2-Y1);
	float step;
	float xInc,yInc,x=X1,y=Y1;
	step=(abs(dx)>abs(dy))?(abs(dx)):abs((dy));
	xInc=dx/(float)step;
	yInc=dy/(float)step;	
	
	glBegin(GL_POINTS);
	glVertex2d(x,y);
	int k;
	for(k=0;k<step;k++)
	{
		x+=xInc;
		y+=yInc;
		glVertex2d(round_value(x),round_value(y));
	}
	glEnd();
	glFlush();
	
}



void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	LineDDA(X1,Y1,X1,Y2);	
	
	//draw_axis();
	//marking_axis();
				
}
void init()
{
	glClearColor(1.0,1.0,1.0,0);
	glColor3i(0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0,500,0,500);
	
}
int main(int argc,char **argv)
{
	printf("\n\t Enter two points of line to be drawn::");
	printf("\n\t ****************************************");
	printf("\n\t Enter Point1 X1:\n");
	scanf("%d%d",&X1);
	printf("\n");
	
	printf("\n\t Enter Point1 Y1:\n");
	scanf("%d%d",&Y1);
	printf("\n");
	
	printf("\n\t ****************************************");
	printf("\n\tEnter Point1 X2:\n");
	scanf("%d%d",&X2);
	printf("\n");
	
	printf("\n\t Enter two points of line to be drawn::");
	printf("\n\t ****************************************");
	printf("\n\t Enter Point1 Y2:\n");
	scanf("%d%d",&Y2);
	printf("\n");
		
	
	X1+=250;
	Y1+=250;
	X2+=250;
	Y2+=250;
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("DDA Line");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
}
