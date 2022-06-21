#ifndef BASE_CONTROLLER_VIEW_H__
#define BASE_CONTROLLER_VIEW_H__
#include "QMainWindow"
#include <QMenuBar>

class View : public QMainWindow {
 Q_OBJECT

 public:
  View();
  void SetMenu(QMenuBar* menu);

 signals:
  void ExitRequested();

 private:
  void paintEvent(QPaintEvent*) override;
  void ConnectUI();

 QMenuBar* menu_{};
};

#endif // BASE_CONTROLLER_VIEW_H__
