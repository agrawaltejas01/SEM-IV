#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

float mat[16][3];
int ch;

GLfloat pcolor[3];

int sign(int x)
{
	if(x>=0)
		return 1;
	else
		return -1;
}
		    
void bres(float x1,float y1,float x2,float y2)
{
    float dx,dy,Po,k,i,Pk,x=x1,y=y1;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy))
    {
    Po=(2*abs(dy))-abs(dx);
   
    Pk=Po;
    glVertex3f(x,y,0);
     
         for(i=0;i<abs(dx);i++)
         {
x=x+sign(dx);
             if(Pk<0)
             {
            
                 glVertex3f(x,y,0);
                 Pk=Pk+(2*abs(dy));
             }
            
             else
             {
y=y+sign(dy);
                  glVertex3f(x,y,0);
                  Pk=Pk+((2*abs(dy))-(2*abs(dx)));
             }
            
         }
      
      }
     
     else
    {
    Po=(2*abs(dx))-abs(dy);
   
    Pk=Po;
    glVertex3f(x,y,0);
         for(i=0;i<abs(dy);i++)
         {
y=y+sign(dy);
             if(Pk<0)
             {
                 glVertex3f(x,y,0);
                 Pk=Pk+(2*abs(dx));
             }
            
             else
             {
x=x+sign(dx);
                  glVertex3f(x,y,0);
                  Pk=Pk+((2*abs(dx))-(2*abs(dy)));
             }
            
         }
      }
          
           
}

void displaymat(float mat[][3])
{
	int i,j;
	for(i=0;i<16;i++)
	{
		for(j=0;j<3;j++)
		{
			cout << "\t" << mat[i][j];
		}
		cout << "\n";
	}		
}

void draw_board(float mat[][3])
{
	int i,j;

	for(i=0;i<5;i++)
	{
		glBegin(GL_POINTS);	
			bres(mat[i][0],mat[i][1],mat[i+5][0],mat[i+5][1]);
		glEnd();
		glFlush();
	}
	for(i=10;i<13;i++)
	{
		glBegin(GL_POINTS);	
			bres(mat[i][0],mat[i][1],mat[i+3][0],mat[i+3][1]);
		glEnd();
		glFlush();
	}	
	
	glBegin(GL_POINTS);	
		bres(mat[0][0],mat[0][1],mat[4][0],mat[4][1]);
		bres(mat[5][0],mat[5][1],mat[9][0],mat[9][1]);
	glEnd();
	glFlush();
}

void chess(void)
{
glColor3f(0.5,0.5,0.5);	
 
	
	int i,j,size;
	float x,y;
	cout << "\n Enter the starting point of chess -: ";
	cout << "\n X -: ";
	cin >> x;
	cout << "\n Y -: ";
	cin >> y;
	
	cout << "\n size of one square of chess board -: ";
	cin >> size;
	

	for(i = 0; i < 5;i++)		// lower line
	{
		mat[i][0] = x + i*size;
		mat[i][1] = y;
		mat[i][2] = 1;
	}
	
	for(j =0 ;j < 5 ;j++)       // upper line 
	{
		mat[i][0] = mat[j][0];
		mat[i][1] = mat[j][1] + 4 * size;
		mat[i][2] = 1;
		i++;
	}
	
	for(j = 1;j<4;j++)		// left side of chess
	{
		mat[i][0] = mat[0][0];
		mat[i][1] = mat[0][1] + j*size;
		mat[i][2] = 1;
		i++;
	}	

	for(j = 1;j<4;j++)		// right side of chess
	{
		mat[i][0] = mat[4][0];
		mat[i][1] = mat[4][1] + j*size;
		mat[i][2] = 1;
		i++;
	}
	
	displaymat(mat);
	draw_board(mat);
}

void multiply(float trans[][3],float old[][3],float new1[][3])
{
	int i,j,k;
	for(i=0;i<16;i++)
	{
		for(j=0;j<3;j++)
		{
			new1[i][j] = 0;
			for(k = 0; k< 3; k++)
			{
				new1[i][j] += old[i][k] * trans[k][j];
			}
		}	
	}					 
}	

void set_trans(float trans[][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
				trans[i][j] = 1;
			else
				trans[i][j] = 0;
		}
	}
}

void Boundary(int x,int y)
{     
        glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,&pcolor);    
      if(pcolor[0]!=0 && pcolor[1]!=0 && pcolor[2]!=0)
      {
              glColor3f(0.0f,0.0f,0.0f);
            glBegin(GL_POINTS);
            glVertex2f(x,y);
            glEnd();

            Boundary(x-1,y);
            Boundary(x+1,y);
            Boundary(x,y-1);
            Boundary(x,y+1);
 
      }
  	    glFlush();
 }


void myMouseFunc(int button, int state, int x, int y)
{

	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN ){

		  Boundary(x,480-y);
	}
}

void choice()
{
	int i,j,opt;
	float trans[3][3], new1[16][3], new2[10][3];
	
	cout << "\n\t :: MENU :: ";
	cout << "\n 1) create ";
	cout << "\n 2) rotate ";
	cout << "\n 3) FILL ";
	cout << "\n 0) EXIT ";
	cout << "\n\t Enter your choice ";
	cin >> ch;
	switch(ch)
	{
		case 1:
			chess();
			break;
			
		case 2:
			float theta;
			glColor3f(0,0,0);
			cout << "\n Enter rotation angle ";
			cin >> theta;
			theta = theta * 3.14159 / 180;

				set_trans(trans);
				
				trans[0][0] = cos(theta);
				trans[0][1] = sin(theta);
				trans[1][0] = -sin(theta);
				trans[1][1] = cos(theta);
				cout << "\n ROTATION MULTIPLIER \n";
	 			displaymat(trans);
 			
 				multiply(trans,mat,new1);
 				cout << "\n COORDINATES AFTER ROTATION ABOUT ORIGIN \n";
			displaymat(new1);
			draw_board(new1);
 			break;
 			
 		case 3:
 			break;	
					
	}		
}

void init() 
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1.0f);
	gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
	//gluOrtho2D(-320.0f, 320.0f, -240.0f, 240.0f);
	glFlush();	
}

int main(int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 480);
	glutCreateWindow("chess board");
	init();
	glClear(GL_COLOR_BUFFER_BIT);
	//glutDisplayFunc(chess);
	
	do
	{
		choice();	
	}while(ch != 3);
 			glutMouseFunc(myMouseFunc);
    glutMainLoop();
	return 0;
}