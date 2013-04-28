#include "mainwindow.h"
#include <cmath>
#include <ctime>
#include <QGraphicsRectItem>
#include <qapplication.h>
#include "cuttle.h"
#include <iostream>
#include "graphicwindow.h"
#include "whale.h"
#include "bfish.h"

/** MainWindow class is the class that operates as a main method
 * and contains and controls all 
 */    
MainWindow::MainWindow()  {


    scene = new QGraphicsScene();
    view = new GraphicWindow( scene,this );

    int sizeMod=1;
    view->setFixedSize( WINDOW_MAX_X*sizeMod, WINDOW_MAX_Y*sizeMod );
    view->setWindowTitle( "Cuttle Scuttle");
    scene->setSceneRect(0,0,WINDOW_MAX_X*sizeMod-10, WINDOW_MAX_Y*sizeMod);
    bounds=new QRectF(scene->sceneRect());
     
    timer = new QTimer(this);
    timer->setInterval(5);
    timer->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer,SIGNAL(timeout()),this,SLOT(animate()));
    connect(timer,SIGNAL(timeout()),this,SLOT(populate()));
    
    cuttlePos=new QPointF(20,WINDOW_MAX_Y/2);
    cuttle=new Cuttle(cuttlePos,this);
    scene->addItem(cuttle);

    mainVLayout=new QVBoxLayout();
    topHLayout=new QHBoxLayout();
    view->setLayout(mainVLayout);
    
    pause=new QPushButton("Pause");
    topHLayout->addWidget(pause);
    pause->resize(40,20);
    mainVLayout->addLayout(topHLayout);
    mainVLayout->addSpacing(WINDOW_MAX_Y*sizeMod);

    level=0;
    defaultBMP=new QPixmap("cuttle/c1.bmp");
    hypnosis=false;
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

  int v=50;
  switch(e->key()){ 
  case Qt::Key_W:   
    cuttle->setYVel(-v);
    break;
  case Qt::Key_A:   
    cuttle->setXVel(-v);
    break;
  case Qt::Key_S: 
    cuttle->setYVel(v);
    break;
  case Qt::Key_D:   
    cuttle->setXVel(v);  
    break;
  }
}
void MainWindow::keyReleaseEvent(QKeyEvent* e){
 switch(e->key()){
  case Qt::Key_W:
    cuttle->setYVel(0);
    break;
  case Qt::Key_A:
    cuttle->setXVel(0);
    break;
  case Qt::Key_S:
    cuttle->setYVel(0);
    break;
  case Qt::Key_D:
    cuttle->setXVel(0);
    break;
 }   
}
void MainWindow::mousePressEvent(QMouseEvent* e){
   if(e->button()==Qt::RightButton){
     hypnosis=true;
   }
   else;
}
void MainWindow::mouseReleaseEvent(QMouseEvent* e){
   if(e->button()==Qt::RightButton){
     hypnosis=false;
   }
}
void MainWindow::move(){
  for(unsigned int i=0;i<things.size();i++){
    if(cuttle->collidesWithItem(things[i])){
      switch(things[i]->isType()){
        case 1:
          cuttle->hitByWhale(things[i]->getVel());
          break;
        case 2:
          if(hypnosis);
          break;
      
      
      }	
    
    }
    things[i]->move();
    if(!scene->sceneRect().contains(things[i]->pos())){
      things[i]->death++;
      if((things[i]->death++)>6000) things.erase(things.begin()+i);    
    }

  }
}

void MainWindow::animate(){
  for(unsigned int i=0;i<things.size();i++){
    things[i]->animate();
  }
}
void MainWindow::populate(){

 if(level%10000==0){

     Whale* whale=new Whale(defaultBMP, WINDOW_MAX_X+250,rand()%WINDOW_MAX_Y);
     scene->addItem(whale);
     things.push_back(whale);
  
 }
 if(level%150==0){
  int mod=5; 
  for(int i=0;i<rand()%mod;i++){
    BFish* bfish=new BFish(defaultBMP, WINDOW_MAX_X+250,rand()%WINDOW_MAX_Y);
    scene->addItem(bfish);
    things.push_back(bfish); 
 }
 }
 level++;
}
 

