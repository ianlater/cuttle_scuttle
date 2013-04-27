#include "cuttle.h"
#include "mainwindow.h"

Cuttle::Cuttle(){
  Pixmap* t=new Pixmap("cuttle/c1.bmp");
  setPixmap(*t);
  state.push_back(t);
}
Cuttle::Cuttle(QPointF* pos,MainWindow* w):Cuttle()
{
  setPos(*pos);
  bounds_=w->get_bounds();
  timer_=w->get_timer();
  connect(timer_,SIGNAL(timeout()),this,SLOT(move()));
}

 QPainterPath Cuttle::shape() const
 {
     QPainterPath path;
     path.addEllipse(QRectF(rect()));
     return path;
 }
 
void Cuttle::move(){
  if(++count==state.size()) count=0;
  setPixmap(*(state[count]));
  if((x()+velocity_[0]==bounds->left())&&(x()+velocity_[0]==bounds->right())){
    velocity_[0]=0;
  }
  
  if((y()+velocity_[1]==bounds->bottom())&&(y()+velocity_[1]==bounds->top())){
    velocity_[1]=0;
  }
  moveBy(velocity_[0],velocity_[1]);
}
