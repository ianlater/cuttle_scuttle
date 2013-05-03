#ifndef CUTTLE_H
#define CUTTLE_H

#include <QGraphicsPixmapItem>
#include <QPointF>
#include <QRectF>
#include <QTimer>
#include <QObject>
#include "whale.h"


class MainWindow;

class Cuttle : public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT

public:

  /** creates cuttle with position and reference to window*/
  Cuttle(QPointF*,MainWindow* );
  /** set x velocity*/
  void setXVel(int x){velocity_[0]=x;}
  /** set y velocity*/
  void setYVel(int y){velocity_[1]=y;}
  /** manages being hit by a whale*/
  void hitByWhale(int*);
  /** sets target*/
  void setTarget(QPoint* t){target=t;}
  /** returns target*/
  QPoint* getTarget(){ return target;}
  /** sets bounded to true*/
  void bind(){bounded=true;caught=false;}
  /** cuttle is caught by fisher*/
  void catchHook(int*);
  /** sets bounded and caught to false*/
  void unbind(){caught=bounded=false;}
  /** returns invincible*/
  bool isInvincible(){return invincible;}
  /** sets hypnotizing to true*/
  void startHypnotizing(){hypnotizing=true;}
  /** sets hypnotizing to false*/
  void stopHypnotizing(){hypnotizing=false;}
  /** sets invincible to true*/
  void becomesInvincible(){invincible=true;}
  /** gets dammaged certain amout*/
  void hurt(int);
  /** heals cuttle*/
  void heal(int);
  /** returns a QString of items health*/
  QString getHealth();
  /** controls whether or not cuttle is dead*/
  int death;
private:
  /** vector of pixmaps for animation*/
  std::vector<QPixmap*> state;
  /** for modulating animation speed*/
  unsigned int count;
  /** reference to mainwindows timer: for movement*/
  QTimer* timer_;
  /** cuttle velocity*/
  int velocity_[2]; 
  /** boundaries for movement*/
  QRectF* bounds_;
  /** for modifying movement speed*/
  int slower;
  /** for modifying animation*/
  int fps;
  /** whether or not the cuttlefish can go off screen to right or left*/
  bool bounded;
  /** cuttle health*/
  int health;
  /** whether or not is invincible */
  bool invincible;
  /** cooldown after being invincible*/
  int cooldown;
  /** if the cuttlefish is caught by hook*/
  bool caught;
  /** point that is targeted*/
  QPoint* target;
  /** for hypnosis animation*/
  bool hypnotizing;
public slots:
  /** movement*/
  void move();
  /** animates cuttle*/
  void animate();
  
};

#endif 
