#ifndef CRAB_H
#define CRAB_H

#include "thing.h"

class Crab : public Thing{
public:
/** constructor*/
  Crab(QPixmap* p,int nx,int ny);
  /** returns type*/
  int isType(){return 4;}
  /** returns velocity*/
  int* getVel();
  /** kills crab*/
  void eat();
private:
/** moves*/
  void move();
  /** animates*/
  void animate();
  /** animation state*/
  std::vector<QPixmap*> state;
  /** x vel*/
  int vx;
  /** y vel*/
  int vy;

};

#endif
