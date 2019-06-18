#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>
#include<string.h>
 double X1, Y1, X2, Y2;
int pntX1, pntY1;
int x,y,r,d;
float rad=(60*3.14)/180;
float c=cos(rad);
float s=sin(rad);
void Circle(int,float,float);
float round_value(float v)
{
  return floor(v + 0.5);
}
void LineDDA(float X1,float Y1,float X2,float Y2)
{
  double dx=(X2-X1);
  double dy=(Y2-Y1);
  double steps;
  float xInc,yInc,x=X1,y=Y1;
 
  steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
  xInc=dx/(float)steps;
  yInc=dy/(float)steps;

  
  //glClear(GL_COLOR_BUFFER_BIT);

  
  glBegin(GL_POINTS);

  glVertex2d(x+320,y+240);
  int k;
  
  for(k=0;k<steps;k++)
  {
    x+=xInc;
    y+=yInc;
  
    glVertex2d(round_value(x)+320, round_value(y)+240);
  }
	
}

void renderFunction()
{
	
	

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 1.0);
	glLoadIdentity();
    glOrtho(0, 640.0, 0, 480, -2, 2);
    glBegin(GL_LINES);
        glVertex2f(0, 240);

        glVertex2f(640, 240);
	glVertex2f(320, 480);
	
        glVertex2f(320, 0);
	
	Circle(r,x,y);
	Circle(r,c*d,s*d);
	Circle(r,-(c*d),s*d);
	Circle(r,c*d,-(s*d));
	Circle(r,-(c*d),-(s*d));
	Circle(d,x,y);
	Circle(3*r,x,y);
	
	Circle(r,x+d,y);


	Circle(r,x-d,y);
  glEnd();
    glFlush();
}
void plot(int x, int y,int xc,int yc)
{
	glBegin(GL_POINTS);
	glVertex2i(x+pntX1+xc+320, y+pntY1+yc+240);
	glEnd();
}
void Circle(int r,float xc,float yc)
{
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	plot(x, y,xc,yc);

	while (y > x)
	{
		if (decision < 0)
		{
			x++; 
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		plot(x, y,xc,yc);
		plot(x, -y,xc,yc);
		plot(-x, y,xc,yc);
		plot(-x, -y,xc,yc);
		plot(y, x,xc,yc);
		plot(-y, x,xc,yc);
		plot(y, -x,xc,yc);
		plot(-y, -x,xc,yc);
	}

}


int main(int argc, char** argv)
{
	printf("enter x:");
	scanf("%d",&x);
	printf("enter y:");
	scanf("%d",&y);
	printf("enter radius:");
	scanf("%d",&r);	
	d=2*r;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    //glutMouseFunc(MyMouseFunc);
    glutMainLoop();    
    return 0;
}
