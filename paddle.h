#ifndef PADDLE_H
#define PADDLE_H

#include "structs.h"
#include "object.h"

class paddle : public object {
  public:
    //Constructors/destructors
    paddle();
    ~paddle();

    void moveUp();
    void moveDown();
    void setSpeed(float speed);
    void setLocation(int side); //Either left (0) or right (1)
    void draw();
  private:
    int _height;
    int _width;
    point _p;
    float _speed;
};

#endif
