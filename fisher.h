#ifndef FISHER_H
#define FISHER_H

#include "thing.h"
#include <QGraphicsRectItem>

class Fisher : public Thing{
public:
  Fisher(QPixmap* p,int nx,int ny);
  int isType(){return 5;}
  int* getVel();
  void increaseAttackSpeed();
private:
  void move();
  void animate();
  std::vector<QPixmap*> state;
  int vx;
  int vy;
  int atkspd;
  QGraphicsRectItem* line;

};

#endif
