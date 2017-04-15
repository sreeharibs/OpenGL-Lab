#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

float theta = -1 ;

void init(){

    glClearColor(1.0,1.0,1.0,1.0);

}


void display(void){

	glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glLoadIdentity();

    //fan - stand
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.7,0.8);
        glVertex2f(0.0,0.0);
        glVertex2f(0.0,-1.2);
        glVertex2f(0.4,-1.0);
        glVertex2f(-0.4,-1.0);

    glEnd();

    //outer
    glColor3f(0.0,0.1,0.9);
    glutSolidSphere(0.65,100,15);

    //inner
    glColor3f(1.0,1.0,1.0);
    glutSolidSphere(0.62,100,15);

    glPopMatrix();

    //rotate the following items- fan_blades
    glRotatef(theta,0,0,1);

    //fan_blades
    glBegin(GL_POLYGON);

        glColor3f(0.0,0.0,0.0);

        glVertex2f(0.0,0.0);
        glVertex2f(-0.25,0.5);
        glVertex2f(0.25,0.5);

        glVertex2f(0.0,0.0);
        glVertex2f(0.5,0.25);
        glVertex2f(0.5,-0.25);

        glVertex2f(0.0,0.0);
        glVertex2f(-0.5,-0.25);
        glVertex2f(-0.5,0.25);

        glVertex2f(0.0,0.0);
        glVertex2f(0.25,-0.5);
        glVertex2f(-0.25,-0.5);

   glEnd();


    //sphere in centre
    glColor3f(1.5,0.0,0.2);
    glutSolidSphere(0.06,100,15);


    glutSwapBuffers();

}



void keys(unsigned char key,int x,int y){

    switch(key){

        case '0' : theta = 0; break;
        case '1' : theta = -1; break;
        case '2' : theta = -5; break;
        case '3' : theta = -10; break;
        case '4' : theta = -15; break;

    }

}


int main(int argc,char **argv)
{

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(800,600);
  glutCreateWindow(" The Table Fan");
  init();

  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutKeyboardFunc(keys);

 glutMainLoop();
  return 0;
}
