#ifndef FISHER_H
#define FISHER_H

#include "thing.h"
#include <QGraphicsRectItem>

class Fisher : public Thing{
public:
/** constructor*/
  Fisher(QPixmap* p,int nx,int ny);
  /** returns type*/
  int isType(){return 5;}
  /**returns velocity*/
  int* getVel();
  /**increments atkspd*/
  void increaseAttackSpeed();
private:
/** moves*/
  void move();
  /** animates*/
  void animate();
  /** animation state*/
  std::vector<QPixmap*> state;
  /** x vel*/
  int vx;
  /** y vel */
  int vy;
  /** how fast fisher pulls up on line*/
  int atkspd;
  /** image of fishing line*/
  QGraphicsRectItem* line;

};

#endif
