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
          &MainController::DrawCircle);
  connect(settings_,
          &Settings::RadioButtonClicked,
          this,
          &MainController::SetColor);
  connect(view_,
          &View::CalledDialog,
          this,
          &MainController::CallColorDialog);
  connect(settings_,
          &Settings::CalledDialog,
          this,
          &MainController::CallFileDialog);
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
  connect(settings_,
          &Settings::PointEditingFinished,
          this,
          &MainController::DrawLine);
  connect(settings_,
          &Settings::PointEditingFinished,
          this,
          &MainController::FindCrossing);
  connect(view_,
          &View::Clicked,
          this,
          &MainController::FindCrossing);
}

void MainController::Exit() {
  exit(0);
}

void MainController::DrawCircle(QPoint point) {
  model_->DrawCircle(point);
}

void MainController::SetColor(int num) {
  model_->SetFillColor(num);
}

void MainController::CallColorDialog() {
  model_->CreateColorDialog();
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

void MainController::DrawLine() {
  if (!model_->IsSomeEmpty()) {
    model_->DrawLine();
    std::cout << "Line" << std::endl;
  }
  std::cout << "Thick" << std::endl;
}

void MainController::FindCrossing() {
  if (model_->EverythingExists()) {
    model_->FindCrossing();
  }
}

void MainController::CallFileDialog() {
  std::cout << "Success" << std::endl;
  model_->CreateFileDialog();
}
