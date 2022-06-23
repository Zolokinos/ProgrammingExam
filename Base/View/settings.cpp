#include <QHBoxLayout>
#include <QValidator>
#include <QFileDialog>
#include <QPixmap>
#include <QPalette>
#include <iostream>

#include "settings.h"
#include "Base/Helpers/styles.h"

Settings::Settings() :
    layout_(new QHBoxLayout()),
    central_(new QWidget(this)) {
  SetUpWidget();
  move(900, 160);
}

void Settings::SetUpWidget() {
  show();
  setWindowTitle(tr("Settings"));
}

void Settings::SetRadioButtons(QButtonGroup* buttons) {
  buttons_ = buttons;
  QVBoxLayout* box_layout = new QVBoxLayout();
  for (int i = 0; i < 3; ++i) {
    box_layout->addWidget(buttons_->buttons()[i]);
  }
  layout_->addLayout(box_layout);
}

void Settings::ConnectUI() {
  assert(buttons_->buttons()[0] != nullptr);

  connect(buttons_,
          &QButtonGroup::idClicked,
          this,
          &Settings::RadioButtonClicked);

  connect(spin_box_,
          &QSpinBox::valueChanged,
          this,
          &Settings::RadiusChanged);

  connect(combo_box_,
          &QComboBox::textActivated,
          this,
          &Settings::PenThicknessChanged);

  connect(call_file_message_,
          &QShortcut::activated,
          this,
          &Settings::CalledDialog);
}

void Settings::SetLayout() {
  setCentralWidget(central_);
  central_->setLayout(layout_);
}

void Settings::SetLineEdits(QLineEdit* from_x_point,
                            QLineEdit* from_y_point,
                            QLineEdit* to_x_point,
                            QLineEdit* to_y_point) {
  from_x_point_ = from_x_point;
  from_y_point_ = from_y_point;
  to_x_point_ = to_x_point;
  to_y_point_ = to_y_point;

  QVBoxLayout* box_layout_from = new QVBoxLayout();
  QVBoxLayout* box_layout_to = new QVBoxLayout();
  box_layout_from->addWidget(from_x_point_);
  box_layout_from->addWidget(from_y_point_);
  box_layout_to->addWidget(to_x_point_);
  box_layout_to->addWidget(to_y_point_);

  layout_->addLayout(box_layout_from);
  layout_->addLayout(box_layout_to);

  SetFocusTransition();
}

void Settings::SetSpinBox(QSpinBox* spin_box) {
  spin_box_ = spin_box;
  layout_->addWidget(spin_box_);
}

void Settings::SetComboBox(QComboBox* combo_box) {
  combo_box_ = combo_box;
  layout_->addWidget(combo_box_);
}

void Settings::SetInteraction(QLabel* is_intersection) {
  is_intersection_ = is_intersection;
  is_intersection_->setVisible(true);
  is_intersection_->setText("Waiting");
  is_intersection_->setParent(this);
  assert(is_intersection_);
  layout_->addWidget(is_intersection_);
}

void Settings::SetFocusTransition() {
  connect(from_x_point_,
          &QLineEdit::editingFinished,
          this, [&] {
    emit PointEditingFinished();
    from_y_point_->setFocus();
  });
  connect(from_y_point_,
          &QLineEdit::editingFinished,
          this, [&] {
    emit PointEditingFinished();
    to_x_point_->setFocus();
  });
  connect(to_x_point_,
          &QLineEdit::editingFinished,
          this, [&] {
    emit PointEditingFinished();
    to_y_point_->setFocus();
  });
  connect(to_y_point_,
          &QLineEdit::editingFinished,
          this,
          &Settings::PointEditingFinished);
}

void Settings::SetStyleSheet() {
  // RadioButtons
  setStyleSheet(kMainWindowSettings);
  for (int i = 0; i < 3; ++i) {
    buttons_->button(i)->setStyleSheet(kRadioButton);
  }
  // LineEdits
  from_x_point_->setValidator(
      new QIntValidator(0, INT32_MAX));
  from_y_point_->setValidator(
      new QIntValidator(0, INT32_MAX));
  to_x_point_->setValidator(
      new QIntValidator(0, INT32_MAX));
  to_y_point_->setValidator(
      new QIntValidator(0, INT32_MAX));
  from_x_point_->setPlaceholderText("x point: from");
  from_y_point_->setPlaceholderText("y point: from");
  to_x_point_->setPlaceholderText("x point: to");
  to_y_point_->setPlaceholderText("y point: to");
  from_x_point_->setStyleSheet(kLineEditBlack);
  from_y_point_->setStyleSheet(kLineEditBlack);
  to_x_point_->setStyleSheet(kLineEditBlack);
  to_y_point_->setStyleSheet(kLineEditBlack);
  // SpinBox
  spin_box_->setStyleSheet(kSpinBoxBlack);
  // ComboBox
  combo_box_->setStyleSheet(kComboBoxBlack);
  // Label
  is_intersection_->setStyleSheet(kIsIntersectionLabelBlack);
  // MessageBox
  error_message_->setStyleSheet(kMessage);
}

void Settings::SetRedStyle() {
  // LineEdits
  from_x_point_->setStyleSheet(kLineEditRed);
  from_y_point_->setStyleSheet(kLineEditRed);
  to_x_point_->setStyleSheet(kLineEditRed);
  to_y_point_->setStyleSheet(kLineEditRed);
  // SpinBox
  spin_box_->setStyleSheet(kSpinBoxRed);
  // ComboBox
  combo_box_->setStyleSheet(kComboBoxRed);
  // Label
  is_intersection_->setStyleSheet(kIsIntersectionLabelRed);
}

void Settings::SetBlueStyle() {
  // LineEdits
  from_x_point_->setStyleSheet(kLineEditBlue);
  from_y_point_->setStyleSheet(kLineEditBlue);
  to_x_point_->setStyleSheet(kLineEditBlue);
  to_y_point_->setStyleSheet(kLineEditBlue);
  // SpinBox
  spin_box_->setStyleSheet(kSpinBoxBlue);
  // ComboBox
  combo_box_->setStyleSheet(kComboBoxBlue);
  // Label
  is_intersection_->setStyleSheet(kIsIntersectionLabelBlue);
}

void Settings::SetBlackStyle() {
  // LineEdits
  from_x_point_->setStyleSheet(kLineEditBlack);
  from_y_point_->setStyleSheet(kLineEditBlack);
  to_x_point_->setStyleSheet(kLineEditBlack);
  to_y_point_->setStyleSheet(kLineEditBlack);
  // SpinBox
  spin_box_->setStyleSheet(kSpinBoxBlack);
  // ComboBox
  combo_box_->setStyleSheet(kComboBoxBlack);
  // Label
  is_intersection_->setStyleSheet(kIsIntersectionLabelBlack);
}

void Settings::SetFileDialog(QFileDialog* file_dialog) {
  file_dialog_ = file_dialog;
}

void Settings::SetShortCut(QShortcut* call_file_message) {
  call_file_message_ = call_file_message;
}

void Settings::SetErrorFileDialog(QMessageBox* error_message) {
  error_message_ = error_message;
}

void Settings::SendFileDialogError() {
  error_message_->show();
  error_message_->setFocus();
}

void Settings::SetCustomBackground(QString filename) {
  QPixmap background(filename);
  background = background.scaled(size(), Qt::IgnoreAspectRatio);
  QPalette palette;
  palette.setBrush(QPalette::Window, background);
  setPalette(palette);
}
