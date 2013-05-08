#ifndef SCORES_H
#define SCORES_H

#include <fstream>
#include <queue>
#include <map>
#include <QGraphicsView>
#include <QListWidget>
#include <QGraphicsScene>

/** Class responsible for reading, displaying, and writing high scores*/
class Scores{
public:
/** constructor*/
  Scores(const char*);
/** destructor writes scores*/
  ~Scores(){}
  /** gives score to Score class for processing*/
  void give(QString,int);
  /** writes scores*/
  void write();
  /** displays scores*/
  void display();
private:
/** name of score file*/
const char* fn_;
/** reads file */
void read();
/** map of players and scores scores*/
 std::map<int,QString> results_;
 /** priority queue of scores to keep them ordered*/
 std::priority_queue<int> scores_;
 /** scene for displaying rankings*/
 QGraphicsScene* scene;
 /** view for displaying scene*/
 QGraphicsView* view;
 /** list of rankings*/
 QListWidget* list;
};
#endif
