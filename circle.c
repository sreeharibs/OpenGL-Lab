#include<GL/glut.h>
#include <GL/gl.h>
#include<stdlib.h>
#include<stdio.h>

int r;

 void init(void){

    glClearColor (0.0, 0.0, 0.0, 1.0);
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);

 }

 void display (void){

    //Bresenhams Algorithm starts here

    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);

    glBegin(GL_POINTS);

	  int xCenter=0,yCenter=0;
	  int x=0,y=r;
	  int p = 3/2 - r;

	  while(x<=y){

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
	    else{
                p += (2*(x-y))+5;
                y--;
            }
	    x++;

	}

    glEnd();

    glutSwapBuffers();
 }


int main(int argc, char** argv){


    printf("Enter the radius\n");
    scanf("%d",&r);

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Midpoint Circle Drawing ");
    init ();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;

}

