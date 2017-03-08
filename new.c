#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>


void display(){
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_POINTS);
	glVertex2i(30,30);	
	glVertex2i(30,60);
	glVertex2i(60,80);
	glVertex2i(90,60);
	glVertex2i(90,30);
   glEnd();

   glFlush();
}


int main(int argc, char** argv){


   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutInitWindowSize(500,500);
   glutInitWindowPosition(100,100);
   glutCreateWindow(" Simple ");
   glOrtho(-200,200,-200,200,-1.0,1.0);
   
   glutDisplayFunc(display);
   glutMainLoop();

   return 0;
}
