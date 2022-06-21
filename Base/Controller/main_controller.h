#ifndef BASE_CONTROLLER_MAIN_CONTROLLER_H__
#define BASE_CONTROLLER_MAIN_CONTROLLER_H__

#include <QWidget>
#include "Base/Model/model.h"
#include "Base/View/view.h"

class MainController : public QWidget {
  Q_OBJECT

 public:
  MainController();

 private:
  Model* model_{};
  View* view_;
};

#endif // BASE_CONTROLLER_MAIN_CONTROLLER_H__