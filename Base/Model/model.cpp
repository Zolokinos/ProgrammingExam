#include <QColor>
#include <iostream>

#include "model.h"
Model::Model(View* view, Settings* settings) :
    view_(view),
    settings_(settings),
    menu_(new QMenuBar),
    audio_player_(new AudioPlayer),
    spin_box_(new QSpinBox(this)),
    color(QColor(Qt::black)),
    buttons_(new QButtonGroup) {
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

}

void Model::SetView() {
  call_paint_message_ = new QShortcut(Qt::Key_Space, view_);
  view_->SetShortCut(call_paint_message_);
}

void Model::SetSettings() {
  buttons_->addButton(new QRadioButton("Fill red"), 0);
  buttons_->addButton(new QRadioButton("Fill blue"), 1);
  buttons_->addButton(new QRadioButton("Fill black"), 2);
  assert(!buttons_->buttons().empty());
  settings_->SetRadioButtons(buttons_);
  settings_->SetLayout();
}

void Model::SetFillColor(int num) {
  std::cout << num;
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



