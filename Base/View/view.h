#ifndef BASE_CONTROLLER_VIEW_H__
#define BASE_CONTROLLER_VIEW_H__
#include <QMainWindow>
#include <QMenuBar>
#include <QMouseEvent>
#include <QShortcut>
#include <QPoint>
#include <QColor>

class View : public QMainWindow {
 Q_OBJECT

 public:
  View();
  void SetMenu(QMenuBar* menu);
  void ConnectUI();
  void SetShortCut(QShortcut* shortcut);
  void DrawCircle(QPoint point, QColor color, QColor color_pen_, int rad);

 signals:
  void ExitRequested();
  void Clicked(QPoint point);
  void CallDialog();

 private:
  void paintEvent(QPaintEvent*) override;
  void mousePressEvent(QMouseEvent* event) override;

  QMenuBar* menu_{};
  QShortcut* call_paint_message_{};
};

#endif // BASE_CONTROLLER_VIEW_H__
