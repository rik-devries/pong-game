//Include glut for all operating systems
#include <cmath>

#ifdef _WIN32
  #include <windows.h>
  #include <GL/freeglut.h>
#elif __APPLE__
  #include <GLUT/glut.h>
#elif __linux__
  #include <GL/freeglut.h>
#endif

#include "ball.h"

ball::ball(){
  _p.x = 0;
  _p.y = 0;
  _radius = 1;
  _color = { 1, 1, 1 };
}

ball::~ball(){}

void ball::draw(){
  point points[360];
  for (int i = 0; i < 360; i++){
    float radian = (M_PI * i) / 180;
    float x = _p.x + _radius * cos(radian);
    float y = _p.y + _radius * sin(radian);
    points[i] = { x, y };
  }

  glColor3f(_color.r, _color.g, _color.b);
  glBegin(GL_POLYGON);
  for(int i = 0; i < 360; i++){
    glVertex2f(points[i].x, points[i].y);
  }
  glEnd();
}
