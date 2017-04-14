#include<stdio.h>
#include<GL/glut.h>

void init(){

    glClearColor( 0.0,0.0,0.0,1.0 );
    gluOrtho2D( 0 , 100 , 0 , 100 );

}

void display(){

    glClear( GL_COLOR_BUFFER_BIT );

    //static - ship
    glBegin(GL_POLYGON);

            glColor3f( 1.0 , 0.0 , 0.0 );

            glVertex2i( 10 , 30 );
            glVertex2i( 40 , 30 );
            glVertex2i( 35 , 20 );
            glVertex2i( 15 , 20 );

    glEnd();

    glBegin(GL_POLYGON);

            glColor3f( 0.0 , 0.0 , 1.0 );

            glVertex2i( 15 , 30 );
            glVertex2i( 15 , 42 );
            glVertex2i( 20 , 42 );
            glVertex2i( 20 , 38 );
            glVertex2i( 25 , 38 );
            glVertex2i( 25 , 34 );
            glVertex2i( 30 , 34 );
            glVertex2i( 30 , 30 );

    glEnd();

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

    glutMainLoop();

}

