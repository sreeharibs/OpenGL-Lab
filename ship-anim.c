#include<GL/glut.h>
int i=0,j=0;
void init(void)
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,100,0,100);
}
void linesegment()
{
glClearColor(0.0f,0.0f,0.0f,1.0f);
glClear(GL_COLOR_BUFFER_BIT);

glLineWidth(3);
glPointSize(2);
glBegin(GL_POLYGON);
glColor3f(0.0,1.0,0.0);
glVertex2i(15+i+j,10);
glVertex2i(10+i+j,20);
glVertex2i(45+i+j,20);
glVertex2i(40+i+j,10);
glVertex2i(15+i+j,10);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.0,0.1,0.7);
glVertex2i(20+i+j,20);
glVertex2i(20+i+j,27);
glVertex2i(25+i+j,27);
glVertex2i(25+i+j,20);
glVertex2i(25+i+j,25);
glVertex2i(30+i+j,25);
glVertex2i(30+i+j,23);
glVertex2i(35+i+j,23);
glVertex2i(35+i+j,20);
glEnd();
	if(i<130)
	{
	  i=i+1;
	}
	else if(i>0&&j>-150)
	{
	  j--;
	}
	else
	{
	i=0;
	j=0;
	}
	usleep(10000);
	glutPostRedisplay();
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
