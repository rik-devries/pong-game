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
  //TODO: add drawing function
}
