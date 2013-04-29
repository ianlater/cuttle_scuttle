#include "whale.h"
#include <iostream>
#include "cuttle.h"

Whale::Whale(QPixmap* p,int nx,int ny): Thing(p,nx,ny)
{
  vx=rand()%5+5;
  vy=0;
 /* for(int i=1;i<6;i++){
    QString fn="whale/w";fn.append(QString::number(i));fn.append(".bmp");
    QPixmap* t=new QPixmap(fn);
    setPixmap(*t);
    state.push_back(t);
  }*/
  for(int i=1;i<6;i++){
    QString fn="cuttle/c";fn.append(QString::number(i));fn.append(".bmp");
    QPixmap p(fn);
    QPixmap* t=new QPixmap(p.scaled(800,350));
    setPixmap(*t);
    state.push_back(t);
  }

}


void Whale::move(){
 if(++slower%20==0){
  setPos(x()-vx,y()+vy);
  //std::cout<<x()<<","<<y()<<std::endl;
 }
}

void Whale::animate(){
 if(++fps%20==0){
   if(++count>=state.size()) count=0;
   setPixmap(*(state[count]));
 }
}

int* Whale::getVel(){
  int* vel=new int(2);
  vel[0]=vx;vel[1]=vy;
  return vel;
}



