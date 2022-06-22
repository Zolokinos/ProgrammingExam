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
}

void Settings::ConnectUI() {
  assert(buttons_->buttons()[0] != nullptr);
    connect(buttons_,
            &QButtonGroup::idClicked,
            this,
            &Settings::RadioButtonClicked);
  }

void Settings::SetLayout() {
  setCentralWidget(central_);
  central_->setLayout(layout_);
  QHBoxLayout* box_layout = new QHBoxLayout();
  for (int i = 0; i < 3; ++i) {
    box_layout->addWidget(buttons_->buttons()[i]);
  }
  layout_->addLayout(box_layout);
}
