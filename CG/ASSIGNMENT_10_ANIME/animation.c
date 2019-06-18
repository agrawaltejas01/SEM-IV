#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
#include<GL/glut.h>
//#include<dos.h>

void Initialize() 
{	
	//glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,640,0,480);
}
void makedelay()
{
	mydisplay();

	glutTimerFunc(60,makedelay,1);


}
void setPixel(GLint x,GLint y)
{
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}

void Circle(int xCenter,int yCenter, int r)
{
 

  int x=0,y=r;
  int p = 3/2 - r;    
 
  while(x<=y){
    setPixel(xCenter+x,yCenter+y);
    setPixel(xCenter+y,yCenter+x);  
    setPixel(xCenter-x,yCenter+y);
    setPixel(xCenter+y,yCenter-x);
    setPixel(xCenter-x,yCenter-y);
    setPixel(xCenter-y,yCenter-x);
    setPixel(xCenter+x,yCenter-y);
    setPixel(xCenter-y,yCenter+x);

    if (p<0)
  p += (2*x)+3;
else {
 p += (2*(x-y))+5;
 y -= 1;
    }
    x++;
  }

  glFlush();
}

void mydisplay()
{
int x,y,i;
x=glutGet(GLUT_WINDOW_WIDTH);
y=glutGet(GLUT_WINDOW_HEIGHT);
for(i=0;i<360;i++)
{

	
	
glBegin(GL_LINES);
 		glVertex2f(95+i,(y/2)+10);
		glVertex2f(145+i,(y/2)+10);//line betn two tires
 		glVertex2f(40+i,(y/2)+10);
		glVertex2f(65+i,(y/2)+10); //back line hori.
 		glVertex2f(175+i,(y/2)+10);
		glVertex2f(195+i,(y/2)+10); //front hori.
		glVertex2f(40+i,(y/2)+10);
		glVertex2f(42+i,(y/2)+33); //back vert.
 		glVertex2f(195+i,(y/2)+10);
		glVertex2f(190+i,(y/2)+30); //front vert.
 		glVertex2f(42+i,(y/2)+33);
		glVertex2f(70+i,(y/2)+35); //back line upper hori.
 		glVertex2f(170+i,(y/2)+35);
		glVertex2f(190+i,(y/2)+30); //front upper hori.
 		glVertex2f(70+i,(y/2)+35);
		glVertex2f(85+i,(y/2)+55); //back digonal.
 		glVertex2f(140+i,(y/2)+55);
		glVertex2f(170+i,(y/2)+35); //front digonal.
 		glVertex2f(85+i,(y/2)+55);
		glVertex2f(140+i,(y/2)+55); //tipper
	glEnd();
 		//****glasses****
	glBegin(GL_LINES);
 		glVertex2f(85+i,(y/2)+35);
		glVertex2f(115+i,(y/2)+35); //glass bottom line left
 		glVertex2f(125+i,(y/2)+35);
		glVertex2f(155+i,(y/2)+35); //glass bttm line rght
		glVertex2f(115+i,(y/2)+47);
		glVertex2f(115+i,(y/2)+35); //glass vert. line left side

 		glVertex2f(125+i,(y/2)+47);
		glVertex2f(125+i,(y/2)+35); //glass vert line rght side
 		glVertex2f(115+i,(y/2)+47);
		glVertex2f(95+i,(y/2)+47); //glass top line left
 		glVertex2f(125+i,(y/2)+47);
		glVertex2f(140+i,(y/2)+47); //glass top line rght
 		glVertex2f(85+i,(y/2)+35);
		glVertex2f(95+i,(y/2)+47); //glass vert. line right side
 		glVertex2f(140+i,(y/2)+47);
		glVertex2f(155+i,(y/2)+35); //glass vert line left side
	glEnd();	
	glBegin(GL_LINES);
		glVertex2f(0,y/2);
		glVertex2f(x,y/2);
	glEnd();
 	//****tires****
 	Circle(80+i,(y/2)+10,10);
 	Circle(160+i,(y/2)+10,10);
 	Circle(80+i,(y/2)+10,11);
 	Circle(160+i,(y/2)+10,11);
	//***rim****
	//left tire rim
 	//line(x/2,(y/2)-10,x/2+(10*sin(k*3.14/180)),y/2-(10*cos(k*3.14/180)));
 	//line(((80+i)+(10*cos((i%360)*3.14/180))),((y/2-20)-(10*sin((i%360)*3.14/180))),((80+i)-(10*sin(((i+180)%360)*3.14/180))),((y/2-20)+(10*cos(((i+180)%360)*3.14/180))));
	glBegin(GL_LINES);
 		glVertex2f(((80+i)+(10*sin(i*3.14/180))),((y/2+10)-(10*cos(i*3.14/180))));
		glVertex2f(((80+i)-(10*sin(i*3.14/180))),((y/2+10)+(10*cos(i*3.14/180))));
 		glVertex2f(((80+i)+(10*sin((90+i)*3.14/180))),((y/2+10)-(10*cos((90+i)*3.14/180))));
		glVertex2f(((80+i)-(10*sin((90+i)*3.14/180))),((y/2+10)+(10*cos((90+i)*3.14/180)))); 

 		//line(70+i,(y/2)-10,90+i,(y/2)-10);

 		//right tire rim
 		/***Constant rim***
 		line(160+i,(y/2)-20,160+i,y/2);
 		line(170+i,(y/2)-10,150+i,(y/2)-10);
 		*/

 		glVertex2f(((160+i)+(10*sin(i*3.14/180))),((y/2+10)-(10*cos(i*3.14/180))));
		glVertex2f(((160+i)-(10*sin(i*3.14/180))),((y/2+10)+(10*cos(i*3.14/180))));
 		glVertex2f(((160+i)+(10*sin((90+i)*3.14/180))),((y/2+10)-(10*cos((90+i)*3.14/180))));
		glVertex2f(((160+i)-(10*sin((90+i)*3.14/180))),((y/2+10)+(10*cos((90+i)*3.14/180))));
	glEnd(); 

 //****mudguard****
 /*arc(80+i,(y/2)-10,0,180,15);
 arc(160+i,(y/2)-10,0,180,15);
 //***lights***
 arc(190+i,(y/2)-27,90,270,4);*/

 	//****Car body*****
	
        glFlush();
glutSwapBuffers();
//glClear(GL_COLOR_BUFFER_BIT);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clean the screen and the depth buffer
//glLoadIdentity();

	
 	//sleep(1);

 }


}

void main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  glutCreateWindow("my first attempt");
  glClearColor(1.0f,1.0f,1.0,0.0f);
  glColor3ub(10,10,254);
  Initialize();

  glClear(GL_COLOR_BUFFER_BIT);
  glutDisplayFunc(makedelay);
  glutTimerFunc(1,makedelay,1);
  glutReshapeFunc(mydisplay);
  glutIdleFunc(mydisplay);
  //mydisplay();
  //gluOrtho2D(0,640,0,480);
  glutMainLoop();

}

