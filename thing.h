#ifndef THING_H
#define THING_H
#include <QGraphicsPixmapItem>

class Cuttle;
class Thing: public QGraphicsPixmapItem
{
public:
/** Constructs thing */
Thing (QPixmap* pm,int nx,int ny);
/** virtual because all things move differently*/  
int death;
/** all Things must specify type for collisions*/
virtual int isType()=0;
/** all things move*/
virtual void move() = 0;
/** all things must return some kind of velocity*/ 
virtual int* getVel()=0;
/** Some things can be hypnotized by the cuttle fish*/
virtual void hypnotize(Cuttle*){}
/** virtual because different things may have different states of animation*/
virtual void animate()=0;
private: //Every thing has a origin and a velocity–maybe 0
QPixmap* pixMap; //Good idea. Explain later.
protected:
/** x loc*/
  int x_;
  /** y loc*/
  int y_;
  /** for animation*/
  int fps;
  /** mods movement*/
  int slower;
  /** also mods movement and special events*/
  unsigned int count;

  
};


#endif
