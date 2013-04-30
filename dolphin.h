#ifndef DOLPHIN_H
#define DOLPHIN_H

#include "thing.h"

class Dolphin : public Thing{
public:
/** constructor*/
  Dolphin(QPixmap* p,int nx,int ny);
  /** returns type*/
  int isType(){return 3;}
  /** returns velocity*/
  int* getVel();
  /** sets target*/
  void giveTarget(QGraphicsItem*);
  /** increments atkspd*/
  void increaseAttackSpeed();
private:
/** moves*/
  void move();
  /** animates*/
  void animate();
  /** animation state*/
  std::vector<QPixmap*> state;
  /** x vel*/
  double vx;
  /** y vel*/
  double vy;
  /** health*/
  int health;
  /** target that dolphin moves towars*/
  QGraphicsItem* target;
  /** if it has a target*/
  bool hasTarget;
  /** how fast it moves towards target*/
  int atkspd;

};

#endif
