#include <QFileDialog>
#include <iostream>
#include "main_controller.h"

MainController::MainController() :
    view_(new View),
    settings_(new Settings) {
  model_ = new Model(view_, settings_);
  ConnectUI();
  // QFileDialog dialog(this);
  // dialog.setFileMode(QFileDialog::ExistingFile);
}

void MainController::ConnectUI() {
  connect(view_,
          &View::ExitRequested,
          this,
          &MainController::Exit);
  connect(view_,
          &View::Clicked,
          this,
          &MainController::SetCenter);
  connect(settings_,
          &Settings::RadioButtonClicked,
          this,
          &MainController::SetColor);
  connect(view_,
          &View::CallDialog,
          this,
          &MainController::CallColorDialog);
  connect(settings_,
          &Settings::RadiusChanged,
          this,
          &MainController::ChangeRadius);
  connect(settings_,
          &Settings::PenThicknessChanged,
          this,
          &MainController::ChangePenThickness);
  connect(view_,
          &View::ColorDialogColorSelected,
          this,
          &MainController::ChangeColorPen);
}

void MainController::Exit() {
  exit(0);
}

void MainController::SetCenter(QPoint point) {
  model_->SetCenterCircle(point);
}

void MainController::SetColor(int num) {
  model_->SetFillColor(num);
}

void MainController::CallColorDialog() {
  model_->CreateDialog();
}

void MainController::ChangeRadius(int rad) {
  model_->ChangeRadius(rad);
}

void MainController::ChangePenThickness(const QString& pen_thickness) {
  int thickness = pen_thickness.toInt();
  model_->ChangePenThickness(thickness);
}

void MainController::ChangeColorPen(QColor color) {
  model_->SetPenColor(color);
}
