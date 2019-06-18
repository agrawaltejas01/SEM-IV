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
