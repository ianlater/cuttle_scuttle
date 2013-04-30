#include "bfish.h"
#include <QGraphicsScene>
#include <iostream>
#include <cmath>

/** constructs with default thing constructor*/
BFish::BFish(QPixmap* p,int nx,int ny): Thing(p,nx,ny)
{
  p=new QPixmap(p->scaled(40,15));
  state.push_back(p);
  vx=rand()%10+15;
  vy=rand()%10+5;
  /*for(int i=1;i<6;i++){
    QString fn="fishes/bf";fn.append(QString::number(i));fn.append(".bmp");
    QPixmap* t=new QPixmap(fn);
    setPixmap(*t);
    state.push_back(t);
  }*/
  setZValue(rand()%6+45);
  hypnotized=fired=targetFixed=false;

}
/** gives the hypnotizing cuttle*/
void BFish::hypnotize(Cuttle* c){
  hypnotized=true;
  myCuttle=c;
  setParentItem(c);
  if(fired) fired=targetFixed=false;
}
/** moves, being hypnotized makes it hover around cuttle, being shot sends it towards target*/
void BFish::move(){
 if(++slower%20==0){
  if(slower%80==0 && rand()%7==0 && !fired) vy=-vy;
  if(hypnotized){ 
    QRectF bounds=myCuttle->boundingRect();
    if(zValue()<0){
      hypnotized=false;
      target_=myCuttle->getTarget();
      setParentItem(0);
      setPos(myCuttle->x()+rand()%50,myCuttle->y()-rand()%35);
      fired=true;
      setZValue(rand()%6+45);
    }
    else {
      if(x()-vx<=bounds.left()) vx=-vx;
      else if(x()-vx>=bounds.right()) vx=-vx;
      if(y()+vy<=bounds.top()) vy=-vy;
      else if(y()+vy>=bounds.bottom()) vy=-vy;
      setPos(myCuttle->x()+rand()%50,myCuttle->y()-rand()%35);
      setPos(mapFromParent(myCuttle->pos()));
      setZValue(rand()%6+45);
    }
  }
  if(!fired){
    if(y()+vy<=(scene()->sceneRect()).top()) vy=-vy;
    setPos(x()-vx,y()+vy);
  }
  else{
    if(!targetFixed){
      vx=(target_->x()-x()); vy=(target_->y()-y());
      targetFixed=true;
    }    
    setPos(x()+vx/4,y()+vy/4);
    QList<QGraphicsItem *> collisions=scene()->items(pos());
    for(int i=0;i<collisions.size();i++){
      if(collisions[i]->zValue()==5){
         collisions[i]->setZValue(-1);
         break;
      }
    }
  }
 }
}
/** animates*/
void BFish::animate(){
 if(++fps%20==0){
   if(++count>=state.size()) count=0;
   setPixmap(*(state[0]));
 }
}
/** returns velocity*/
int* BFish::getVel(){
  int* vel=new int(2);
  vel[0]=vx;vel[1]=vy;
  return vel;
}
/** specifies shape as ellipse*/
QPainterPath BFish::shape() const
{
     QPainterPath path;
     path.addEllipse(QRectF(state[0]->rect()));
     return path;
}



