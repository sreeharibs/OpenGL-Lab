#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

#define pi 22/7

int i=0,j,k,n;
float sum=0;
float m[10][3],mt[3][3],mPdt[10][3];

float tx= 5 , ty = 5 ;
float sx= 2 , sy = 2 ;
float theta = 30;

void init(){

    glClearColor( 0.0,0.0,0.0,1.0 );
    gluOrtho2D( -100 , 100 , -100 , 100 );

}

void matrixInit(){

   for(i=0;i<3;i++)
	for(j=0;j<3;j++)
		mt[i][j]=(i==j);
}

void matrixMult(){

    for( i=0;i<n;i++ ){
            for( j=0;j<3;j++ ) {
                for( k=0;k<3;k++ )

                    sum=sum+m[i][k]*mt[k][j];

                mPdt[i][j]=sum;
                sum=0;
            }
   }



}

void matrixCopyPdt(){

    for(i=0;i<n;i++)
        for(j=0;j<3;j++)
            m[i][j]=mPdt[i][j];


}

void translate(){

    matrixInit();

    mt[2][0] = tx;
    mt[2][1] = ty;

    matrixMult();
    matrixCopyPdt();


}

void scale(){

    matrixInit();

    mt[0][0] = sx;
    mt[1][1] = sy;

    matrixMult();
    matrixCopyPdt();


}

void rotate(){

    matrixInit();

    mt[0][0]=cos(theta*pi/180);
    mt[0][1]=sin(theta*pi/180);;
	mt[1][0]=-sin(theta*pi/180);;
   	mt[1][1]=cos(theta*pi/180);;

    matrixMult();
    matrixCopyPdt();


}

void display(){

    glClear( GL_COLOR_BUFFER_BIT );

    //static - ship
    glBegin(GL_LINE_LOOP);

            glColor3f( 1.0 , 0.0 , 0.0 );

            for( i = 0 ; i < n ; i++ )
                glVertex2f( m[i][0] , m[i][1] );



    glEnd();

    glutSwapBuffers();

}


void keyPressed( unsigned char key , int x , int y ){

    switch(key){

        case 't': translate(); break;
        case 's': scale();     break;
        case 'r': rotate();    break;
    }

}

int main( int argc, char **argv ){

    printf( "\n Enter the no: of vertices : " );
    scanf( "%d",&n );

    printf( "\n Enter the points (x,y) : " );
    for( i = 0 ; i < n ; i++ )
        scanf( "%f%f",& m[i][0], &m[i][1] );

    for( i = 0 ; i < n ; i++ )
        m[i][2] = 1 ;


    glutInit( &argc , argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA );
    glutInitWindowSize( 650 , 650 );
    glutInitWindowPosition( 10 , 10 );
    glutCreateWindow( "2D Trans" );

    init();

    //callback functions
    glutDisplayFunc( display );
    glutIdleFunc( display );
    glutKeyboardFunc( keyPressed );

    glutMainLoop();

    return 0;

}

