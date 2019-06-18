/*
NAME:Shubhangi Kumari
CLASS:SE 9
BATCH:H9
ROLL NO.:2962
TITLE:Animation(windmill)
*/

#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/freeglut.h>
#include<unistd.h>
#include<stdio.h>
#include<math.h>

void init()
{
	glClearColor(0,0,0,0);
	glColor3f(1,1,1);
	gluOrtho2D(0,1024,0,648);
}

void putpixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}

void plotPoints(int xc, int yc, int x, int y)
{
     putpixel(xc+x,yc+y);
     putpixel(xc-x,yc+y);
     putpixel(xc+x,yc-y);
     putpixel(xc-x,yc-y);
     putpixel(xc+y,yc+x);
     putpixel(xc-y,yc+x);
     putpixel(xc+y,yc-x);
     putpixel(xc-y,yc-x);
}

void DDA(float x1, float y1, float x2, float y2)
{
	float x,y,xinc,yinc;
	int steps,dx,dy,k;
	
	dx=x2-x1;
	dy=y2-y1;
	x=x1;
	y=y1;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	
	xinc=dx/float(steps);	
	yinc=dy/float(steps);
	putpixel(x,y);	
	for(k=0;k<steps;k++)
	{
		x+=xinc;
		y+=yinc;
		putpixel(x,y);
	}
}

void circleMP(int xc, int yc, int r)
{
     int x=0, y=r, p=1-r;
     
     plotPoints(xc,yc,x,y);
     
     while(x<y)
     {
          x=x+1;
          if(p<0)
               p+=2*x+1;
          else
          {
               y--;
               p+=2*(x-y)+1;
          }
          plotPoints(xc,yc,x,y);
     }
}

void draw()
{
	float x,y,xmid,ymid,r,theta,theta1,theta2,theta3,l,i,j,k;
	x=1024;
	y=648;
	r=20;
	xmid=x/2;
	ymid=y/2;
	l=150;                                                                                    
	for(i=0,j=120,k=240;i<360,j<480,k<600;i+=5,j+=5,k+=5)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		circleMP(int(xmid),int(1.5*ymid),r); 
		//sin(20)=0.342 cos(20)=0.94
		DDA(xmid-r*0.342,(1.5*ymid)-r*0.94,xmid-r*0.342,(0.5*ymid)-r*0.94);
		DDA(xmid+r*0.342,(1.5*ymid)-r*0.94,xmid+r*0.342,(0.5*ymid)-r*0.94);
		DDA(xmid-r*0.342,(0.5*ymid)-r*0.94,xmid+r*0.342,(0.5*ymid)-r*0.94);
		theta=i*0.0174;			//(i*3.14/180);
		theta1=0.0523;			//(3*3.14/180);
		theta2=theta+theta1;
		theta3=theta-theta1;
	
		glBegin(GL_TRIANGLES);
		glVertex2f(xmid+r*cos(theta),(1.5*ymid)+r*sin(theta));
		glVertex2f(xmid+r*cos(theta)+l*cos(theta2),(1.5*ymid)+r*sin(theta)+l*sin(theta2));
		glVertex2f(xmid+r*cos(theta)+l*cos(theta3),(1.5*ymid)+r*sin(theta)+l*sin(theta3));
		glEnd();
	
		theta=j*0.0174;			//(j*3.14/180);
		theta1=0.0523;			//(3*3.14/180);
		theta2=theta+theta1;
		theta3=theta-theta1;
		glBegin(GL_TRIANGLES);
		glVertex2f(xmid+r*cos(theta),(1.5*ymid)+r*sin(theta));
		glVertex2f(xmid+r*cos(theta)+l*cos(theta2),(1.5*ymid)+r*sin(theta)+l*sin(theta2));
		glVertex2f(xmid+r*cos(theta)+l*cos(theta3),(1.5*ymid)+r*sin(theta)+l*sin(theta3));
		glEnd();
	
		theta=k*0.0174;			//(k*3.14/180);
		theta1=0.0523;			//(3*3.14/180);
		theta2=theta+theta1;
		theta3=theta-theta1;
		glBegin(GL_TRIANGLES);
		glVertex2f(xmid+r*cos(theta),(1.5*ymid)+r*sin(theta));
		glVertex2f(xmid+r*cos(theta)+l*cos(theta2),(1.5*ymid)+r*sin(theta)+l*sin(theta2));
		glVertex2f(xmid+r*cos(theta)+l*cos(theta3),(1.5*ymid)+r*sin(theta)+l*sin(theta3));
		glEnd();
				
		glFlush();
		usleep(300*300);
		}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1024,648);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Animation");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
}
