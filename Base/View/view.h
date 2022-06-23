#ifndef BASE_CONTROLLER_VIEW_H__
#define BASE_CONTROLLER_VIEW_H__
#include <QMainWindow>
#include <QMenuBar>
#include <QMouseEvent>
#include <QShortcut>
#include <QPoint>
#include <QColor>
#include <QColorDialog>
#include "Base/Helpers/helpers.h"

class View : public QMainWindow {
 Q_OBJECT

 public:
  View();
  void SetMenu(QMenuBar* menu);
  void ConnectUI();
  void SetShortCut(QShortcut* shortcut);
  void SendCircle(Circle circle);
  void SendLine(Line line);
  void SetColorDialog(QColorDialog* dialog);

 signals:
  void ExitRequested();
  void Clicked(QPoint point);
  void CalledDialog();
  void ColorDialogColorSelected(QColor color);

 private:
  void paintEvent(QPaintEvent*) override;
  void mousePressEvent(QMouseEvent* event) override;

  bool is_circle_{false};
  bool is_line_{false};
  Circle circle_{};
  Line line_{};
  QMenuBar* menu_{};
  QShortcut* call_paint_message_{};
  QColorDialog* dialog_;
};

#endif // BASE_CONTROLLER_VIEW_H__
