#ifndef DOLPHIN_H
#define DOLPHIN_H

#include "thing.h"

class Dolphin : public Thing{
public:
  Dolphin(QPixmap* p,int nx,int ny);
  int isType(){return 3;}
  int* getVel();
  void giveTarget(QGraphicsItem*);
  void increaseAttackSpeed();
private:
  void move();
  void animate();
  std::vector<QPixmap*> state;
  double vx;
  double vy;
  int health;
  QGraphicsItem* target;
  bool hasTarget;
  int atkspd;

};

#endif
