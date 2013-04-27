#include "cuttle.h"
#include "mainwindow.h"
#include <iostream>
Cuttle::Cuttle(){
  QPixmap* t=new QPixmap("cuttle/c1.bmp");
  setPixmap(*t);
  state.push_back(t);
}
Cuttle::Cuttle(QPointF* pos,MainWindow* w)
{
  for(int i=1;i<6;i++){
    QString fn="cuttle/c";fn.append(QString::number(i));fn.append(".bmp");
    QPixmap* t=new QPixmap(fn);
    setPixmap(*t);
    state.push_back(t);
  }
  setPos(*pos);
  velocity_[0]=velocity_[1]=0;
  bounds_=sceneBoundingRect();
  timer_=w->get_timer();
  connect(timer_,SIGNAL(timeout()),this,SLOT(move()));
}

 QPainterPath Cuttle::shape() const
 {
     QPainterPath path;
     path.addEllipse(QRectF(state[count]->rect()));
     return path;
 }
 
void Cuttle::move(){
  if(++slower%20==0){
  //velocity_[0]=rand()%70;velocity_[1]=rand()%70;
  if(++count>=state.size()) count=0;
  setPixmap(*(state[count]));
  if((x()+velocity_[0]>=bounds_.left())||(x()+velocity_[0]>=bounds_.right())){
    velocity_[0]=0;
  }
  if((y()+velocity_[1]>=bounds_.bottom())||(y()+velocity_[1]>=bounds_.top())){
    velocity_[1]=0;
  }
  
  setPos(x()+velocity_[0],y()+velocity_[1]);
  }
}
