#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

float xmin=-100;
float xmax=100;
float ymin=-100;
float ymax=100;
float xl1,yl1,xl2,yl2;

void display();
void init();
int code(float x,float y)
{
    int c=0;
    if(y>ymax)c=8;
    if(y<ymin)c=4;
    if(x>xmax)c=c|2;
    
    if(x<xmin)c=c|1;
    return c;
}

void cohen_Line(float x1,float y1,float x2,float y2)
{
    int c1=code(x1,y1);
    int c2=code(x2,y2);
    float m=(y2-y1)/(x2-x1);
    while((c1|c2)>0)
    {
        if((c1 & c2)>0)
        {
           exit(0);
        }

    float xi=x1;float yi=y1;
    int c=c1;
    if(c==0)
    {
         c=c2;
         xi=x2;
         yi=y2;
    }
    float x,y;
    if((c & 8)>0)
    {
       y=ymax;
       x=xi+ 1.0/m*(ymax-yi);
    }
    else
      if((c & 4)>0)
      {
          y=ymin;
          x=xi+1.0/m*(ymin-yi);
      }
      else
       if((c & 2)>0)
       {
           x=xmax;
           y=yi+m*(xmax-xi);
       }
       else
       if((c & 1)>0)
       {
           x=xmin;
           y=yi+m*(xmin-xi);
       }

       if(c==c1)
       {
           xl1=x;
           yl1=y;
           c1=code(xl1,yl1);
       }

       if(c==c2)
       {
           xl2=x;
           yl2=y;
           c2=code(xl2,yl2);
       }
}

 display();

}
	
void mykey(unsigned char key,int x,int y)
{
    if(key=='c')
    {  
        cout << "Hello";
        cohen_Line(xl1,yl1,xl2,yl2);
        glFlush();
    }
}

void display()
{

   glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);

   glBegin(GL_LINE_LOOP);
   glVertex2i(xmin,ymin);
   glVertex2i(xmin,ymax);
   glVertex2i(xmax,ymax);
   glVertex2i(xmax,ymin);
   glEnd();
   glColor3f(1.0,0.0,0.0);
   glBegin(GL_LINES);
   glVertex2i(xl1,yl1);
   glVertex2i(xl2,yl2);
   glEnd();
   glFlush();
}

void init() 
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(1.0f);
	gluOrtho2D(-320.0f, 320.0f, -240.0f, 240.0f);
	glFlush();	
}

int main(int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 480);
	cout << "\n Enter x1 & y1 ";
	cin >> xl1 >> yl1;
	cout << "\n Enter x2 & y2 ";
	cin >> xl2 >> yl2;
		
	glutCreateWindow("\n Clipping");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(mykey);
	glutMainLoop();
	
	return 0;
}

