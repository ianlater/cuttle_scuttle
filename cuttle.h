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
  Cuttle();
  Cuttle(QPointF*,MainWindow* );
  ~Cuttle(){}

  void setXVel(int x){velocity_[0]=x;}
  void setYVel(int y){velocity_[1]=y;}
  void hitByWhale(int*);
  void setTarget(QPoint* t){target=t;}
  QPoint* getTarget(){ return target;}
  void bind(){bounded=true;}
  void catchHook(int*);
  void unbind(){caught=false;bounded=false;}
  bool isInvincible(){return invincible;}
  void becomesInvincible(){invincible=true;}
  void hurt(int);
  void heal(int);
  QString getHealth();
  int death;
private:
  std::vector<QPixmap*> state;
  unsigned int count;
  /** reference to mainwindows timer: for movement*/
  QTimer* timer_;
  int velocity_[2]; 
  QRectF* bounds_;
  int slower;
  int fps;
  QPoint* target;
  bool bounded;
  int health;
  bool invincible;
  int cooldown;
  bool caught;
public slots:
  void move();
  void animate();
  
};

#endif 
