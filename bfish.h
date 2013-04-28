#ifndef FISH_H
#define FISH_H

#include "thing.h"

class BFish : public Thing{
public:
  BFish(QPixmap* p,int nx,int ny);
  int isType(){return 2;}
  int* getVel();
  QPainterPath shape() const;
private:
  void move();
  void animate();
  std::vector<QPixmap*> state;
  int vx;
  int vy;

};

#endif
