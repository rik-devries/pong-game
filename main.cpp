//Include glut for all operating systems
#ifdef _WIN32
  #include <windows.h>
  #include <GL/freeglut.h>
#elif __APPLE__
  #include <GLUT/glut.h>
#elif __linux__
  #include <GL/freeglut.h>
#endif

#include "paddle.h"
#include "ball.h"

//Have to use global variables: https://community.khronos.org/t/opengl-global-variables/67004/2
paddle leftPaddle, rightPaddle;
ball mainBall;

void glDraw();
void TimeStep(int n); //Unsure if necessary
void handleUserInput(unsigned char key, int x, int y);

int main(int argc, char* argv[]){
  leftPaddle.setLocation(0);
  rightPaddle.setLocation(1);

  glutInit(&argc, argv);
  glutInitWindowSize(WINDOWSIZE, WINDOWSIZE);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutCreateWindow("Pong");
  glClearColor(0.0, 0.0, 0.0, 0.0); //The typical black pong background
  glClear(GL_COLOR_BUFFER_BIT);
  glutDisplayFunc(glDraw);
  glutTimerFunc(25, TimeStep, 25);
  glutKeyboardFunc(handleUserInput); //Set keyboard function
  glutMainLoop();
  return 0;
}

void glDraw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //Draw the paddles & ball
  object* allObjects[3] = { &leftPaddle, &rightPaddle, &mainBall };

  for(unsigned long i = 0; i < sizeof(allObjects)/sizeof(allObjects[0]); i++){
    allObjects[i]->draw();
  }

	glutSwapBuffers();
	glFlush();
}

void TimeStep(int n) {
	glutTimerFunc(n, TimeStep, n);
	glutPostRedisplay();
}

void handleUserInput(unsigned char key, int x, int y) {
  x = x; y = y; //To supress unused warnings: having int x and y is necessary for glutKeyboardFunc
  //Input is: Pressed key, and mouse X and Y (in the canvas) at moment of press
  switch(key) {
    case 'w':
    case 'W':
      //Up for left paddle
      leftPaddle.moveUp();
      break;
    case 's':
    case 'S':
      leftPaddle.moveDown();
      break;
    case 'p':
    case 'P':
      rightPaddle.moveUp();
      break;
    case 'l':
    case 'L':
      rightPaddle.moveDown();
      break;
  }
}
