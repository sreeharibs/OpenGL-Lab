#include <GL/glut.h>
#include<math.h>
#include<ctime>
#include<unistd.h>


void init(){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);

}

void set_pixel(int x,int y){

    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(x,y);


    glEnd();


}

void circle(int r,int xc,int yc){


	int x,y,p;
	x=0;
	y=r;
	p=3-2*r;
	while(x<=y)
	{
		if(p<0)
		{
			p=p+(4*x)+6;
			x++;
			set_pixel(xc+x,yc+y);
			set_pixel(xc+x,yc-y);
			set_pixel(xc-x,yc+y);
			set_pixel(xc-x,yc-y);
			set_pixel(xc+y,yc+x);
			set_pixel(xc+y,yc-x);
			set_pixel(xc-y,yc+x);
			set_pixel(xc-y,yc-x);
		}
		else
		{
			p=p+(4*x)-(4*y)+10;
			x++;
			y--;
			set_pixel(xc+x,yc+y);
			set_pixel(xc+x,yc-y);
			set_pixel(xc-x,yc+y);
			set_pixel(xc-x,yc-y);
			set_pixel(xc+y,yc+x);
			set_pixel(xc+y,yc-x);
			set_pixel(xc-y,yc+x);
			set_pixel(xc-y,yc-x);
		}
	}
}

void draw(void)
{
	int x=40,y=30,x1,x2,y1,y2,x3,y3,x4,y4,i=1;
	float p=0,q=0,r=0;
	glColor3f(1.0,0.0,0.0);
	glClearColor(1,1,1,1);
	while(i!=0)
	{
	glColor3f(1.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	circle(40,40,30);
	glBegin(GL_LINES);
        glPointSize(10);
        glColor3f(0.0,0.0,0.0);
        //min
        glVertex2i(40,-10);
        glVertex2i(40,-5);
        glVertex2i(75,30);
        glVertex2i(80,30);
        glVertex2i(0,30);
        glVertex2i(5,30);
        glVertex2i(40,70);
        glVertex2i(40,65);
        //hands
            p=p-(2*3.14)/60;
            x1=((40-x)*cos(p))-((30-y)*sin(p));
            y1=((30-y)*cos(p)+(40-x)*sin(p));
            x2=((40-x)*cos(p))-((65-y)*sin(p));
            y2=((65-y)*cos(p)+(40-x)*sin(p));
            glVertex2f(x1+x,y1+y);
            glVertex2f(x2+x,y2+y);

            q=q-(2*3.14)/3600;
            x3=((40-x)*cos(q))-((30-y)*sin(q));
            y3=((30-y)*cos(q)+(40-x)*sin(q));
            x4=((40-x)*cos(q))-((55-y)*sin(q));
            y4=((55-y)*cos(q)+(40-x)*sin(q));
            glVertex2f(x3+x,y3+y);
            glVertex2f(x4+x,y4+y);

            r=r-(2*3.14)/(3600*60);
            x3=((40-x)*cos(r))-((30-y)*sin(r));
            y3=((30-y)*cos(r)+(40-x)*sin(r));
            x4=((40-x)*cos(r))-((45-y)*sin(r));
            y4=((45-y)*cos(r)+(40-x)*sin(r));
            glVertex2f(x3+x,y3+y);
            glVertex2f(x4+x,y4+y);
		glEnd();
		usleep(1000000);
		glFlush();
	}
glutPostRedisplay();
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB );
  glutInitWindowPosition(10,10);
  glutInitWindowSize(500,500);
  glutCreateWindow("MID_CIRCLE");
  init();
  glutDisplayFunc(draw);
  glutMainLoop();
  return 0;
}
