#ifndef THING_H
#define THING_H
#include <QGraphicsPixmapItem>

class Thing: public QGraphicsPixmapItem
{
public:
Thing (QPixmap* pm,int nx,int ny);
/** virtual because all things move differently*/  
int death;
virtual int isType()=0;
virtual void move() = 0; 
virtual int* getVel()=0;
/** virtual because different things may have different states of animation*/
virtual void animate()=0;
private: //Every thing has a origin and a velocity–maybe 0
QPixmap* pixMap; //Good idea. Explain later.
protected:
  int x_;
  int y_;
  int fps;
  int slower;
  unsigned int count;

  
};


#endif
