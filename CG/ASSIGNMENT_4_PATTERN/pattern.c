#include<stdio.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<string.h>
//#include"dda.c"

int dx,dy,pos,neg,X1,X2,Y1,Y2,sdx,sdy;             //pos=positive constant   neg=negitive constant  s=sign     

int sign(int a,int b)
{
      if( (b-a)>0 )
            return 1;
      
      else if( (b-a)<0 )
            return -1;
}

void bresenham(int x1,int y1,int x2,int y2)
{
   dx=abs(x2-x1);
   dy=abs(y2-y1);   
            
   if(dy<=dx)
   {
      
      int x=x1,y=y1;
      
      sdx=sign(x1,x2);                            //assigning constants
      sdy=sign(y1,y2);
      
      pos=2*dy-2*dx;
      neg=2*dy;
      
      int p;     
      p=2*dy-dx;                          //p0
      
      glBegin(GL_POINTS);
      glVertex2d(x,y);
      
      for(int i=0;i<dx;i++)
      {
            if(p<0)
            {                          
                  x=x+sdx;
                                                      
                  glVertex2d(x,y);
                  
                  p=p+neg;      
            }
            
            else if(p>0)
            {
                  x=x+sdx;
                  y=y+sdy;
                                  
                  glVertex2d(x,y);
                  
                  p=p+pos;               
            }
      }
      
      glEnd();
	glFlush();
      
      
   }
   
   else if(dx<dy)
   {
      int x=x1,y=y1;
        
      sdy=sign(y1,y2);
      sdx=sign(x1,x2);
      pos=2*dx-2*dy;
      neg=2*dx;                     //assigning constants
      
      int p;     
      p=2*dx-dy;                          //p0
      
      glBegin(GL_POINTS);
      glVertex2d(x,y);
      
      for(int i=0;i<dy;i++)
      {
            if(p<0)
            {
                  y=y+sdy;
                                  
                  glVertex2d(x,y);
                  
                  p=p+neg;
                                                  
            }
            
            else if(p>0)
            {
                  y=y+sdy;
                  x=x+sdx;
                  
                  glVertex2d(x,y);
                  
                  p=p+pos;
             
            }
      }
      
      glEnd();
	glFlush();
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
	
	      bresenham(i,253,i,247);
	      bresenham(j,253,j,247);
	      
	      sprintf(arr1,"%d",i-250);
	      sprintf(arr2,"%d",j-250);
	      
	      renderBitMapString(i,240,arr1);
	      renderBitMapString(j,240,arr2);
	      
      }
           
      for(int i=220,j=280;i>=0,j<=500;i-=30,j+=30)           //marking y-axis
	{
	      bresenham(253,i,247,i);
	      bresenham(253,j,247,j);
	      
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

	bresenham(X1,Y1,X1,Y2);
	bresenham(X1,Y2,X2,Y2);
	bresenham(X2,Y2,X2,Y1);
	bresenham(X2,Y1,X1,Y1);
	
	bresenham((X1+X2)/2,Y2,X2,(Y1+Y2)/2);
	bresenham(X2,(Y1+Y2)/2,(X1+X2)/2,Y1);
	bresenham((X1+X2)/2,Y1,X1,(Y1+Y2)/2);
	bresenham(X1,(Y1+Y2)/2,(X1+X2)/2,Y2);
	
	bresenham((((X1+X2)/2)+X2)/2,(Y2+((Y1+Y2)/2))/2,(X2+((X1+X2)/2))/2,(((Y1+Y2)/2)+Y1)/2);
	bresenham((X2+((X1+X2)/2))/2,(((Y1+Y2)/2)+Y1)/2,(X1+((X1+X2)/2))/2,(((Y1+Y2)/2)+Y1)/2);
	bresenham((X1+((X1+X2)/2))/2,(((Y1+Y2)/2)+Y1)/2,(X1+((X1+X2)/2))/2,(((Y1+Y2)/2)+Y2)/2);
	bresenham((X1+((X1+X2)/2))/2,(((Y1+Y2)/2)+Y2)/2,(((X1+X2)/2)+X2)/2,(Y2+((Y1+Y2)/2))/2);
	
	draw_axis();
	marking_axis();
				
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
	scanf("%d",&X1);
	printf("\n");
	
	printf("\n\t Enter Point1 Y1:\n");
	scanf("%d",&Y1);
	printf("\n");
	
	printf("\n\t ****************************************");
	printf("\n\tEnter Point1 X2:\n");
	scanf("%d",&X2);
	printf("\n");
	
	printf("\n\t Enter two points of line to be drawn::");
	printf("\n\t ****************************************");
	printf("\n\t Enter Point1 Y2:\n");
	scanf("%d",&Y2);
	printf("\n");
		
	
	X1+=250;
	Y1+=250;
	X2+=250;
	Y2+=250;
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("PATTERN");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
}
