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
  bounds_=w->get_bounds();
  timer_=w->get_timer();
  connect(timer_,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer_,SIGNAL(timeout()),this,SLOT(animate()));
    setZValue(50);
}

 QPainterPath Cuttle::shape() const
 {
     QPainterPath path;
     path.addEllipse(QRectF(state[count]->rect()));
     return path;
 }
 
void Cuttle::animate(){
if(++fps%20==0){
  if(++count>=state.size()) count=0;
  setPixmap(*(state[count]));
}
}
 
void Cuttle::move(){
  if(++slower%20==0){
   
  if((x()+velocity_[0]<=bounds_->left())||(x()+velocity_[0]>=bounds_->right())){
    velocity_[0]=0;
  }
  if((y()+velocity_[1]>=bounds_->bottom())||(y()+velocity_[1]<=bounds_->top())){
    velocity_[1]=0;
  }
 // std::cout<<"Position: "<<x()<<","<<y()<<std::endl;
//  std::cout<<"Velocity: "<<velocity_[0]<<","<<velocity_[1]<<std::endl;
  //std::cout<<"Bounds: "<<bounds_->left()<<","<<bounds_->right()<<","<<bounds_->bottom()<<","<<bounds_->top()<<std::endl;
  setPos(x()+velocity_[0],y()+velocity_[1]);
  }
}

void Cuttle::hitByWhale(int* vel){
  if(velocity_[0]>0) velocity_[0]=0;
  velocity_[0]=-vel[0];  
}


