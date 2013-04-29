#include "fisher.h"
#include <iostream>
#include "cuttle.h"
#include <QBrush>

Fisher::Fisher(QPixmap* p,int nx,int ny): Thing(p,nx,ny)
{
  vx=rand()%5+5;
  vy=5;
 /* for(int i=1;i<6;i++){
    QString fn="Fisher/w";fn.append(QString::number(i));fn.append(".bmp");
    QPixmap* t=new QPixmap(fn);
    setPixmap(*t);
    state.push_back(t);
  }*/
  for(int i=1;i<6;i++){
    QString fn="cuttle/c";fn.append(QString::number(i));fn.append(".bmp");
    QPixmap p(fn);
    QPixmap* t=new QPixmap(p.scaled(15,15));
    setPixmap(*t);
    state.push_back(t);
    atkspd=20;
  }
  line =new QGraphicsRectItem(boundingRect().center().x(),boundingRect().center().y()-600,1,600);
  QBrush blackBrush(Qt::black);
  line->setBrush(blackBrush);
  line->setParentItem(this);
  line->setZValue(-16);
  
}


void Fisher::move(){
 if(++slower%20==0){
   if(zValue()==-15){
     vy=atkspd;
     setPos(x()-vx,y()-vy);
   }
   else{
     if(slower%80==0 ) vy=-vy;
     setPos(x()-vx,y()+vy);
   }
 }
}

void Fisher::animate(){
 if(++fps%20==0){
   if(++count>=state.size()) count=0;
   
   setPixmap(*(state[0]));
 }
}

int* Fisher::getVel(){
  int* vel=new int(2);
  vel[0]=vx;vel[1]=vy;
  return vel;
}
void Fisher::increaseAttackSpeed(){
   atkspd+=15;
}


