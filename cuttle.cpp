#include "cuttle.h"
#include "mainwindow.h"
#include <iostream>


/** creates cuttle at position with reference to main window
 * @param pos is location of cuttle
 * @param w is reference to mainwindow
 */
Cuttle::Cuttle(QPointF* pos,MainWindow* w)
{
  for(int i=1;i<11;i++){
    QString fn="cuttle/c";fn.append(QString::number(i));fn.append(".png");
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
  death=0;
  bounded=true;
  health=100;
  invincible=false;
  cooldown=25;
  caught=false;
  hypnotizing=false;
}


 /** animates cuttle*/
void Cuttle::animate(){
 if(++fps%20==0){
  if(hypnotizing){
    if(++count<6||count>9)count=6;
    setPixmap(*(state[count]));
  }
  else{
    if(++count>=6) count=0;
    setPixmap(*(state[count]));
  }
 }
}
 /** moves cuttle*/
void Cuttle::move(){
  if(++slower%20==0){
  if(bounded){ 
    if((x()+velocity_[0]<=bounds_->left())||(x()+velocity_[0]>=bounds_->right())){
      velocity_[0]=0;
    }
  }
  if(!caught){
    if((y()+velocity_[1]>=bounds_->bottom())||(y()+velocity_[1]<=bounds_->top())){
      velocity_[1]=0;
    }
  }
  if(velocity_[0]>0||velocity_[0]<-10) bind();
  setPos(x()+velocity_[0],y()+velocity_[1]);
  if(invincible) cooldown--;
  if(cooldown<=0){
    cooldown=25;
    invincible=false;
  }
  }
}
/** gives cuttle whales rightward velocity*/
void Cuttle::hitByWhale(int* vel){
  if(velocity_[0]>0) velocity_[0]=0;
  velocity_[0]=-vel[0];  

}
/** gives cuttle hooks velocity and sets catch to true*/
void Cuttle::catchHook(int* vel){
  velocity_[0]=vel[0];  
  velocity_[1]=vel[1];
  caught=true;  
}
/** decrements health by @param damage*/
void Cuttle::hurt(int dammage){
  health-=dammage;
  if(health<=0) death+=500000;
}

/** increments health(up to 100) by @param life*/
void Cuttle::heal(int life){
   if(health+life>100) health=100;
   else health+=life;
}
/** returns QString of health*/
QString Cuttle::getHealth(){
    QString h("Health: ");
    h.append(QString::number(health));
    return h;
}

