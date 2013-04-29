#ifndef CRAB_H
#define CRAB_H

#include "thing.h"

class Crab : public Thing{
public:
  Crab(QPixmap* p,int nx,int ny);
  int isType(){return 4;}
  int* getVel();
  void eat();
private:
  void move();
  void animate();
  std::vector<QPixmap*> state;
  int vx;
  int vy;

};

#endif
