#include<GL/glut.h>
#include <GL/gl.h>
#include<stdlib.h>
#include<stdio.h>

#define ROUND(x) ((int)(x+0.5))
int xa,xb,ya,yb,p;
void display (void)
{

 //Bresenham's Algorithm starts here
 int dx=xb-xa,dy=yb-ya;
 int x=xa,y=ya;
 p=(2*dy)-dx;


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
 glBegin(GL_LINE_STRIP);

	 printf("%d %d\n",x,y);
	 glVertex2s(x,y);

	 for(int k=0;k<dx;k++){
		 	if(p<0){
				p=p+2*dy;
		 		x++;
			}
			else {
				p=p+2*dy-2*dx;
				x++;
				y++;
			}
		 	printf("%d %d\n",x,y);
			glVertex2s(x,y);
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
 printf("Enter the points\n");
 scanf("%d %d %d %d",&xa,&ya,&xb,&yb);
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (100, 100);
 glutCreateWindow ("Simple Bresenham's ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
