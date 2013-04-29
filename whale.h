#ifndef WHALE_H
#define WHALE_H

#include "thing.h"

class Whale : public Thing{
public:
  Whale(QPixmap* p,int nx,int ny);
  int isType(){return 1;}
  int* getVel();
private:
  void move();
  void animate();
  std::vector<QPixmap*> state;
  int vx;
  int vy;

};

#endif
