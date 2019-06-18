#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>

void setpixel(int x,int y)	{
	glVertex2f(x,y);
}

void dda(int xa,int ya,int xb, int yb)	{
	int dx,dy,k;
	float xinc,yinc,steps,x,y;
	dx = xb-xa;
	dy = yb-ya;
	x=xa;
	y=ya;
	if(abs(dx)>abs(dy))	steps=abs(dx);
	else	steps=abs(dy);
	xinc = dx/steps;
	yinc = dy/steps;
	setpixel(round(x),round(y));
	for(k=0;k<steps;k++)	{
		x = x+xinc;
		y = y+yinc;
		setpixel(round(x),round(y));
	}
}

void brez(int x1,int y1,int x2,int y2)	{
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
}
void renderFunction()	{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
glLoadIdentity();
    glOrtho(-320,320,-240,240,-1.0,1.0);
    glBegin(GL_LINES);
        glVertex2f(-320,0);
        glVertex2f(320,0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
        glVertex2f(0,240);
        glVertex2f(0,-240);
    glColor3f(0.5, 1.0, 0.0);
	dda(-240,200,240,200);	dda(240,200,240,-200);
	dda(240,-200,-240,-200);dda(-240,-200,-240,200);
    glColor3f(1.0, 0.9, 0.2);
	brez(0,200,240,0);	brez(240,0,0,-200);
	brez(0,-200,-240,0);	brez(-240,0,0,200);
    glColor3f(0.1, 1.0, 1.0);
	brez(-120,100,120,100);	brez(120,100,120,-100);
	brez(120,-100,-120,-100);	brez(-120,-100,-120,100);
    glEnd();
    glFlush();
}
int main(int argc, char** argv)	{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
