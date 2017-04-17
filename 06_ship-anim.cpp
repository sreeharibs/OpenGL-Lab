#include<stdio.h>
#include<GL/glut.h>

int i=0;

void init(){

    glClearColor( 0.0,0.0,0.0,1.0 );
    gluOrtho2D( 0 , 100 , 0 , 100 );

}

void display(){

    glClear( GL_COLOR_BUFFER_BIT );

    //static - ship
    glBegin(GL_POLYGON);

            glColor3f( 1.0 , 0.0 , 0.0 );

            glVertex2i( 10+i , 30 );
            glVertex2i( 40+i , 30 );
            glVertex2i( 35+i , 20 );
            glVertex2i( 15+i , 20 );

    glEnd();

    glBegin(GL_POLYGON);

            glColor3f( 0.0 , 0.0 , 1.0 );

            glVertex2i( 15+i , 30 );
            glVertex2i( 15+i , 42 );
            glVertex2i( 20+i , 42 );
            glVertex2i( 20+i , 38 );
            glVertex2i( 25+i , 38 );
            glVertex2i( 25+i , 34 );
            glVertex2i( 30+i , 34 );
            glVertex2i( 30+i , 30 );

    glEnd();

    i++;

    if(i>100) i=-30;

    glutSwapBuffers();

}


int main( int argc, char **argv ){

    glutInit( &argc , argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA );
    glutInitWindowSize( 650 , 650 );
    glutInitWindowPosition( 10 , 10 );
    glutCreateWindow( "My Ship" );

    init();

    //callback functions
    glutDisplayFunc( display );
    glutIdleFunc( display );

    glutMainLoop();

}

