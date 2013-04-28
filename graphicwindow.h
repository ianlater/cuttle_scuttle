#include <QGraphicsView>

class MainWindow;

class GraphicWindow : public QGraphicsView{
public:
GraphicWindow(QGraphicsScene*,MainWindow* );

private:
  MainWindow* w_;
  void keyPressEvent(QKeyEvent* e);
  void keyReleaseEvent(QKeyEvent* e);
  void mousePressEvent(QMouseEvent* e);
  void mouseReleaseEvent(QMouseEvent* e);
  //void mouseMove(QMouseEvent* e);
};
