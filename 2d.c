#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include<GL/gl.h>
#include<GL/glut.h>

#define pi 22/7



int i,j,n;
float m[10][3],msave[10][3],mfin[10][3],mt[3][3],sum=0;
int k;

float tx=5,ty=5,sx=1.2,sy=1.2,theta=30;

void matrixInit(){
 
   for(i=0;i<3;i++)
	for(j=0;j<3;j++)
		if (i==j) mt[i][j]=1; else mt[i][j]=0;
}

void matrixMult(){

   for(i=0;i<n;i++){
	for(j=0;j<3;j++){
		for(k=0;k<3;k++)
			sum=sum+m[i][k]*mt[k][j];
		mfin[i][j]=sum;
		sum=0;
	}
   }

   for(i=0;i<n;i++)
	for(j=0;j<3;j++)
		m[i][j]=mfin[i][j];

}

void display(){
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_LINE_LOOP);
      glColor3f(1.0,0.0,0.0);
      for(i=0;i<n;i++)
         glVertex2i(m[i][0],m[i][1]);
   glEnd();
   glFlush();

}

void init(){
   glClearColor(0.0,0.0,0.0,0.0);
   glColor3f(1.f,1.0f,1.0f);
   glOrtho(-100.0,100.0,-100.0,100.0,-1.0,1.0);
   

}

void restore(){
   //RESTORE from save
   for(i=0;i<n;i++)
	for(j=0;j<3;j++)
		m[i][j]=msave[i][j];


}

void translate(){
		matrixInit();
   		mt[2][0]=tx;
   		mt[2][1]=ty;
   
   		matrixMult();

}

void scale(){
   		matrixInit();
		mt[0][0]=sx;
   		mt[1][1]=sy;
   
   		matrixMult();

}


void rotate(){
   		matrixInit();
		mt[0][0]=cos(theta*pi/180);
   		mt[0][1]=sin(theta*pi/180);;
		mt[1][0]=-sin(theta*pi/180);;
   		mt[1][1]=cos(theta*pi/180);;
   
   		matrixMult();

}

void keyPressed (unsigned char key, int x, int y) {

  switch(key){

	case 'z': restore(); display(); break;
	case 't': translate(); display(); break;
	case 's': scale(); display(); break;
	case 'r': rotate(); display(); break;
  }

}  

int main(int argc, char** argv){


   printf("\n Enter the no: of vertices : ");
   scanf("%d",&n);

   printf("\n Enter the points : \n ");
   for(i=0;i<n;i++)
      for(j=0;j<2;j++)
          scanf("%f",&m[i][j]);

   for(i=0;i<n;i++)
      m[i][2]=1;

   //saving the matrix for future use - RESTORE
   for(i=0;i<n;i++)
	for(j=0;j<3;j++)
		msave[i][j]=m[i][j];


   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutInitWindowSize(500,500);
   glutInitWindowPosition(100,100);
   glutCreateWindow(" 2D Transformation ");
   init();
   glutDisplayFunc(display);
   glutKeyboardFunc(keyPressed);
   glutMainLoop();

   return 0;
}


