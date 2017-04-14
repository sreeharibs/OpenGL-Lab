#include<GL/glut.h>
#include <GL/gl.h>
#include<stdlib.h>
#include<stdio.h>

int xa,xb,ya,yb,p;


 void init(void){

    glClearColor (0.0, 0.0, 0.0, 1.0);
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

 }

 void display (void){

    //Bresenhams Algorithm starts here

    int dx=xb-xa,dy=yb-ya;
    int x=xa,y=ya;

    p=(2*dy)-dx;

    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);

    glBegin(GL_POINTS);

    glVertex2s(x,y);

	 for(int k=0;k<dx;k++){
		 	if(p<0){
                    p=p+2*dy;
                    x++;
            }

			else{
                    p=p+2*dy-2*dx;
                    x++;
                    y++;
			}

			glVertex2s(x,y);
    }


    glEnd();

    glutSwapBuffers();
 }


int main(int argc, char** argv){


    printf("Enter the points\n");
    scanf("%d %d %d %d",&xa,&ya,&xb,&yb);

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Simple DDA ");
    init ();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;

}

