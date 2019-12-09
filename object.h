#ifndef OBJECT_H
#define OBJECT_H

class object {
  public:
    virtual ~object() = 0;
    virtual void draw() = 0;
};

#endif
