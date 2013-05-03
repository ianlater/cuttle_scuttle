#include "crab.h"
#include <iostream>
#include "cuttle.h"
/** contructor calls thing constructor*/
Crab::Crab(QPixmap* p,int nx,int ny): Thing(p,nx,ny)
{
  vx=rand()%5+5;
  vy=4;
  for(int i=1;i<4;i++){
    QString fn="crab/cr";fn.append(QString::number(i));fn.append(".png");
    QPixmap* t=new QPixmap(fn);
    t=new QPixmap(t->scaled(30,30));
    setPixmap(*t);
    state.push_back(t);
  }

}
/** is eaten, kills crab*/
void Crab::eat(){
  death+=999999999;
  setPos(-1,-1);
}
/** moves*/
void Crab::move(){
 if(zValue()==3) eat();
 if(++slower%20==0){
  if(slower%80==0 ) vy=-vy;
  setPos(x()-vx,y()+vy);

 }
}
/** animates*/
void Crab::animate(){
 if(++fps%20==0){
   if(++count>=state.size()) count=0;
   setPixmap(*(state[count]));
 }
}
/** return velocity*/
int* Crab::getVel(){
  int* vel=new int(2);
  vel[0]=vx;vel[1]=vy;
  return vel;
}



