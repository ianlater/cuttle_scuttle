#include <QGraphicsView>

class MainWindow;

class GraphicWindow : public QGraphicsView{
public:
GraphicWindow(QGraphicsScene*,MainWindow* );

private:
  MainWindow* w_;
  void keyPressEvent(QKeyEvent* e);
  void keyReleaseEvent(QKeyEvent* e);
};
