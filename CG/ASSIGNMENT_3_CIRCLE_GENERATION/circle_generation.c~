#include<stdio.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<string.h>

float X,Y,r,l,R;
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

void plot(float x,float y,float Xc,float Yc)
{
     glBegin(GL_POINTS);
      glVertex2d(x+Xc,y+Yc);
      
      glEnd();
      glFlush();
}
     

void mid_pt(float Xc,float Yc,float R)
{
     float d,x,y;
     
     d=(5/4)-R;
     y=R;
     x=0;     
     
     while(y>=x)
     {            
            if(d<0)
            {
                  x++;
                  d+=2*x+1;
            }
            
            else
            {
                  x++;
                  y--;
                  d+=2*x-2*y+1;
            }
            
            plot(x,y,Xc,Yc);
            plot(x,-y,Xc,Yc);
            plot(-x,y,Xc,Yc);
            plot(-x,-y,Xc,Yc);
            plot(y,x,Xc,Yc);
            plot(y,-x,Xc,Yc);
            plot(-y,x,Xc,Yc);
            plot(-y,-x,Xc,Yc);
      }
} 

void renderBitMapString(int x,int y,char arr[])
{
      glRasterPos3f(x,y,0);
      
      int len=strlen(arr);
      
      for(int i=0;i<len;i++)
      {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,arr[i]);
      }
}

void marking_axis()
{
	char arr1[50],arr2[50];
	
	for(int i=220,j=280;i>=0,j<=500;i-=30,j+=30)           //marking x-axis
	{
	
	      LineDDA(i,253,i,247);
	      LineDDA(j,253,j,247);
	      
	      sprintf(arr1,"%d",i-250);
	      sprintf(arr2,"%d",j-250);
	      
	      renderBitMapString(i,240,arr1);
	      renderBitMapString(j,240,arr2);
	      
      }
           
      for(int i=220,j=280;i>=0,j<=500;i-=30,j+=30)           //marking y-axis
	{
	      LineDDA(253,i,247,i);
	      LineDDA(253,j,247,j);
	      
	      sprintf(arr1,"%d",i-250);
	      sprintf(arr2,"%d",j-250);
	      
	      renderBitMapString(230,i,arr1);
	      renderBitMapString(230,j,arr2);	   
	      
      }
}

void draw_axis()
{
      glBegin(GL_LINES);                  //draw axis
	
	glVertex2d(0,250);
	glVertex2d(500,250);
	glVertex2d(250,0);
	glVertex2d(250,500);
}        

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	draw_axis();
	marking_axis();
      
      mid_pt(X+(l/2),Y+((sqrt(3))/6)*l,r);
      mid_pt(X+(l/2),Y+((sqrt(3))/6)*l,R);
      
      LineDDA(X,Y,X+l,Y);
      LineDDA(X,Y,X+l/2,Y+((sqrt(3)/2))*l);
      LineDDA(X+l,Y,X+l/2,Y+((sqrt(3)/2))*l);

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
	printf("\n\t Enter points of Triangle ::");
	printf("\n\t ****************************************");
	printf("\n\t Enter Point1 X1:\n");
	scanf("%f",&X);
	printf("\n");
	
	printf("\n\t Enter Point1 Y1:\n");
	scanf("%f",&Y);
	printf("\n");
	
	printf("\n\t Enter Length of Triangle ::");
	printf("\n\t ****************************************");
	printf("\n\t Enter Length:\n");
	scanf("%f",&l);
	printf("\n");		
		
	
	X+=250;
	Y+=250;
	
	r=((sqrt(3))/6)*l;
	R=2*r;
	//R=((sqrt(3))/3)*l;
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("Circle Drawing");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
}
