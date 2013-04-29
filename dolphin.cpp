#include "dolphin.h"
#include <iostream>
#include "cuttle.h"
#include "bfish.h"
#include <QGraphicsScene>

Dolphin::Dolphin(QPixmap* p,int nx,int ny): Thing(p,nx,ny)
{
  p=new QPixmap(p->scaled(200,80));
  //state.push_back(p);
  vx=rand()%5+12;
  vy=rand()%10+5;
 /* for(int i=1;i<6;i++){
    QString fn="Dolphin/w";fn.append(QString::number(i));fn.append(".bmp");
    QPixmap* t=new QPixmap(fn);
    setPixmap(*t);
    state.push_back(t);
  }*/
  for(int i=1;i<6;i++){
    QString fn="cuttle/c";fn.append(QString::number(i));fn.append(".bmp");
    QPixmap p(fn);
    QPixmap* t=new QPixmap(p.scaled(200,80));
    setPixmap(*t);
    state.push_back(t);
  }
 setZValue(5);
 health=100;
 hasTarget=false;
 atkspd=50;
}


void Dolphin::move(){
 if(zValue()==-1) health-=50;
 if(health>0){ 
  if(++slower%20==0){
    if(slower%80==0 && rand()%7==0) vy=-vy;
    if(hasTarget){
      vy=(target->y()-y())/atkspd;
      setPos(x()-vx,y()+vy);
    }
    if(y()+vy<=(scene()->sceneRect()).top()) vy=-vy;
    setPos(x()-vx,y()+vy);
  }
 }else{
  setZValue(-12);
  death+=999999999;
  setPos(-1,-1);
  }
}

void Dolphin::animate(){
 if(++fps%20==0){
   if(++count>=state.size()) count=0;
   setPixmap(*(state[count]));
 }
}

int* Dolphin::getVel(){
  int* vel=new int(2);
  vel[0]=vx;vel[1]=vy;
  return vel;
}

void Dolphin::giveTarget(QGraphicsItem* t){
  target=t;
  hasTarget=true;

}
void Dolphin::increaseAttackSpeed(){
  atkspd-=15;
  if(atkspd<=0)atkspd=1;
}


