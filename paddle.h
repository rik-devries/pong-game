#ifndef PADDLE_H
#define PADDLE_H

#include "point.h"

class paddle {
  public:
    void moveUp();
    void moveDown();
    void setSpeed();

  private:
    int _height;
    int _width;
    point _p;
    float _speed;
};

#endif
