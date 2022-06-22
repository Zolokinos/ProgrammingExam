#include <QColor>
#include <iostream>

#include "model.h"
Model::Model(View* view, Settings* settings) :
    view_(view),
    settings_(settings),
    menu_(new QMenuBar),
    audio_player_(new AudioPlayer),
    buttons_(new QButtonGroup),
    from_x_point_(new QLineEdit),
    from_y_point_(new QLineEdit),
    to_x_point_(new QLineEdit),
    to_y_point_(new QLineEdit),
    spin_box_(new QSpinBox),
    combo_box_(new QComboBox),
    is_intersection_(new QLabel("")) {
  SetAudio();
  SetMenu();
  SetView();
  SetSettings();
  SetUI();
}

void Model::SetMenu() {
  menu_->setParent(view_);
  view_->SetMenu(menu_);
}

void Model::SetAudio() {
  audio_player_->CreateAudioOutput();
  audio_player_->ChooseStream(QUrl("qrc:00199.mp3"));
  audio_player_->TurnOn();
}

void Model::SetUI() {
  view_->ConnectUI();
  settings_->ConnectUI();
}

void Model::SetCenterCircle(QPoint point) {
  central_circle_ = point;
  Circle circle(
      fill_color_,
      color_pen_,
      radius_,
      thickness_,
      central_circle_);
  view_->SendCircle(circle);
}

void Model::SetView() {
  call_paint_message_ = new QShortcut(Qt::Key_Space, view_);
  view_->SetShortCut(call_paint_message_);
}

void Model::SetSettings() {
  settings_->SetLayout();

  SetRadioButtons();
  SetLineEdits();
  SetSpinBox();
  SetComboBox();
  assert(is_intersection_);
  settings_->SetInteraction(is_intersection_);
}

void Model::SetFillColor(int num) {
  switch (num) {
    case 0: {
      fill_color_ = QColor(Qt::red);
      break;
    }
    case 1: {
      fill_color_ = QColor(Qt::blue);
      break;
    }
    case 2: {
      fill_color_ = QColor(Qt::black);
      break;
    }
    default: {
      exit(1);
    }
  }
}

void Model::SetRadioButtons() {
  buttons_->addButton(new QRadioButton("Fill red"), 0);
  buttons_->addButton(new QRadioButton("Fill blue"), 1);
  buttons_->addButton(new QRadioButton("Fill black"), 2);
  assert(!buttons_->buttons().empty());
  buttons_->button(2)->click();
  settings_->SetRadioButtons(buttons_);
}

void Model::SetLineEdits() {
  settings_->SetLineEdits(from_x_point_,
                          from_y_point_,
                          to_x_point_,
                          to_y_point_);
}

void Model::SetSpinBox() {
  spin_box_->setMaximum(INT32_MAX);
  settings_->SetSpinBox(spin_box_);
}

void Model::SetComboBox() {
  for (int i = 1; i < 17; ++i) {
    combo_box_->addItems({QString::number(i)});
  }
  combo_box_->setCurrentIndex(0);
  settings_->SetComboBox(combo_box_);
}

void Model::CreateDialog() {
  QColorDialog* dialog = new QColorDialog;
  dialog->open();
  color_pen_ = dialog->currentColor();
}

void Model::ChangeRadius(int rad) {
  radius_ = rad;
}

void Model::ChangePenThickness(int thickness) {
  thickness_ = thickness;
}
