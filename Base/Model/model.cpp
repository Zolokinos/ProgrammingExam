#include "model.h"
Model::Model(View* view) :
    view_(view),
    menu_(new QMenuBar),
    audio_player_(new AudioPlayer) {
  SetAudio();
  SetMenu();
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
}
