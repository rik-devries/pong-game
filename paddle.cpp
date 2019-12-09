#include <cmath>

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

paddle::paddle(){
  _height = 10;
  _width = 2;
  _speed = 1;
  setLocation(0);
}

paddle::~paddle(){
}

void paddle::moveUp(){
  _p.y += 1;
}

void paddle::moveDown(){
  _p.y -= 1;
}

void paddle::setSpeed(float speed){
  _speed = speed;
}

void paddle::setLocation(int side){
  switch(side){
    case 0:
      //Left side
      _p.x = -10;
      _p.y = 0;
      break;
    case 1:
      //Right side
      _p.x = 10;
      _p.y = 0;
      break;
    default:
      break;
  }
}

void paddle::draw(){
  glColor3f(_color.r, _color.g, _color.b);

	glBegin(GL_QUAD_STRIP);
	glVertex2f(_p.x - _width/2, _p.y + _height/2); //Top left corner
	glVertex2f(_p.x + _width/2, _p.y + _height/2); //Top right corner
	glVertex2f(_p.x - _width/2, _p.y - _height/2); //Bottom left corner
	glVertex2f(_p.x + _width/2, _p.y - _height/2); //Bottom right corner

	glEnd();
}
