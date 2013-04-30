#ifndef WHALE_H
#define WHALE_H

#include "thing.h"

class Whale : public Thing{
public:
/**constructor*/
  Whale(QPixmap* p,int nx,int ny);
  /** returns type*/
  int isType(){return 1;}
  /** returns velocity*/
  int* getVel();
private:
/**moves whale*/
  void move();
  /**animates*/
  void animate();
  /** animation frames*/
  std::vector<QPixmap*> state;
  /** x velocity*/
  int vx;
  /** y velocity*/
  int vy;

};

#endif
