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
