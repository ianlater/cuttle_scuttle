#include "bfish.h"
#include <QGraphicsScene>
#include <iostream>

BFish::BFish(QPixmap* p,int nx,int ny): Thing(p,nx,ny)
{
  p=new QPixmap(p->scaled(40,15));
  state.push_back(p);
  vx=rand()%10+15;
  vy=rand()%10+5;
  for(int i=1;i<6;i++){
    QString fn="Fishes/bf";fn.append(QString::number(i));fn.append(".bmp");
    QPixmap* t=new QPixmap(fn);
    setPixmap(*t);
    state.push_back(t);
  }

}


void BFish::move(){
 if(++slower%20==0){
  if(slower%80==0 && rand()%7==0) vy=-vy;
  if(y()+vy<=(scene()->sceneRect()).top()) vy=-vy;
  setPos(x()-vx,y()+vy);
 }
}

void BFish::animate(){
 if(++fps%20==0){
   if(++count>=state.size()) count=0;
   setPixmap(*(state[0]));
 }
}

int* BFish::getVel(){
  int vel[2]={vx,vy};
  return vel;
}

QPainterPath BFish::shape() const
{
     QPainterPath path;
     path.addEllipse(QRectF(state[0]->rect()));
     return path;
}
