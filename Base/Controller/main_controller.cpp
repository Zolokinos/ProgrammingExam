#include <QFileDialog>
#include <iostream>
#include "main_controller.h"

MainController::MainController() :
    view_(new View) {
  model_ = new Model(view_);
// QFileDialog dialog(this);
  // dialog.setFileMode(QFileDialog::ExistingFile);
}
