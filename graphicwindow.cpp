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
