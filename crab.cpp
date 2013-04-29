#include "crab.h"
#include <iostream>
#include "cuttle.h"

Crab::Crab(QPixmap* p,int nx,int ny): Thing(p,nx,ny)
{
  vx=rand()%5+5;
  vy=4;
 /* for(int i=1;i<6;i++){
    QString fn="Crab/w";fn.append(QString::number(i));fn.append(".bmp");
    QPixmap* t=new QPixmap(fn);
    setPixmap(*t);
    state.push_back(t);
  }*/
  for(int i=1;i<6;i++){
    QString fn="cuttle/c";fn.append(QString::number(i));fn.append(".bmp");
    QPixmap p(fn);
    QPixmap* t=new QPixmap(p.scaled(30,30));
    setPixmap(*t);
    state.push_back(t);
  }

}

void Crab::eat(){
  death+=999999999;
  setPos(-1,-1);
}

void Crab::move(){
 if(zValue()==3) eat();
 if(++slower%20==0){
  if(slower%80==0 ) vy=-vy;
  setPos(x()-vx,y()+vy);

 }
}

void Crab::animate(){
 if(++fps%20==0){
   if(++count>=state.size()) count=0;
   setPixmap(*(state[count]));
 }
}

int* Crab::getVel(){
  int* vel=new int(2);
  vel[0]=vx;vel[1]=vy;
  return vel;
}



