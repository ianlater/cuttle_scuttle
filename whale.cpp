#include "whale.h"
#include <iostream>
#include "cuttle.h"

/** constructs whale, calls Thing constructor*/
Whale::Whale(QPixmap* p,int nx,int ny): Thing(p,nx,ny)
{
  vx=rand()%5+5;
  vy=0;
  for(int i=1;i<9;i++){
    QString fn="whale/w";fn.append(QString::number(i));fn.append(".png");
    QPixmap* t=new QPixmap(fn);    
    t=new QPixmap(t->scaled(800,350));
    setPixmap(*t);
    state.push_back(t);
  }/*
  for(int i=1;i<6;i++){
    QString fn="cuttle/c";fn.append(QString::number(i));fn.append(".bmp");
    QPixmap p(fn);

    setPixmap(*t);
    state.push_back(t);
  }*/

}

/** moves */
void Whale::move(){
 if(++slower%20==0){
  setPos(x()-vx,y()+vy);
 }
}
/** animates*/
void Whale::animate(){
 if(++fps%20==0){
   if(++count>=state.size()) count=0;
   setPixmap(*(state[count]));
 }
}
/** returns velocity*/
int* Whale::getVel(){
  int* vel=new int(2);
  vel[0]=vx;vel[1]=vy;
  return vel;
}



