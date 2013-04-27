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

#define WINDOW_MAX_X 250
#define WINDOW_MAX_Y 250
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
private:
    /** The graphics scene*/
    QGraphicsScene *scene;
    /** The graphics view that holds the scene*/
    GraphicWindow* view;
    /*Main QVBoxLayout. Organizes fields and buttons and display*/
    QVBoxLayout *mainVLayout;
    Cuttle* cuttle;
    QPointF* cuttlePos;

    QTimer* timer;
    QRectF* bounds;
public slots:


};

#endif // MAINWINDOW_H