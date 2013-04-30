#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <vector>
#include <QListWidget>
#include <QLineEdit>
#include <QKeyEvent>
#include <QPointF>
#include <QRectF>
#include <QTimer>
#include "thing.h"
#include "cuttle.h"
#include <QMainWindow>

class GraphicWindow;

#define WINDOW_MAX_X 1000
#define WINDOW_MAX_Y 600
/** MainWindow class is the class that operates as a main method
 * and contains and controls everything.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    /** Constructor functions similarly to a main function. Initializes
    * the GUI interface*/
    explicit MainWindow();
    /** Destructor. Removes scene and view*/
    ~MainWindow();
    /** Passed to main(), displays the GUI*/
    void show();
    /** returns timer*/
    QTimer* get_timer(){return timer;}
    /** returns game boundaries*/
    QRectF* get_bounds(){return bounds;}
    /** handles a key being pressed*/    
    void keyPressEvent(QKeyEvent* e);
    /** handles a key being released*/
    void keyReleaseEvent(QKeyEvent* e);
    /** handles mouse buttons being pressed*/
    void mousePressEvent(QMouseEvent* e);
    /** handles mouse buttons being released*/
    void mouseReleaseEvent(QMouseEvent* e);
private:
    /** The graphics scene*/
    QGraphicsScene *scene;
    /** The graphics view that holds the scene*/
    GraphicWindow* view;
    /*Main QVBoxLayout. Organizes fields and buttons and display*/
    QVBoxLayout *mainVLayout;
    /** topmost QHBoxLayout*/
    QHBoxLayout* topHLayout;
    /** main player : the cuttlefish*/
    Cuttle* cuttle;
    /** QPointF* for tracking and setting cuttle pos*/
    QPointF* cuttlePos;
    /** timer for animation and movemet*/
    QTimer* timer;
    /** boundaries of game*/
    QRectF* bounds;
    /** vector of all Thing items in game*/
    std::vector<Thing*> things;
    /** counter to determine levels*/
    int level;
    /** default pixmap given to each thing */
    QPixmap* defaultBMP;
    /** weather the cuttlefish is hypnotizing*/
    bool hypnosis;
    /** whether or not the player is firing(useful for later animations)*/
    bool firing;
    /** target for firing */
    QPoint* target;
    /** button to start game*/
    QPushButton* start; 
    /** button to pause game*/   
    QPushButton* pause;
    /** button to stop playing*/
    QPushButton* exit;
    /** whether or not game has started*/
    bool started;
    /** health displaying label*/
    QLabel* health;
    /** label that shows "GAME  OVER"*/
    QLabel* gameOver;
    /** score displaying label*/
    QLabel* score;
    /** player's points*/
    int points;
   /** score multiplier*/
    int multiplier;
    /** modifies level difficulty*/
    int mod;
      /** takes and displays player name*/
     QFormLayout* player;
     /** diisplays "Name"*/
     QLabel* name;
     /** where player enters name*/
     QLineEdit* nameField;
    /** returns score in QString format for qlabel score*/
    QString getScore();
     /** stops game and spams game over*/    
    void lose();
public slots:
  /** animates all the Things*/
  void animate();
  /** moves all the Things and helps handle collisions*/
  void move();
  /** Populates the game with Thing items, and updates level*/
  void populate();
  /** pauses or resumes game*/
  void pausePressed();
  /** starts game*/
  void startPressed();

};

#endif // MAINWINDOW_H
