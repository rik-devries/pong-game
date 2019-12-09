#ifndef OBJECT_H
#define OBJECT_H

class object {
  public:
    virtual object() = 0;
    virtual ~object() = 0;

    virtual void draw();

  private:
    colorRGB _color;
    point _anchor;

}

#endif
