#include<stdio.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<string.h>

int dx,dy,pos,neg,sdx,sdy,X_min,Y_min,L,Y_max,X_max,X1,X2,Y1,Y2,x,y;      //pos=positive constant   neg=negitive constant  s=sign     
unsigned int o1=0,o2=0;
float m=0;

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

unsigned int opcode(int x_temp,int y_temp)
{
	unsigned int code=0;
	
	if(x_temp<X_min)
		code = code | 1;
	
	if(x_temp>X_max)
		code = code | 2;
	
	if(y_temp<Y_min)
		code = code | 4;
	
	if(y_temp>Y_max)
		code = code | 8;
	
	return code;	
}

void draw()
{
	bresenham(X_min,Y_min,X_max,Y_min);		//base;
	bresenham(X_min,Y_min,X_min,Y_max);		//left
	bresenham(X_min,Y_max,X_max,Y_max);	//top
	bresenham(X_max,Y_max,X_max,Y_min);	//right
	
	bresenham(X1,Y1,X2,Y2);

}

unsigned int clipp(unsigned int o)
{
	if(o & 1)
	{
		x=X_min;
		y=Y1+(X_min-X1)*m;
		o=opcode(x,y);
	}
	else if(o & 2)
	{
		x=X_max;
		y=Y1+(X_max-X1)*m;
		o=opcode(x,y);
	}
	else if(o & 4)
	{
		y=Y_min;
		x=X1+(Y_min-Y1)/m;
		o=opcode(x,y);
	}
	else if(o & 8)
	{
		y=Y_max;
		x=X1+(Y_max-Y1)/m;
		o=opcode(x,y);
	}
	return o;

}

void check()
{
	if( (o1 == 0) && (o2 == 0) )
	{
		printf("Line completely inside region\n");
		return ;		
	}
	
	else if( (o1 & o2) != 0)
	{
		printf("Line completely outside region\n");
		X1=Y1=X2=Y2=0;
		return ;		
	}
	
	else if( (o1 & o2) == 0)
	{
		while(o1 != 0 && o2 != 0)
		{
			m=(Y2-Y1)/(X2-X1);
			
			if(o1 != 0)
			{
				o1=clipp(o1);
				X1=x;
				Y1=y;
			}
			
			else
			{
				o2=clipp(o2);
				X2=x;
				Y2=y;
			}
		}
	}
			
		
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
	printf("Enter starting point of Area Of Clipping(Square) : ");
	
	printf("Enter X : ");
	scanf("%d",&X_min);
	printf("\n");
	
	printf("Enter Y : ");
	scanf("%d",&Y_min);
	printf("\n");
	
	printf("Enter Length of Area Of Clipping (Square) : ");
	scanf("%d",&L);
	printf("\n");
	
	X_max=X_min+L;
	Y_max=Y_min+L;
	
	printf("Enter Cordinates of line : ");
	
	printf("Enter X1 : ");
	scanf("%d",&X1);
	printf("\n");
	
	printf("Enter Y1 : ");
	scanf("%d",&Y1);
	printf("\n");
	
	printf("Enter X2 : ");
	scanf("%d",&X2);
	printf("\n");
	
	printf("Enter Y2 : ");
	scanf("%d",&Y2);
	printf("\n");
	
	o1 = opcode(X1,Y1);
	o2 = opcode(X2,Y2);
	
	
	
	/*printf("%u\n",o1);
	printf("%u\n",o2);*/
	
	check();
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("Circle Drawing");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
}