#include <QFileDialog>
#include <iostream>
#include "main_controller.h"

MainController::MainController() :
    view_(new View) {
  model_ = new Model(view_);
  ConnectUI();
// QFileDialog dialog(this);
  // dialog.setFileMode(QFileDialog::ExistingFile);
}

void MainController::ConnectUI() {
  connect(view_,
          &View::ExitRequested,
          this,
          &MainController::Exit);
}

void MainController::Exit() {
  exit(0);
}