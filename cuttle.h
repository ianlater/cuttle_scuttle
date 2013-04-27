#ifndef CUTTLE_H
#define CUTTLE_H

#include <QGraphicsPixmapItem>
#include <QPointF>
#include <QRectF>
#include <QTimer>
#include <QObject>

class MainWindow;

class Cuttle : public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT

public:
  Cuttle();
  Cuttle(QPointF*,MainWindow* );
  ~Cuttle(){}
  QPainterPath shape() const;
  void setXVel(int x){velocity_[0]=x;}
  void setYVel(int y){velocity_[1]=y;}
private:
  std::vector<QPixmap*> state;
  unsigned int count;
  /** reference to mainwindows timer: for movement*/
  QTimer* timer_;
  int velocity_[2]; 
  QRectF bounds_;
  int slower;
  
public slots:
  void move();
  
};

#endif 
