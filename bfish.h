#ifndef FISH_H
#define FISH_H

#include "thing.h"
#include "cuttle.h"

class BFish : public Thing{
public:
  BFish(QPixmap* p,int nx,int ny);
  int isType(){return 2;}
  int* getVel();
  QPainterPath shape() const;
  void hypnotize(Cuttle*);
private:
  void move();
  void animate();
  std::vector<QPixmap*> state;
  double vx;
  double vy;
  bool hypnotized;
  Cuttle* myCuttle;
  QPoint* target_;
  bool fired;
  bool targetFixed;

};

#endif
