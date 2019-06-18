#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

int num,ch;
float old[10][3],trans[3][3];

void displaymat(float mat[][3])
{
	int i,j;
	for(i=0;i<num;i++)
	{
		for(j=0;j<3;j++)
		{
			cout << "\t" << mat[i][j];
		}
		cout << "\n";
	}		
}

void drawpoly(float new1[][3])
{
	int i;
	
	for(i=0;i<num-1;i++)
	{
		glBegin(GL_LINES);
		
			glVertex2f(new1[i][0],new1[i][1]);
			glVertex2f(new1[i+1][0],new1[i+1][1]);
			
		glEnd();
		glFlush();
	}		
		glBegin(GL_LINES);
		
			glVertex2f(new1[i][0],new1[i][1]);
			glVertex2f(new1[0][0],new1[0][1]);
			
		glEnd();
		glFlush();
}
	
void multiply(float trans[][3],float old[][3],float new1[][3])
{
	int i,j,k;
	for(i=0;i<num;i++)
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

void translate(int tx,int ty,float old[][3],float new1[][3])
{
	set_trans(trans);		
		trans[2][0] = tx;
		trans[2][1] = ty;
	displaymat(trans);
	
	multiply(trans,old,new1);
}	

void choice()
{
	int i,j,opt;
	float new1[10][3], new2[10][3];
	cout << "\n\t :: MENU :: ";
	cout << "\n 1) Translation ";
	cout << "\n 2) Rotation ";
	cout << "\n 3) Scaling ";
	cout << "\n 4) Shearing ";
	cout << "\n 5) Reflection ";
	cout << "\n 0) EXIT ";
	cout << "\n\t Enter your choice ";
	cin >> ch;
	switch(ch)
	{
		case 1:
 			int tx,ty;
 			cout << "\n Enter value of x-factor of translation (tx)";
 			cin >> tx;
 			cout << "\n Enter value of y-factor of translation (ty)";
 			cin >> ty;
 			cout << "\n";
 			
 			translate(tx,ty,old,new1);

 			cout << "\n";
			displaymat(new1);
			glColor3ub(183,28,28);
 			drawpoly(new1);
			break;
		
		case 2:
			float theta;
			cout << "\n Enter rotation angle ";
			cin >> theta;
			theta = theta * 3.14159 / 180;
			// translation to origin 
				translate(-old[0][0],-old[0][1],old,new1);
				cout << "\n COORDINATES AFTER TRANSLATION TO ORIGIN \n";	
				displaymat(new1);
					// translated coordinates are in new1
			// rotation about origin	
				set_trans(trans);
					trans[0][0] = cos(theta);
					trans[0][1] = sin(theta);
					trans[1][0] = -sin(theta);
					trans[1][1] = cos(theta);
				cout << "\n ROTATION MULTIPLIER \n";
	 			displaymat(trans);
 				multiply(trans,new1,new2);
 				cout << "\n COORDINATES AFTER ROTATION ABOUT ORIGIN \n";
 				displaymat(new2);
 					// rotation coordinates are stored in new2
 			// translation back to its original position
 				translate(old[0][0],old[0][1],new2,new1);
					// required matrix is stored back in new1
 				cout << "\n REQUIRED COORDINATES \n";
			displaymat(new1);
			glColor3ub(74,20,140);
 			drawpoly(new1);
 			break;
 								
		case 3:
			int sx,sy;	
			cout << "\n Enter scaling factor along x axis (Sx) ";
			cin >> sx;
			cout << "\n Enter scaling factor along y axis (Sy) ";
			cin >> sy;
			// translation to origin 
				translate(-old[0][0],-old[0][1],old,new1);
				cout << "\n COORDINATES AFTER TRANSLATION TO ORIGIN \n";	
				displaymat(new1);
					// translated coordinates are in new1
			// scaling about origin				
			set_trans(trans);
				trans[0][0] = sx;
				trans[1][1] = sy;
			displaymat(trans);
 			multiply(trans,new1,new2);
 			cout << "\n";
			displaymat(new2);
 		
 			// translation back to its original position
 				translate(old[0][0],old[0][1],new2,new1);
					// required matrix is stored back in new1
			displaymat(new1);
			glColor3ub(191,54,12);
 			drawpoly(new1);
			break;
			
		case 4:
			{
			int a=-1,b=-1;
			cout << "\n 1) X-shear \n 2) Y-shear ";
			cout << "\n What do you want to perfoem  ";
			cin >> opt;
				switch(opt)
				{
				case 1:
					cout << "\n Enter x-shear factor (b) ";
					cin >> b;
					break;
				case 2:
					cout << "\n Enter y-shear factor (a) ";
					cin >> a;
					break;
				}		
			// translation to origin 
				translate(-old[0][0],-old[0][1],old,new1);
				cout << "\n COORDINATES AFTER TRANSLATION TO ORIGIN \n";	
				displaymat(new1);
					// translated coordinates are in new1	
				// shearing at origin
				set_trans(trans);
				
				if(b != -1)
					trans[1][0] = b;
					
				if(a != -1)
					trans[0][1] = a;
						
				displaymat(trans); 	
				
				multiply(trans,new1,new2);
				cout << "\n";
				displaymat(new2);
				
 			// translation back to its original position
 				translate(old[0][0],old[0][1],new2,new1);
					// required matrix is stored back in new1
				displaymat(new1);
			glColor3ub(0,96,100);
 				drawpoly(new1);
			}
				break;
		
		case 5:
		{
			cout << "\n 1) Reflection about y-axis (x=0)";
			cout << "\n 2) Reflection about x-axis (y=0)";
			cout << "\n 3) Reflection about xy (x=y)";
			cout << "\n 4) Reflection about origin ";
			cout << "\n Enter your choice ";
			cin >> opt; 
			switch(opt)
			{
				case 1:
					set_trans(trans);
					trans[0][0] = -1;
			 			multiply(trans,old,new1);
 						cout << "\n";
						displaymat(new1);
			glColor3ub(26,35,126);
					drawpoly(new1);
					break;
					
				case 2:	
					set_trans(trans);
					trans[1][1] = -1;
			 			multiply(trans,old,new1);
 						cout << "\n";
						displaymat(new1);
			glColor3ub(62,39,35);
					drawpoly(new1);
					break;
					
				case 3:
					set_trans(trans);
					trans[0][0] = 0;
					trans[1][1] = 0;
					trans[0][1] = 1;
					trans[1][0] = 1;
			 			multiply(trans,old,new1);
 						cout << "\n";
						displaymat(new1);
			glColor3ub(136,14,79);
					drawpoly(new1);
					break;
					
				case 4:
					set_trans(trans);
					trans[0][0] = -1;
					trans[1][1] = -1;
			 			multiply(trans,old,new1);
 						cout << "\n";
						displaymat(new1);
			glColor3ub(118,255,3);
					drawpoly(new1);
					break;				
			}	
		}	
		break;	
					
	}		
}

void init() 
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
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
	
	int i;
	cout << "\n Enter number of vertices of a polygon -: ";
	cin >> num;
	for(i=0;i<num;i++)
	{
		cout << "\n Enter co-ordinates -: \t X -:";
		cin >>old[i][0]; 
		cout << " \t Y -: ";
		cin >> old[i][1];
		old[i][2] = 1;	
	}	
	
	
	glutCreateWindow("Transformation");
	init();
	glClear(GL_COLOR_BUFFER_BIT);

	displaymat(old);
	glBegin(GL_LINES);

			glVertex2f(-320,0);
			glVertex2f(320,0);
			
			glVertex2f(0,-240);
			glVertex2f(0,240);
			
	glEnd();
	glFlush();
	drawpoly(old);
	
	
	do
	{
		choice();	
	}while(ch != 0);

	return 0;
}
