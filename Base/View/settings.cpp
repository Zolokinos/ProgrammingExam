#include <QHBoxLayout>
#include <iostream>

#include "settings.h"
Settings::Settings() :
    layout_(new QHBoxLayout()),
    central_(new QWidget(this)) {
  SetUpWidget();
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
          &QComboBox::activated,
          this,
          &Settings::PenThicknessChanged);
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
  box_layout_from->addWidget(to_point_);

  layout_->addLayout(box_layout);
}

void Settings::SetSpinBox(QSpinBox* spin_box) {
  spin_box_ = spin_box;
  layout_->addWidget(spin_box_);
}

void Settings::SetComboBox(QComboBox* combo_box) {
  combo_box_ = combo_box;
  layout_->addWidget(combo_box_);
}
