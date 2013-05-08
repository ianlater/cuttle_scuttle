#include "scores.h"
#include <iostream>

/** constructor checks if file exists of existing scores exists otherwise writes file
 * @param fn is the file name of scores
 */
Scores::Scores(const char* fn){
  fn_=fn;
  scene = new QGraphicsScene();
  view = new QGraphicsView( scene ); 
  read();
}
  /** gives score to Score class for processing
  * @param name is the name of the player
  * @param score is the players score
  */
void Scores::give(QString name,int score){
  scores_.push(score);
  name.append(" ");
  name.append(QString::number(score));
  results_[score]=name;
}
/** reads in scores from file specified in constructor paramaters*/
void Scores::read(){
  std::ifstream reader;
  reader.open(fn_);
  reader.peek();
  while(reader.good()){
     char fname[50];int score;
     reader>>fname>>score;
     QString name(fname);
     name.append(" ");
     name.append(QString::number(score));
     results_[score]=name;
     scores_.push(score);    
  }
  reader.close();    
}

  /** writes scores*/
void Scores::write(){
  std::priority_queue<int> storage;
  std::ofstream writer(fn_);
  while(!scores_.empty()){
    storage.push(scores_.top());
    writer<<(results_[scores_.top()]).toAscii().constData()<<"\n";
    scores_.pop();
  }
  while(!storage.empty()){
    scores_.push(storage.top());
    storage.pop();
  }
}
  /** displays scores*/
void Scores::display(){
  list=new QListWidget();
  scene->addWidget(list);
  std::priority_queue<int> storage;
  while(!scores_.empty()){
    storage.push(scores_.top());
    list->addItem(results_[scores_.top()]);
    scores_.pop();
  }
  while(!storage.empty()){
    scores_.push(storage.top());
    storage.pop();
  }
  view->show();
  write();
}

