#ifndef FISH_H
#define FISH_H

#include "thing.h"
#include "cuttle.h"

class BFish : public Thing{
public:
/** constructor*/
  BFish(QPixmap* p,int nx,int ny);
  /** returns type*/
  int isType(){return 2;}
  /** returns velocity*/
  int* getVel();
  /** specifies shape*/
  QPainterPath shape() const;
  /** hypnotizes bfish*/
  void hypnotize(Cuttle*);
private:
/**moves*/
  void move();
  /** animates*/
  void animate();
  /** framestate of animation*/
  std::vector<QPixmap*> state;
  /** x vel*/
  double vx;
  /** y vel*/
  double vy;
  /** whether or not bfish is hypnotized*/
  bool hypnotized;
  /** cuttle that has hypnotized it*/
  Cuttle* myCuttle;
  /** target for being fired*/
  QPoint* target_;
  /** whether or not has been fired*/
  bool fired;
  /** whether or not target has been set*/
  bool targetFixed;

};

#endif
