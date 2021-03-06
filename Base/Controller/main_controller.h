#ifndef BASE_CONTROLLER_MAIN_CONTROLLER_H__
#define BASE_CONTROLLER_MAIN_CONTROLLER_H__

#include <QWidget>
#include <QScreen>
#include "Base/Model/model.h"
#include "Base/View/view.h"
#include "Base/View/settings.h"

class MainController : public QWidget {
  Q_OBJECT

 public:
  MainController();

 private:
  void ConnectUI();
  static void Exit();
  void DrawCircle(QPoint point);
  void SetColor(int num);
  void CallColorDialog();
  void CallFileDialog();
  void ChangeRadius(int rad);
  void ChangePenThickness(const QString& pen_thickness);
  void ChangeColorPen(QColor color);
  void DrawLine();
  void FindCrossing();

  Model* model_{};
  View* view_;
  Settings* settings_;
};

#endif // BASE_CONTROLLER_MAIN_CONTROLLER_H__
