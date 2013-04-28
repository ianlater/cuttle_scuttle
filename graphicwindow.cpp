#include "graphicwindow.h"
#include "mainwindow.h"

GraphicWindow::GraphicWindow(QGraphicsScene* scene, MainWindow* w){
  setScene(scene);
  w_=w;
}

void GraphicWindow::keyPressEvent(QKeyEvent* e){
   w_->keyPressEvent(e);
}
void GraphicWindow::keyReleaseEvent(QKeyEvent* e){
  w_->keyReleaseEvent(e);
}
void GraphicWindow::mousePressEvent(QMouseEvent* e){
   w_->mousePressEvent(e);
}
void GraphicWindow::mouseReleaseEvent(QMouseEvent* e){
   w_->mouseReleaseEvent(e);
}


