#include<GL/glut.h>
#include <GL/gl.h>
#include<stdlib.h>
#include<stdio.h>

#define ROUND(x) ((int)(x+0.5))

int r;

void display (void)
{

 glClear (GL_COLOR_BUFFER_BIT);

 glBegin(GL_POINTS);
	 //Plotting X axis and Y axis
	 glColor3f (1.0, 1.0, 1.0);
	 for(int i=-100 ; i<=100 ; i++){
			glVertex2s(i,0);
			glVertex2s(0,i);
	 	}

	 //Mark X - optional
	 for(int i=-2; i<=2 ; i++){
			 glVertex2s(95+i,4+i);
			 glVertex2s(95-i,4+i);
	 	}

	 //Mark Y - optional
	 for(int i=0; i<=2 ; i++){
			 glVertex2s(4+i,95+i);
			 glVertex2s(4-i,95+i);
			 glVertex2s(4,95-i);
	 	}
 glEnd();

 glColor3f (1.0, 0.0, 0.0);
 glBegin(GL_POINTS);

	 
	  int xCenter=0,yCenter=0;
	  int x=0,y=r;
	  int p = 3/2 - r;    

	  while(x<=y){
	    printf("\n%d %d",x,y);
	    glVertex2i(xCenter+x,yCenter+y);
	    glVertex2i(xCenter+y,yCenter+x);  
	    glVertex2i(xCenter-x,yCenter+y);
	    glVertex2i(xCenter+y,yCenter-x);
	    glVertex2i(xCenter-x,yCenter-y);
	    glVertex2i(xCenter-y,yCenter-x);
	    glVertex2i(xCenter+x,yCenter-y);
	    glVertex2i(xCenter-y,yCenter+x);

	    if (p<0)
	  		p += (2*x)+3;
	    else {
	 		p += (2*(x-y))+5;
	 		y--;
	    	     }
	    x++;

	}

 glEnd();
 glFlush();
 }

 void init(void)
 {
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
 }

int main(int argc, char** argv)
{
 printf("Enter the radius\n");
 scanf("%d",&r);
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (100, 100);
 glutCreateWindow ("Midpoint Circle ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
