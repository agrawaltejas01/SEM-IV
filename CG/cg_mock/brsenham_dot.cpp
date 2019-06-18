
#include <GL/freeglut.h>
#include <GL/gl.h>
#include<math.h>
#include<stdio.h>
int xa,ya,xb,yb,flag=0;
int sign(int dxy)
{
    if(dxy>0)
        return -1;
    return 1;
}
void line()
{
    int x=xa,y=ya,i;
    int dx=xa-xb;
    int dy=ya-yb;
    int p;
    if(abs(dx)>=abs(dy))
    {
        p=2*abs(dy)-abs(dx);
        for(i=0;i<abs(dx);i++)
        {
            if(p<0)
            {
                x+=sign(dx);
                p+=2*abs(dy);
            }
            else
            {
                
                x+=sign(dx);
                y+=sign(dy);
                p+=2*abs(dy)-2*abs(dx);
            }
            if(flag<=1)
            glVertex2d(round(x)+320,round(y)+240);
            if(flag==5)
            flag=0;
            flag++;
        }
    }
    else
    {
p=2*abs(dx)-abs(dy);
        for(i=0;i<abs(dy);i++)
        {       
        
        if(p<0)
        {
            y+=sign(dy);
            p+=2*abs(dx);
        }
        else
        {
    
            x+=sign(dx);
            y+=sign(dy);
            p+=2*abs(dx)-2*abs(dy);
        }
        if(flag<=1)
        glVertex2d(round(x)+320,round(y)+240);  
        if(flag==5)
        flag=0;
        flag++;
        }   
    }
            
}
void renderFunction()
{
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1, 1, 1.0);
        glLoadIdentity();
        glOrtho(0.0, 640.0, 0.0,480.0, 0, 1.0);
    glBegin(GL_POINTS); 
    line();
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(320,0);
    glVertex2d(320,480);
    glVertex2d(0,240);
    glVertex2d(640,240);
    glEnd();
        glFlush();
}
int main(int argc, char** argv)
{
    printf("Enter xa,ya\n");
        scanf("%d%d",&xa,&ya);
        printf("Enter xb,yb\n");
        scanf("%d%d",&xb,&yb);
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
        glutCreateWindow("OpenGL - First window demo");
        glutDisplayFunc(renderFunction);
        glutMainLoop();    
        return 0;
}


