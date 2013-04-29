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
    QTimer* get_timer(){return timer;}
    QRectF* get_bounds(){return bounds;}    
    void keyPressEvent(QKeyEvent* e);
    void keyReleaseEvent(QKeyEvent* e);
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
private:
    /** The graphics scene*/
    QGraphicsScene *scene;
    /** The graphics view that holds the scene*/
    GraphicWindow* view;
    /*Main QVBoxLayout. Organizes fields and buttons and display*/
    QVBoxLayout *mainVLayout;
    QHBoxLayout* topHLayout;
    Cuttle* cuttle;
    QPointF* cuttlePos;
    QTimer* timer;
    QRectF* bounds;
    std::vector<Thing*> things;
    int level;
    QPixmap* defaultBMP;
    bool hypnosis;
    bool firing;
    QPoint* target;
    QPushButton* start;    
    QPushButton* pause;
    QPushButton* exit;
    bool started;
    QLabel* health;
    QLabel* gameOver;
    QLabel* score;
    int points;
    void lose();
    QString getScore();
    int multiplier;
    int mod;
public slots:
  void animate();
  void move();
  void populate();
  void pausePressed();
  void startPressed();

};

#endif // MAINWINDOW_H
