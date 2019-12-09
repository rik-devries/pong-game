#ifndef BALL_H
#define BALL_H

#include "point.h"
#include "paddle.h"

class ball {
  public:
    //Will also move up/down
    void moveLeft();
    void moveRight();

    void setSpeed();

    bool collideWith(paddle paddle);
  private:
    point _p;
    int _speed;
};

#endif
