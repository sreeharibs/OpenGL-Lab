#include<GL/glut.h>
void init(void)	
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,50,0,50);
}
void linesegment()
{
glClearColor(0.0f,0.0f,0.0f,1.0f);
glClear(GL_COLOR_BUFFER_BIT);

glLineWidth(3);
glPointSize(2);
glBegin(GL_POLYGON);
glColor3f(0.0,1.0,0.0);
glVertex2i(15,10);
glVertex2i(10,20);
glVertex2i(45,20);
glVertex2i(40,10);
glVertex2i(15,10);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.0,0.1,0.7);
glVertex2i(20,20);
glVertex2i(20,27);
glVertex2i(25,27);
glVertex2i(25,20);
glVertex2i(25,25);
glVertex2i(30,25);
glVertex2i(30,23);
glVertex2i(35,23);
glVertex2i(35,20);
glEnd();
glFlush();
}
int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(250,250);
 glutInitWindowSize(700,700);
 glutCreateWindow("SHIP");
 init();
 glutDisplayFunc(linesegment);
 glutMainLoop();
 return 0;
}
