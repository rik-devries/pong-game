#ifndef BALL_H
#define BALL_H

#include "structs.h"
#include "paddle.h"

class ball : public object {
  public:
    //Constructors/destructors
    ball();
    ~ball();

    //Will also move up/down
    void moveLeft();
    void moveRight();
    void setSpeed();
    bool collideWith(paddle paddle);
    void draw();
  private:
    point _p;
    float _radius;
    float _speed;
    colorRGB _color;
};

#endif
