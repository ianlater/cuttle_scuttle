#include "whale.h"
#include <iostream>

Whale::Whale(QPixmap* p,int nx,int ny): Thing(p,nx,ny)
{
  p=new QPixmap(p->scaled(800,350));
  state.push_back(p);
vx=rand()%5+5;
vy=0;
for(int i=1;i<6;i++){
    QString fn="whale/w";fn.append(QString::number(i));fn.append(".bmp");
    QPixmap* t=new QPixmap(fn);
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
   setPixmap(*(state[0]));
 }
}

int* Whale::getVel(){
  int vel[2]={vx,vy};
  return vel;
}

QPainterPath Whale::shape() const
{
     QPainterPath path;
     path.addRect(QRectF(state[0]->rect()));
     return path;
}
