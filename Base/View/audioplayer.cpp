#include "audioplayer.h"
AudioPlayer::AudioPlayer() = default;

void AudioPlayer::TurnOn() {
  play();
}

void AudioPlayer::CreateAudioOutput() {
  auto* audioOutput = new QAudioOutput(this);
  audioOutput->setVolume(25);
  setAudioOutput(audioOutput);
  setLoops(QMediaPlayer::Infinite);
}

void AudioPlayer::TurnOff() {
  stop();
}

void AudioPlayer::ChooseStream(const QUrl& url) {
  setSource(url);
}

