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
#include "dolphin.h"
#include "crab.h"
#include "fisher.h"

/** MainWindow class is the class that operates as a main method
 * and contains and controls all 
 */    
MainWindow::MainWindow()  {


    scene = new QGraphicsScene();
    view = new GraphicWindow( scene,this );

    int sizeMod=1;
    view->setFixedSize( WINDOW_MAX_X*sizeMod+20, WINDOW_MAX_Y*sizeMod+20 );
    view->setWindowTitle( "Cuttle Scuttle");
    scene->setSceneRect(0,0,WINDOW_MAX_X*sizeMod-10, WINDOW_MAX_Y*sizeMod);
    bounds=new QRectF(scene->sceneRect());
    
    timer = new QTimer(this);
    timer->setInterval(5);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer,SIGNAL(timeout()),this,SLOT(animate()));
    connect(timer,SIGNAL(timeout()),this,SLOT(populate()));
    
    cuttlePos=new QPointF(20,WINDOW_MAX_Y/2);
    cuttle=new Cuttle(cuttlePos,this);
    scene->addItem(cuttle);

    mainVLayout=new QVBoxLayout();
    topHLayout=new QHBoxLayout();
    view->setLayout(mainVLayout);
    
    start=new QPushButton("Start");
    connect(start,SIGNAL(clicked()),this,SLOT(startPressed()));
    pause=new QPushButton("Pause");
    connect(pause,SIGNAL(clicked()),this,SLOT(pausePressed()));
    exit=new QPushButton("Quit");
    connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));
    topHLayout->addWidget(start);
    topHLayout->addWidget(pause);
    topHLayout->addWidget(exit);
    health=new QLabel("Health: ");
    topHLayout->addWidget(health);
    score=new QLabel("SCORE: ");
    topHLayout->addWidget(score);
    player=new QFormLayout();
    name=new QLabel("Name");
    nameField=new QLineEdit();
    player->addRow(name,nameField);
    topHLayout->addLayout(player);
    
         
    pause->resize(40,20);
    mainVLayout->addLayout(topHLayout);
    mainVLayout->addSpacing(WINDOW_MAX_Y*sizeMod);

    level=points=0;
    multiplier=mod=1;
    defaultBMP=new QPixmap("cuttle/c1.bmp");
    firing=hypnosis=false;
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
    /** handles a key being pressed
         * @param e is instance of the key event
         */    
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
    /** handles a key being releaseds
     * @param e is instance of the key event
     */    
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
/** handles pressing of mouse buttons and their corrosponding actions
 *  in terms of the game mechanics
 * @param e is instance of the mouse event
 */
void MainWindow::mousePressEvent(QMouseEvent* e){
   if(e->button()==Qt::RightButton){
     hypnosis=true;
   }
   else{
     firing=true;
     target=new QPoint(e->globalPos());
     cuttle->setTarget(target);
     QList<QGraphicsItem*> childrens=cuttle->childItems();
     if(!childrens.empty()){
       QGraphicsItem* t=childrens.front();
       childrens.pop_front();
       t->setZValue(-1);
     }  
     
   }
}
/** handles mouse buttons being released
     * @param e is instance of the mouse event
     */
void MainWindow::mouseReleaseEvent(QMouseEvent* e){
   if(e->button()==Qt::RightButton){
     hypnosis=false;
   }else{
     firing=false;
   }
}
  /** moves all the Things and helps handle collisions and deaths*/
void MainWindow::move(){
  for(unsigned int i=0;i<things.size();i++){
    if(things[i]->collidesWithItem(cuttle)){
      switch(things[i]->isType()){
        case 1:
          cuttle->unbind();
          cuttle->hitByWhale(things[i]->getVel());
          break;
        case 2:    
          if(hypnosis) things[i]->hypnotize(cuttle);
          break;
        case 3:
          if(!cuttle->isInvincible()){
            cuttle->hurt(25);
            points-=500;
            cuttle->becomesInvincible();
          }
          break;
        case 4:
         cuttle->heal(50);
         things[i]->setZValue(3);
         break;
        case 5:
         things[i]->setZValue(-15);
         cuttle->catchHook(things[i]->getVel());
         break;
         
      }	    
    }
    things[i]->move();
    health->setText(cuttle->getHealth());
    multiplier=cuttle->childItems().size();
    if(multiplier==0) multiplier=1;
    score->setText(getScore());
    if((cuttle->death)>1000) lose();  
    
    if(!scene->sceneRect().contains(things[i]->pos()))
      if((things[i]->death++)>4000){
       if(things[i]->zValue()==-12) points+=500;  
       if(things[i]->zValue()==3) points+=200;  
       scene->removeItem(things[i]);
       things.erase(things.begin()+i);

      }     
    }
    if(!scene->sceneRect().contains(cuttle->pos())) cuttle->death++;
    else{ cuttle->death=0;}
  
}
  /** animates all the Things*/
void MainWindow::animate(){
  for(unsigned int i=0;i<things.size();i++){
    things[i]->animate();
  }
}
  /** Populates the game with Thing items, and updates level*/
void MainWindow::populate(){
 if(mod<2){
 if(level%(5000/mod)==0){

     Whale* whale=new Whale(defaultBMP, WINDOW_MAX_X+250,rand()%(WINDOW_MAX_Y-50)+20);
     scene->addItem(whale);
     things.push_back(whale);
  
 }
 }
 if(level%(1000/mod)==0){
   Dolphin* dolphin=new Dolphin(defaultBMP, WINDOW_MAX_X+250,rand()%WINDOW_MAX_Y);
   scene->addItem(dolphin);
   dolphin->giveTarget(cuttle);
   things.push_back(dolphin);
   for(int i=0;i<mod;i++){
     dolphin->increaseAttackSpeed();
   }
 }
 
 if(level%(200/mod)==0){

  points+=10*multiplier;
  
  for(int i=0;i<rand()%(5/mod);i++){
    BFish* bfish=new BFish(defaultBMP, WINDOW_MAX_X+250,rand()%WINDOW_MAX_Y);
    scene->addItem(bfish);
    things.push_back(bfish); 
  }
 }

 if(level%(1500/mod)==0){
    Crab* crab=new Crab(defaultBMP, WINDOW_MAX_X+250,WINDOW_MAX_Y-25);
    scene->addItem(crab);
    things.push_back(crab);
 }
 if(level%(3500/mod)==0){
   Fisher* fisher=new Fisher(defaultBMP, WINDOW_MAX_X+250,rand()%115+20*mod);
   scene->addItem(fisher);
   things.push_back(fisher);
   for(int i=0;i<mod;i++){
     fisher->increaseAttackSpeed();
   }
 }
 level++;
 if(level%10000==0) mod++;
}
  /** pauses or resumes game*/
void MainWindow::pausePressed(){
   if(started){
     if(timer->isActive()) timer->stop();
      else timer->start();
   }
}
  /** starts game*/
void MainWindow::startPressed(){
   started=true;
   health->setText(cuttle->getHealth());
   timer->start();
}
/** stops game and spams game over*/
void MainWindow::lose(){
  timer->stop();
  gameOver=new QLabel("GAME  OVER");  gameOver->setScaledContents(true);
  mainVLayout->addWidget(gameOver);
}
    /** returns score in QString format for qlabel score*/
QString MainWindow::getScore(){
    QString s("SCORE: ");
    s.append(QString::number(points));
    return s;
}

