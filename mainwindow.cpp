#include "mainwindow.h"
#include <cmath>
#include <ctime>
#include <QGraphicsRectItem>
#include <qapplication.h>
#include "cuttle.h"


/** MainWindow class is the class that operates as a main method
 * and contains and controls all 
 */    
MainWindow::MainWindow()  {


    scene = new QGraphicsScene();
    view = new QGraphicsView( scene );
    setFocus();
    int sizeMod=3;
    view->setFixedSize( WINDOW_MAX_X*sizeMod, WINDOW_MAX_Y*sizeMod );
    view->setWindowTitle( "Tile Puzzle");
    bounds=new QRectF(scene->sceneRect());
    
    
    cuttlePos=new QPointF(20,20);
    cuttle=new Cuttle(cuttlePos,this);
    scene->addItem(cuttle);
    

    
    timer = new QTimer(this);
    timer->setInterval(5);
    timer->start();
    
    mainVLayout=new QVBoxLayout();
    view->setLayout(mainVLayout);

} 

   /** Passed to main(), displays the GUI*/
void MainWindow::show() {
    view->show();
}
     /** Destructor. Removes scene and view*/
MainWindow::~MainWindow()
{

    delete scene;
    delete view;
}

void MainWindow::keyPressEvent(QKeyEvent* e){
  //QWidget::keyPressEvent(e);
  int v=1;
  switch(e->key()){
  case Qt::Key_W:
    cuttle->setYVel(v);
  case Qt::Key_A:
    cuttle->setXVel(-v);
  case Qt::Key_S:
    cuttle->setYVel(-v);
  case Qt::Key_D:
    cuttle->setXVel(v);
  //case Qt::Key_Space:
  
  }
}

