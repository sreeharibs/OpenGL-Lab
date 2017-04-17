#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

#include<ctime>
#include<unistd.h>
int k,j=0;

void init(void){

    glClearColor(0.0,0.0,0.0,1.0);
    gluOrtho2D(0.0,200.0,0.0,200.0);

}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);


    glLineWidth(3);
    glColor3f( 1.0,1.0,1.0 );

    //pipe
    glBegin(GL_LINES);

        glVertex2i(0,160);
        glVertex2i(100,160);

        glVertex2i(0,165);
        glVertex2i(100,165);

    glEnd();


    //bucket
    glBegin(GL_LINE_STRIP);

        glVertex2i(50,120);
        glVertex2i(50,20);
        glVertex2i(150,20);
        glVertex2i(150,120);

    glEnd();


    //water droplets
    glColor3f(0.0,0.0,1.0);
    glPointSize(10);
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);

        for(int j=0;j<15;j++)
            glVertex2f(102,163-10*j);

    glEnd();


    //fill water
    glBegin(GL_LINES);

        for(int i=21;i<22+j;i++){

            glVertex2f(51,i);
            glVertex2f(149,i);


            usleep(1000);
        }

    if(j<100) j++;

    glEnd();


    glutSwapBuffers();

}
int main(int argc,char **argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bucket fill");
    init();

    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop();

    return 0;
}
